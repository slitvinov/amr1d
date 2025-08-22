import math


def fmt_e12_5(x):
    return f"{x: .5E}".rjust(12)


def line_5e(vals):
    return "".join(["  " + fmt_e12_5(v) for v in vals])


def line_5e_i6(vals, iv):
    return "".join(["  " + fmt_e12_5(v) for v in vals]) + f"  {iv:6d}"


def fname_from_i(i):
    return f"{i:07d}.dat"

def init(state, fh):
    s = state
    pi = 3.141592654

    s["gamma"] = 1.4
    s["gammal"] = s["gamma"] - 1.0
    s["cour"] = 0.5
    s["ntime"] = 3000
    s["di"] = 0.5
    s["ctore"] = 0.25
    s["ctode"] = 0.1
    s["epsil"] = 0.005
    s["nbuff"] = 3
    s["ntref"] = 2
    s["nrmax"] = 3
    s["npoin"] = 128
    s["nelem"] = 127

    npoin = s["npoin"]
    nelem = s["nelem"]
    melem = s["melem"]
    mpoin = s["mpoin"]
    period = s["period"]

    intmat = s["intmat"]
    mrhist = s["mrhist"]
    irefe = s["irefe"]
    idere = s["idere"]
    ipact = s["ipact"]

    for ie in range(1, npoin):
        intmat[ie][1] = ie
        intmat[ie][2] = ie + 1

    if period != 0.0:
        intmat[nelem][1] = nelem
        intmat[nelem][2] = 1
    else:
        s["ibdry_l"] = 1
        s["ibdry_r"] = npoin

    for ie in range(1, melem + 1):
        for ir in range(1, 6):
            mrhist[ie][ir] = 0
        irefe[ie] = 0
        idere[ie] = 0
    for ie in range(1, nelem + 1):
        mrhist[ie][5] = 1
    for ip in range(1, npoin + 1):
        ipact[ip] = 1
    for ip in range(npoin + 1, mpoin + 1):
        ipact[ip] = 0

    rho = s["rho"]
    p = s["p"]
    v = s["v"]
    rhov = s["rhov"]
    rhoE = s["rhoE"]
    xp = s["xp"]

    half = npoin // 2
    for ip in range(1, half + 1):
        rho[ip] = 8.0
        p[ip] = 10.0
    for ip in range(half, npoin + 1):
        rho[ip] = 1.0
        p[ip] = 1.0
    for ip in range(1, npoin + 1):
        xp[ip] = float(ip - 1) * 6.4 / float(npoin)
        v[ip] = 0.0
        rhov[ip] = rho[ip] * v[ip]
        rhoE[ip] = p[ip] / s["gammal"] + 0.5 * rho[ip] * v[ip] * v[ip]

    it = 0
    fh.write("initial conditions\n")
    fh.write(" it npoin nelem\n")
    fh.write(f" {it} {npoin},{nelem}\n"
             )  # Fortran had a comma after npoin in your paste; keep similar
    fh.write(" xp rho v  rhoE p \n")
    for i in range(1, npoin + 1):
        fh.write(line_5e([xp[i], rho[i], v[i], rhoE[i], p[i]]) + "\n")


def geom(state):
    s = state
    mpoin = s["mpoin"]
    melem = s["melem"]
    npoin = s["npoin"]
    nelem = s["nelem"]
    intmat = s["intmat"]
    xp = s["xp"]
    ce = s["ce"]
    rmatm = s["rmatm"]
    rlen = s["rlen"]
    period = s["period"]
    mrhist = s["mrhist"]
    ipact = s["ipact"]

    for ip in range(1, npoin + 1):
        rmatm[ip] = 0.0
    for ie in range(1, nelem + 1):
        rlen[ie] = 0.0
    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            rlen[ie] = xp[intmat[ie][2]] - xp[intmat[ie][1]]
    if period != 0.0:
        for ie in range(1, nelem + 1):
            if abs(rlen[ie]) > period / 2.0:
                rlen[ie] = period + rlen[ie]
    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            ce[ie][2] = 1.0 / rlen[ie]
            ce[ie][1] = -ce[ie][2]
    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            for inn in (1, 2):
                rmatm[intmat[ie][inn]] += rlen[ie]
    for ip in range(1, npoin + 1):
        if ipact[ip] == 1:
            rmatm[ip] = 2.0 / rmatm[ip]


def grerror(state, vref):
    s = state
    nelem = s["nelem"]
    npoin = s["npoin"]
    melem = s["melem"]
    mpoin = s["mpoin"]
    intmat = s["intmat"]
    mrhist = s["mrhist"]
    ipact = s["ipact"]
    irefe = s["irefe"]
    idere = s["idere"]
    ce = s["ce"]
    rlen = s["rlen"]
    epsil = s["epsil"]
    ctore = s["ctore"]
    ctode = s["ctode"]
    nbuff = s["nbuff"]
    ibdry_l = s.get("ibdry_l", 1)
    ibdry_r = s.get("ibdry_r", npoin)

    tempea = s["tempea"]
    tempec = s["tempec"]
    errore = s["errore"]
    temppa = s["temppa"]
    temppb = s["temppb"]
    temppc = s["temppc"]
    errorp = s["errorp"]
    iptemp = s["iptemp"]
    ietemp = s["ietemp"]

    for ie in range(1, melem + 1):
        tempea[ie] = 0.0
        tempec[ie] = 0.0
        errore[ie] = 0.0
        irefe[ie] = 0
        idere[ie] = 0
    for ip in range(1, mpoin + 1):
        temppa[ip] = 0.0
        temppb[ip] = 0.0
        temppc[ip] = 0.0
        errorp[ip] = 0.0

    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            acc_a = 0.0
            acc_c = 0.0
            for inn in (1, 2):
                acc_a += ce[ie][inn] * vref[intmat[ie][inn]]
                acc_c += abs(ce[ie][inn]) * abs(vref[intmat[ie][inn]])
            tempea[ie] = acc_a
            tempec[ie] = acc_c

    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            for inn in (1, 2):
                node = intmat[ie][inn]
                temppa[node] += rlen[ie] * ce[ie][inn] * tempea[ie]
                temppb[node] += rlen[ie] * abs(ce[ie][inn]) * abs(tempea[ie])
                temppc[node] += rlen[ie] * abs(ce[ie][inn]) * tempec[ie]

    temppa[ibdry_l] = 0.0
    temppa[ibdry_r] = 0.0

    for ip in range(1, npoin + 1):
        if ipact[ip] == 1:
            denom = temppb[ip] + s["epsil"] * temppc[ip]
            errorp[ip] = abs(temppa[ip]) / denom if denom != 0.0 else 0.0

    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            errore[ie] = max(errorp[intmat[ie][1]], errorp[intmat[ie][2]])

    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            if errore[ie] > ctore:
                irefe[ie] = 1
            if errore[ie] < ctode:
                idere[ie] = 1

    for _ in range(1, nbuff + 1):
        for ip in range(1, npoin + 1):
            iptemp[ip] = 0
        for ie in range(1, nelem + 1):
            if mrhist[ie][5] == 1:
                if irefe[ie] == 1:
                    iptemp[intmat[ie][1]] = 1
                    iptemp[intmat[ie][2]] = 1
        for ie in range(1, nelem + 1):
            if mrhist[ie][5] == 1:
                if iptemp[intmat[ie][1]] == 1 or iptemp[intmat[ie][2]] == 1:
                    irefe[ie] = 1

    for _ in range(1, 6):
        for ie in range(1, nelem + 1):
            ietemp[ie] = 0
            if mrhist[ie][5] == 1:
                ietemp[ie] = mrhist[ie][4] + irefe[ie]
        for ip in range(1, npoin + 1):
            iptemp[ip] = 0
        for ie in range(1, nelem + 1):
            if mrhist[ie][5] == 1:
                for inn in (1, 2):
                    node = intmat[ie][inn]
                    if ietemp[ie] > iptemp[node]:
                        iptemp[node] = ietemp[ie]
        for ie in range(1, nelem + 1):
            if mrhist[ie][5] == 1:
                for inn in (1, 2):
                    node = intmat[ie][inn]
                    if iptemp[node] - mrhist[ie][4] > 1:
                        irefe[ie] = 1
                    if iptemp[node] - mrhist[ie][4] >= 1:
                        idere[ie] = 0
                ietemp[ie] = mrhist[ie][4] + irefe[ie]
                for inn in (1, 2):
                    node = intmat[ie][inn]
                    if ietemp[ie] > iptemp[node]:
                        iptemp[node] = ietemp[ie]


def unref(state):
    s = state
    intmat = s["intmat"]
    mrhist = s["mrhist"]
    idere = s["idere"]
    ipact = s["ipact"]
    nelem = s["nelem"]

    for ie in range(1, nelem + 1):
        if idere[ie] == 1 and mrhist[ie][4] != 0:
            iparent = mrhist[ie][1]
            ichild1 = mrhist[iparent][2]
            ichild2 = mrhist[iparent][3]
            if idere[ichild1] == 1 and idere[ichild2] == 1:
                for inn in (1, 2):
                    ipl = intmat[ichild1][inn]
                    ip2 = intmat[ichild2][inn]
                    if ipl != intmat[iparent][1] and ipl != intmat[iparent][2]:
                        ipact[ipl] = 0
                    if ip2 != intmat[iparent][1] and ip2 != intmat[iparent][2]:
                        ipact[ip2] = 0
                mrhist[ichild1][5] = 0
                mrhist[ichild2][5] = 0
                mrhist[iparent][5] = 1
                idere[ichild1] = 0
                idere[ichild2] = 0


def refine(state):
    s = state
    intmat = s["intmat"]
    xp = s["xp"]
    rho = s["rho"]
    rhov = s["rhov"]
    rhoE = s["rhoE"]
    mrhist = s["mrhist"]
    irefe = s["irefe"]
    ipact = s["ipact"]

    nrmaxl = s["nrmax"] - 1
    ie = 1
    # Important: iterate over original nelem snapshot; new ones append at end
    while ie <= s["nelem"]:
        if irefe[ie] == 1 and mrhist[ie][4] <= nrmaxl:
            s["npoin"] += 1
            npoin = s["npoin"]
            ipact[npoin] = 1
            if npoin > s["mpoin"]:
                raise RuntimeError(f"Please increase mpoin. Needed: {npoin}")
            nelem2 = s["nelem"] + 2
            if nelem2 > s["melem"]:
                raise RuntimeError(f"Please increase melem. Needed: {nelem2}")

            # midpoint and averages
            mid = 0.5 * (xp[intmat[ie][1]] + xp[intmat[ie][2]])
            xp[npoin] = mid
            rho[npoin] = 0.5 * (rho[intmat[ie][1]] + rho[intmat[ie][2]])
            rhov[npoin] = 0.5 * (rhov[intmat[ie][1]] + rhov[intmat[ie][2]])
            rhoE[npoin] = 0.5 * (rhoE[intmat[ie][1]] + rhoE[intmat[ie][2]])

            # split element
            intmat[s["nelem"] + 1][1] = intmat[ie][1]
            intmat[s["nelem"] + 1][2] = npoin
            intmat[s["nelem"] + 2][1] = npoin
            intmat[s["nelem"] + 2][2] = intmat[ie][2]

            mrhist[ie][5] = 0
            mrhist[s["nelem"] + 1][5] = 1
            mrhist[s["nelem"] + 2][5] = 1

            mrhist[ie][2] = s["nelem"] + 1
            mrhist[ie][3] = s["nelem"] + 2
            mrhist[s["nelem"] + 1][1] = ie
            mrhist[s["nelem"] + 2][1] = ie
            mrhist[s["nelem"] + 1][4] = mrhist[ie][4] + 1
            mrhist[s["nelem"] + 2][4] = mrhist[ie][4] + 1

            s["nelem"] += 2
        ie += 1


def fluxld(state):
    s = state
    npoin = s["npoin"]
    nelem = s["nelem"]
    intmat = s["intmat"]
    rho = s["rho"]
    rhov = s["rhov"]
    rhoE = s["rhoE"]
    p = s["p"]
    v = s["v"]
    flux = s["flux"]
    rlen = s["rlen"]
    vmax = s["vmax"]
    mrhist = s["mrhist"]
    ipact = s["ipact"]

    cbig = 1.0e30
    gammal = s["gammal"]
    gamma = s["gamma"]

    for ip in range(1, npoin + 1):
        if ipact[ip] == 1:
            v[ip] = rhov[ip] / rho[ip]
            p[ip] = gammal * (rhoE[ip] - 0.5 * rhov[ip] * v[ip])
            flux[ip][1] = rhov[ip]
            flux[ip][2] = rhov[ip] * v[ip] + p[ip]
            flux[ip][3] = rhoE[ip] * v[ip] + p[ip] * v[ip]

    for ip in range(1, npoin + 1):
        if ipact[ip] == 1:
            vmax[ip] = math.sqrt(gamma * p[ip] / rho[ip]) + abs(v[ip])

    dt = cbig
    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            for inn in (1, 2):
                node = intmat[ie][inn]
                dt = min(dt, rlen[ie] / vmax[node])

    dt = s["cour"] * dt
    s["dt"] = dt


def deltau(state):
    s = state
    npoin = s["npoin"]
    nelem = s["nelem"]
    intmat = s["intmat"]
    du = s["du"]
    dup = s["dup"]
    flux = s["flux"]
    dt = s["dt"]
    ce = s["ce"]
    rlen = s["rlen"]
    cour = s["cour"]
    di = s["di"]
    rho = s["rho"]
    rhov = s["rhov"]
    rhoE = s["rhoE"]
    diff = s["diff"]
    vmax = s["vmax"]
    mrhist = s["mrhist"]

    cbig = 1.0e20
    csmall = -1.0e20

    for im in (1, 2, 3):
        for ie in range(1, nelem + 1):
            du[ie][im] = 0.0
            diff[ie][im] = 0.0

    rlmin = cbig
    rlmax = csmall
    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1 and rlen[ie] < rlmin:
            rlmin = rlen[ie]
        if mrhist[ie][5] == 1 and rlen[ie] > rlmax:
            rlmax = rlen[ie]

    for im in (1, 2, 3):
        for ip in range(1, npoin + 1):
            dup[ip][im] = 0.0

    for ie in range(1, nelem + 1):
        if mrhist[ie][5] == 1:
            for im in (1, 2, 3):
                du_ie = 0.0
                for inn in (1, 2):
                    du_ie += ce[ie][inn] * flux[intmat[ie][inn]][im]
                du[ie][im] = du_ie

            vv = max(vmax[intmat[ie][1]], vmax[intmat[ie][2]])
            diff[ie][1] = ce[ie][1] * rho[
                intmat[ie][1]] * vv + ce[ie][2] * rho[intmat[ie][2]] * vv
            diff[ie][2] = ce[ie][1] * rhov[
                intmat[ie][1]] * vv + ce[ie][2] * rhov[intmat[ie][2]] * vv
            diff[ie][3] = ce[ie][1] * rhoE[
                intmat[ie][1]] * vv + ce[ie][2] * rhoE[intmat[ie][2]] * vv

            dfact = 0.5 * di
            for im in (1, 2, 3):
                diff[ie][im] = dfact * diff[ie][im] * rlen[ie] * rlmin

            for im in (1, 2, 3):
                for inn in (1, 2):
                    node = intmat[ie][inn]
                    dup[node][im] += 0.5 * rlen[ie] * du[ie][im] + ce[ie][
                        inn] * diff[ie][im]


# ----------------------------
# Main driver (translated)
# ----------------------------
def main(mpoin=40000, melem=80000, period=0.0):
    # Allocate 1-based arrays
    def i2d_int(n1, n2):
        return [[0] * (n2 + 1) for _ in range(n1 + 1)]

    def i1d_int(n):
        return [0] * (n + 1)

    def r2d(n1, n2):
        return [[0.0] * (n2 + 1) for _ in range(n1 + 1)]

    def r1d(n):
        return [0.0] * (n + 1)

    # State container
    s = dict(
        mpoin=mpoin,
        melem=melem,
        period=period,
        intmat=i2d_int(melem, 2),
        ce=r2d(melem, 2),
        rmatm=r1d(mpoin),
        rlen=r1d(melem),
        xp=r1d(mpoin),  # <-- add this line
        rho=r1d(mpoin),
        rhov=r1d(mpoin),
        rhoE=r1d(mpoin),
        p=r1d(mpoin),
        v=r1d(mpoin),
        flux=r2d(mpoin, 3),
        diff=r2d(melem, 3),
        vmax=r1d(mpoin),
        du=r2d(melem, 3),
        dup=r2d(mpoin, 3),
        mrhist=i2d_int(melem, 5),
        irefe=i1d_int(melem),
        idere=i1d_int(melem),
        ipact=i1d_int(mpoin),
        iptemp=i1d_int(mpoin),
        ietemp=i1d_int(melem),
        l=i1d_int(mpoin),
        tempea=r1d(melem),
        tempec=r1d(melem),
        errore=r1d(melem),
        temppa=r1d(mpoin),
        temppb=r1d(mpoin),
        temppc=r1d(mpoin),
        errorp=r1d(mpoin),
    )

    # i = 0 → 0000000.dat
    i = 0
    fname = fname_from_i(i)
    with open(fname, "w") as fh:
        init(s, fh)

    # geometry (pre-sweep refine / unref loops)
    geom(s)

    for _ in range(1, 6):
        grerror(s, s["rho"])
        unref(s)
        refine(s)
        geom(s)

    # time loop
    for i in range(1, s["ntime"] + 1):
        if i % s["ntref"] == 0:
            grerror(s, s["rho"])
            unref(s)
            refine(s)
            geom(s)

        fluxld(s)
        deltau(s)

        # boundary condition (non-periodic → momentum at ends = 0)
        if s["period"] == 0.0:
            s["dup"][s["ibdry_l"]][2] = 0.0
            s["dup"][s["ibdry_r"]][2] = 0.0

        # conservative update
        for ip in range(1, s["npoin"] + 1):
            if s["ipact"][ip] == 1:
                s["rho"][ip] = s["rho"][
                    ip] - s["dup"][ip][1] * s["rmatm"][ip] * s["dt"]
                s["rhov"][ip] = s["rhov"][
                    ip] - s["dup"][ip][2] * s["rmatm"][ip] * s["dt"]
                s["rhoE"][ip] = s["rhoE"][
                    ip] - s["dup"][ip][3] * s["rmatm"][ip] * s["dt"]
                s["p"][ip] = s["gammal"] * (s["rhoE"][ip] -
                                            0.5 * s["rhov"][ip] * s["v"][ip])

        if i % 10 == 0:
            # close current file, open new file named with current it
            fname = fname_from_i(i)
            with open(fname, "w") as fh:
                fh.write(f" it,dt = {i},{s['dt']}\n")
                fh.write(" it npoin(active) nelem(active)\n")
                npac = sum(1 for ip in range(1, s["mpoin"] + 1)
                           if s["ipact"][ip] == 1)
                neac = 0
                for ie in range(1, s["melem"] + 1):
                    if s["mrhist"][ie][5] == 1:
                        neac += 1
                        s["l"][s["intmat"][ie][1]] = s["mrhist"][ie][4]
                fh.write(f" {i} {npac} {neac}, {s['npoin']} {s['nelem']}\n")
                fh.write(" xp rho v  rhoE p l \n")
                for ip in range(1, s["npoin"] + 1):
                    if s["ipact"][ip] == 1:
                        fh.write(
                            line_5e_i6(
                                [
                                    s["xp"][ip], s["rho"][ip], s["v"][ip],
                                    s["rhoE"][ip], s["p"][ip]
                                ],
                                s["l"][ip],
                            ) + "\n")

    # final file (the Fortran closes at end)
    # nothing else to do here


if __name__ == "__main__":
    main()
