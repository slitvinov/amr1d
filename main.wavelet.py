import math


class g:
    pass


def i2d(n1, n2):
    return [[0] * (n2 + 1) for _ in range(n1 + 1)]


def i1d(n):
    return [0] * (n + 1)


def r2d(n1, n2):
    return [[0.0] * (n2 + 1) for _ in range(n1 + 1)]


def r1d(n):
    return [0.0] * (n + 1)

def elemLen(ie):
    return abs(g.xp[g.intmat[ie][2]] - g.xp[g.intmat[ie][1]])

def elemValue(ie, field):
    n1, n2 = g.intmat[ie][1], g.intmat[ie][2]
    return 0.5 * (field[n1] + field[n2])

def geom():
    for ip in range(1, g.npoin + 1):
        g.rmatm[ip] = 0.0
    for ie in range(1, g.nelem + 1):
        g.rlen[ie] = 0.0
    for ie in range(1, g.nelem + 1):
        if g.mrhist[ie][5] == 1:
            g.rlen[ie] = g.xp[g.intmat[ie][2]] - g.xp[g.intmat[ie][1]]
    for ie in range(1, g.nelem + 1):
        if g.mrhist[ie][5] == 1:
            g.ce[ie][2] = 1.0 / g.rlen[ie]
            g.ce[ie][1] = -g.ce[ie][2]
    for ie in range(1, g.nelem + 1):
        if g.mrhist[ie][5] == 1:
            for inn in (1, 2):
                g.rmatm[g.intmat[ie][inn]] += g.rlen[ie]
    for ip in range(1, g.npoin + 1):
        if g.ipact[ip] == 1:
            g.rmatm[ip] = 2.0 / g.rmatm[ip]


def grerror(field):
    eps =  0.05
    hyst = 0.50
    vmax = 0.0
    for ip in range(1, g.npoin + 1):
        if g.ipact[ip] == 1:
            a = abs(field[ip])
            if a > vmax:
                vmax = a
    tolRef = eps * (vmax if vmax > 0.0 else 1.0)
    tolDeref = hyst * tolRef
    
    # clear marks
    for ie in range(1, g.melem + 1):
        g.irefe[ie] = 0
        g.idere[ie] = 0

    # collect leaf values/levels
    ue = [0.0] * (g.melem + 1)
    level = [0] * (g.melem + 1)
    isLeaf = [0] * (g.melem + 1)
    Lmax = 0
    for ie in range(1, g.nelem + 1):
        level[ie] = g.mrhist[ie][4]
        if g.mrhist[ie][5] == 1:
            isLeaf[ie] = 1
            ue[ie] = elemValue(ie, field)
            if level[ie] > Lmax:
                Lmax = level[ie]

    # bottom-up parent averages (length-weighted from children)
    avg = [0.0] * (g.melem + 1)
    for ie in range(1, g.nelem + 1):
        if isLeaf[ie]:
            avg[ie] = ue[ie]

    for L in range(Lmax - 1, -1, -1):
        for p in range(1, g.nelem + 1):
            if g.mrhist[p][4] == L:
                c1, c2 = g.mrhist[p][2], g.mrhist[p][3]
                if c1 and c2:
                    l1, l2 = elemLen(c1), elemLen(c2)
                    s = l1 + l2
                    avg[p] = (avg[c1] * l1 + avg[c2] * l2) / s if s > 0.0 else 0.5 * (avg[c1] + avg[c2])

    # details on true sibling leaf pairs (same real parent)
    for p in range(1, g.nelem + 1):
        c1, c2 = g.mrhist[p][2], g.mrhist[p][3]
        if c1 and c2 and isLeaf[c1] and isLeaf[c2]:
            d1 = ue[c1] - avg[p]
            d2 = ue[c2] - avg[p]
            eta = max(abs(d1), abs(d2))
            if eta > tolRef and level[c1] < g.nrmax:
                g.irefe[c1] = 1
                g.irefe[c2] = 1
            if eta < tolDeref and level[c1] > 0:
                g.idere[c1] = 1
                g.idere[c2] = 1

    for ie in range(1, g.nelem):
        ie2 = ie + 1
        if isLeaf[ie] and isLeaf[ie2] and level[ie] == level[ie2]:
            sameParent = (g.mrhist[ie][1] != 0 and g.mrhist[ie][1] == g.mrhist[ie2][1])
            if not sameParent and g.intmat[ie][2] == g.intmat[ie2][1]:
                l1, l2 = elemLen(ie), elemLen(ie2)
                s = l1 + l2
                pav = (ue[ie] * l1 + ue[ie2] * l2) / s if s > 0.0 else 0.5 * (ue[ie] + ue[ie2])
                eta = max(abs(ue[ie] - pav), abs(ue[ie2] - pav))
                if eta > tolRef and level[ie] < g.nrmax:
                    g.irefe[ie] = 1
                    g.irefe[ie2] = 1

    # buffer growth around refine
    for _ in range(1, g.nbuff + 1):
        for ip in range(1, g.npoin + 1):
            g.iptemp[ip] = 0
        for ie in range(1, g.nelem + 1):
            if g.mrhist[ie][5] == 1 and g.irefe[ie] == 1:
                g.iptemp[g.intmat[ie][1]] = 1
                g.iptemp[g.intmat[ie][2]] = 1
        for ie in range(1, g.nelem + 1):
            if g.mrhist[ie][5] == 1:
                if g.iptemp[g.intmat[ie][1]] == 1 or g.iptemp[g.intmat[ie]
                                                              [2]] == 1:
                    g.irefe[ie] = 1

    # 2:1 balance propagation
    for _ in range(1, 6):
        for ie in range(1, g.nelem + 1):
            g.ietemp[ie] = 0
            if g.mrhist[ie][5] == 1:
                g.ietemp[ie] = g.mrhist[ie][4] + g.irefe[ie]
        for ip in range(1, g.npoin + 1):
            g.iptemp[ip] = 0
        for ie in range(1, g.nelem + 1):
            if g.mrhist[ie][5] == 1:
                for inn in (1, 2):
                    node = g.intmat[ie][inn]
                    if g.ietemp[ie] > g.iptemp[node]:
                        g.iptemp[node] = g.ietemp[ie]
        for ie in range(1, g.nelem + 1):
            if g.mrhist[ie][5] == 1:
                for inn in (1, 2):
                    node = g.intmat[ie][inn]
                    if g.iptemp[node] - g.mrhist[ie][4] > 1:
                        g.irefe[ie] = 1
                    if g.iptemp[node] - g.mrhist[ie][4] >= 1:
                        g.idere[ie] = 0
                g.ietemp[ie] = g.mrhist[ie][4] + g.irefe[ie]
                for inn in (1, 2):
                    node = g.intmat[ie][inn]
                    if g.ietemp[ie] > g.iptemp[node]:
                        g.iptemp[node] = g.ietemp[ie]


def unref():
    for ie in range(1, g.nelem + 1):
        if g.idere[ie] == 1 and g.mrhist[ie][4] != 0:
            iparent = g.mrhist[ie][1]
            ichild1 = g.mrhist[iparent][2]
            ichild2 = g.mrhist[iparent][3]
            if g.idere[ichild1] == 1 and g.idere[ichild2] == 1:
                for inn in (1, 2):
                    ipl = g.intmat[ichild1][inn]
                    ip2 = g.intmat[ichild2][inn]
                    if ipl != g.intmat[iparent][1] and ipl != g.intmat[
                            iparent][2]:
                        g.ipact[ipl] = 0
                    if ip2 != g.intmat[iparent][1] and ip2 != g.intmat[
                            iparent][2]:
                        g.ipact[ip2] = 0
                g.mrhist[ichild1][5] = 0
                g.mrhist[ichild2][5] = 0
                g.mrhist[iparent][5] = 1
                g.idere[ichild1] = 0
                g.idere[ichild2] = 0


def refine():
    nrmaxl = g.nrmax - 1
    ie = 1
    while ie <= g.nelem:
        if g.irefe[ie] == 1 and g.mrhist[ie][4] <= nrmaxl:
            g.npoin += 1
            g.ipact[g.npoin] = 1
            if g.npoin > g.mpoin:
                raise RuntimeError(f"Please increase mpoin. Needed: {g.npoin}")
            nelem2 = g.nelem + 2
            if nelem2 > g.melem:
                raise RuntimeError(f"Please increase melem. Needed: {nelem2}")
            # midpoint + averages
            mid = 0.5 * (g.xp[g.intmat[ie][1]] + g.xp[g.intmat[ie][2]])
            g.xp[g.npoin] = mid
            g.rho[g.npoin] = 0.5 * (g.rho[g.intmat[ie][1]] +
                                    g.rho[g.intmat[ie][2]])
            g.rhov[g.npoin] = 0.5 * (g.rhov[g.intmat[ie][1]] +
                                     g.rhov[g.intmat[ie][2]])
            g.rhoE[g.npoin] = 0.5 * (g.rhoE[g.intmat[ie][1]] +
                                     g.rhoE[g.intmat[ie][2]])

            # split element
            g.intmat[g.nelem + 1][1] = g.intmat[ie][1]
            g.intmat[g.nelem + 1][2] = g.npoin
            g.intmat[g.nelem + 2][1] = g.npoin
            g.intmat[g.nelem + 2][2] = g.intmat[ie][2]

            g.mrhist[ie][5] = 0
            g.mrhist[g.nelem + 1][5] = 1
            g.mrhist[g.nelem + 2][5] = 1

            g.mrhist[ie][2] = g.nelem + 1
            g.mrhist[ie][3] = g.nelem + 2
            g.mrhist[g.nelem + 1][1] = ie
            g.mrhist[g.nelem + 2][1] = ie
            g.mrhist[g.nelem + 1][4] = g.mrhist[ie][4] + 1
            g.mrhist[g.nelem + 2][4] = g.mrhist[ie][4] + 1

            g.nelem += 2
        ie += 1


g.mpoin = 40000 * 2
g.melem = 80000 * 2

# arrays (1-based)
g.intmat = i2d(g.melem, 2)
g.ce = r2d(g.melem, 2)
g.rmatm = r1d(g.mpoin)
g.rlen = r1d(g.melem)
g.xp = r1d(g.mpoin)

g.rho = r1d(g.mpoin)
g.rhov = r1d(g.mpoin)
g.rhoE = r1d(g.mpoin)
g.p = r1d(g.mpoin)
g.v = r1d(g.mpoin)
g.flux = r2d(g.mpoin, 3)

g.diff = r2d(g.melem, 3)
g.vmax = r1d(g.mpoin)
g.du = r2d(g.melem, 3)
g.dup = r2d(g.mpoin, 3)

g.mrhist = i2d(g.melem, 5)  # parent, child1, child2, level, active (1 = yes)
g.irefe = i1d(g.melem)  # refine
g.idere = i1d(g.melem)  # de-refine
g.ipact = i1d(g.mpoin)  # active

g.iptemp = i1d(g.mpoin)
g.ietemp = i1d(g.melem)
g.l = i1d(g.mpoin)

g.tempea = r1d(g.melem)
g.tempec = r1d(g.melem)
g.errore = r1d(g.melem)
g.temppa = r1d(g.mpoin)
g.temppb = r1d(g.mpoin)
g.temppc = r1d(g.mpoin)
g.errorp = r1d(g.mpoin)

g.gamma = 1.4
g.gammal = g.gamma - 1.0
g.cour = 0.5
g.ntime = 500
g.di = 0.5
g.ctore = 0.25
g.ctode = 0.1
g.epsil = 0.005
g.nbuff = 3
g.ntref = 2
g.nrmax = 5
g.npoin = 128
g.nelem = 127

# connectivity
for ie in range(1, g.npoin):
    g.intmat[ie][1] = ie
    g.intmat[ie][2] = ie + 1

for ie in range(1, g.nelem + 1):
    g.mrhist[ie][5] = 1
for ip in range(1, g.npoin + 1):
    g.ipact[ip] = 1

# initial conditions
half = g.npoin // 2
for ip in range(1, half + 1):
    g.rho[ip] = 8.0
    g.p[ip] = 10.0
for ip in range(half, g.npoin + 1):
    g.rho[ip] = 1.0
    g.p[ip] = 1.0
for ip in range(1, g.npoin + 1):
    g.xp[ip] = (ip - 1) * 6.4 / g.npoin
    g.v[ip] = 0.0
    g.rhov[ip] = g.rho[ip] * g.v[ip]
    g.rhoE[ip] = g.p[ip] / g.gammal + 0.5 * g.rho[ip] * g.v[ip] * g.v[ip]

geom()
for _ in range(1, 6):
    grerror(g.rho)
    unref()
    refine()
    geom()

for it in range(1, g.ntime + 1):
    if it % g.ntref == 0:
        grerror(g.rho)
        unref()
        refine()
        geom()

    cbig = 1.0e30
    for ip in range(1, g.npoin + 1):
        if g.ipact[ip] == 1:
            g.v[ip] = g.rhov[ip] / g.rho[ip]
            g.p[ip] = g.gammal * (g.rhoE[ip] - 0.5 * g.rhov[ip] * g.v[ip])
            g.flux[ip][1] = g.rhov[ip]
            g.flux[ip][2] = g.rhov[ip] * g.v[ip] + g.p[ip]
            g.flux[ip][3] = g.rhoE[ip] * g.v[ip] + g.p[ip] * g.v[ip]

    for ip in range(1, g.npoin + 1):
        if g.ipact[ip] == 1:
            g.vmax[ip] = math.sqrt(g.gamma * g.p[ip] / g.rho[ip]) + abs(
                g.v[ip])

    dt = cbig
    for ie in range(1, g.nelem + 1):
        if g.mrhist[ie][5] == 1:
            for inn in (1, 2):
                node = g.intmat[ie][inn]
                dt = min(dt, g.rlen[ie] / g.vmax[node])
    g.dt = g.cour * dt
    cbig = 1.0e20
    csmall = -1.0e20

    for im in (1, 2, 3):
        for ie in range(1, g.nelem + 1):
            g.du[ie][im] = 0.0
            g.diff[ie][im] = 0.0

    rlmin = cbig
    rlmax = csmall
    for ie in range(1, g.nelem + 1):
        if g.mrhist[ie][5] == 1 and g.rlen[ie] < rlmin:
            rlmin = g.rlen[ie]
        if g.mrhist[ie][5] == 1 and g.rlen[ie] > rlmax:
            rlmax = g.rlen[ie]

    for im in (1, 2, 3):
        for ip in range(1, g.npoin + 1):
            g.dup[ip][im] = 0.0

    for ie in range(1, g.nelem + 1):
        if g.mrhist[ie][5] == 1:
            for im in (1, 2, 3):
                du_ie = 0.0
                for inn in (1, 2):
                    du_ie += g.ce[ie][inn] * g.flux[g.intmat[ie][inn]][im]
                g.du[ie][im] = du_ie

            vv = max(g.vmax[g.intmat[ie][1]], g.vmax[g.intmat[ie][2]])
            g.diff[ie][1] = g.ce[ie][1] * g.rho[g.intmat[ie][1]] * vv + g.ce[
                ie][2] * g.rho[g.intmat[ie][2]] * vv
            g.diff[ie][2] = g.ce[ie][1] * g.rhov[g.intmat[ie][1]] * vv + g.ce[
                ie][2] * g.rhov[g.intmat[ie][2]] * vv
            g.diff[ie][3] = g.ce[ie][1] * g.rhoE[g.intmat[ie][1]] * vv + g.ce[
                ie][2] * g.rhoE[g.intmat[ie][2]] * vv

            dfact = 0.5 * g.di
            for im in (1, 2, 3):
                g.diff[ie][im] = dfact * g.diff[ie][im] * g.rlen[ie] * rlmin

            for im in (1, 2, 3):
                for inn in (1, 2):
                    node = g.intmat[ie][inn]
                    g.dup[node][im] += 0.5 * g.rlen[ie] * g.du[ie][im] + g.ce[
                        ie][inn] * g.diff[ie][im]

    g.dup[1][2] = 0.0
    g.dup[g.npoin][2] = 0.0

    for ip in range(1, g.npoin + 1):
        if g.ipact[ip] == 1:
            g.rho[ip] -= g.dup[ip][1] * g.rmatm[ip] * g.dt
            g.rhov[ip] -= g.dup[ip][2] * g.rmatm[ip] * g.dt
            g.rhoE[ip] -= g.dup[ip][3] * g.rmatm[ip] * g.dt
            g.p[ip] = g.gammal * (g.rhoE[ip] - 0.5 * g.rhov[ip] * g.v[ip])

    if it % 10 == 0:
        fname = f"{it:07d}.dat"
        with open(fname, "w") as fh:
            npac = sum(1 for ip in range(1, g.mpoin + 1) if g.ipact[ip] == 1)
            neac = 0
            for ie in range(1, g.melem + 1):
                if g.mrhist[ie][5] == 1:
                    neac += 1
                    g.l[g.intmat[ie][1]] = g.mrhist[ie][4]
            for ip in range(1, g.npoin + 1):
                if g.ipact[ip] == 1:
                    fh.write(
                        f"{g.xp[ip]:.16e} {g.rho[ip]:.16e} {g.v[ip]:.16e} {g.rhoE[ip]:.16e} {g.p[ip]:.16e} {g.l[ip]}\n"
                    )
