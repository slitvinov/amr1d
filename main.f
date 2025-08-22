      program AMRID
      parameter(mpoin=40000,melem=80000,period=0.0)
      integer intmat(melem,2)
      real xp(mpoin),ce(melem,2),rmatm(mpoin),rlen(melem)
      real rho(mpoin),rhov(mpoin),rhoE(mpoin)
      real p(mpoin),v(mpoin),flux(mpoin,3)
      real diff(melem,3)
      real vmax(mpoin)
      real du(melem,3), dup(mpoin,3)
      integer mrhist(melem,5),irefe(melem),idere(melem)
      integer ipact(mpoin)
      integer iptemp(mpoin),ietemp(melem)
      integer l(mpoin)
      real tempea(melem),tempec(melem),errore(melem)
      real temppa(mpoin),temppb(mpoin),temppc(mpoin),errorp(mpoin)

      call init(gamma,cour,ntime,di,ctore,ctode,epsil,nrmax,
     &     nbuff,ntref,npoin,nelem,mpoin,melem,period,
     &     intmat, mrhist, irefe, idere, ipact,
     &     xp, rho, p, v, rhov, rhoE,
     &     ibdry_l, ibdry_r )

      gammal=gamma-1.

      call geom(mpoin, melem, npoin, nelem, intmat, xp, ce, rmatm,
     &     rlen, period, mrhist, ipact )

      do iloop=1,5
         call grerror(nelem, npoin, melem, mpoin, rho,
     &        tempea, tempec, temppa, temppb, temppc,
     &        epsil, ctore, ctode, nbuff,errorp,
     &        errore, mrhist, ipact,
     &        irefe, idere, ce, rlen, intmat,
     &        ietemp,iptemp,ibdry_l,ibdry_r )
         call unref(melem, mpoin, nelem, npoin, intmat,
     &        mrhist, idere,ipact )
         call refine(melem, mpoin, nelem, npoin, intmat, nrmax,
     &        mrhist, xp, rho, rhov, rhoE, irefe, ipact)
         call geom(mpoin, melem, npoin, nelem, intmat, xp, ce, rmatm,
     &        rlen, period, mrhist, ipact )
      end do

      do i=1,ntime
         if (mod(i,ntref) .eq. 0 ) then
            call grerror(nelem, npoin, melem, mpoin, rho,
     &           tempea, tempec, temppa, temppb, temppc,
     &           epsil, ctore, ctode, nbuff, errorp,
     &           errore, mrhist, ipact,
     &           irefe, idere, ce, rlen, intmat,
     &           ietemp, iptemp, ibdry_l, ibdry_r)
            call unref(melem, mpoin, nelem, npoin, intmat,
     &           mrhist, idere,ipact )
            call refine(melem, mpoin, nelem, npoin, intmat, nrmax,
     &           mrhist, xp, rho, rhov, rhoE, irefe, ipact)
            call geom(mpoin, melem, npoin, nelem, intmat, xp, ce, rmatm,
     &           rlen, period, mrhist, ipact )
         end if

         call fluxld(mpoin, melem, npoin, nelem, gamma,cour,
     &        intmat, rho, rhov, rhoE, p, v,
     &        rlen, vmax, flux, dt, mrhist, ipact )
         call deltau(mpoin, melem, npoin, nelem,intmat,du,dup,flux,dt,
     &        ce,rlen, cour,di,rho,rhov,rhoE,diff,vmax, mrhist )

         if (period .eq. 0. ) then
            dup(ibdry_l,2)=0.
            dup(ibdry_r,2)=0.
         end if

         do ip=1,npoin
            if (ipact(ip) .eq. 1 ) then
               rho(ip) = rho(ip) - dup(ip,1)*rmatm(ip)*dt
               rhov(ip) = rhov(ip) - dup(ip,2)*rmatm(ip)*dt
               rhoE(ip) = rhoE(ip) - dup(ip,3)*rmatm(ip)*dt
               p(ip)= gammal * (rhoE(ip) - 0.5*rhov(ip)*v(ip) )
            end if
         end do

         if ( mod(i, 10) .eq. 0 ) then
            write(50,*)' it,dt = ',i,dt
            write(50,*)' it npoin(active) nelem(active)'
            npac=0
            do ip=1,mpoin
               if (ipact(ip) .eq. 1 ) then npac=npac+1
            end do
            neac=0
            do ie=1,melem
               if (mrhist(ie,5) .eq. 1 ) then
                  neac=neac+1
                  l(intmat(ie,1))=mrhist(ie,4)
               end if
            end do
            write(50,*) i,npac ,neac, npoin, nelem
            write(50,*)' xp rho v ',
     &           ' rhoE p l '
            do ip=1,npoin
               if (ipact(ip) .eq. 1 ) then
                  write(50,6) xp(ip),rho(ip),v(ip),rhoE(ip),p(ip),l(ip)
               end if
            end do
         end if
      end do
 6    format (5(2x, e12.5))      
      end

      subroutine init(gamma,cour,ntime,di,ctore,ctode,epsil,nrmax,
     &     nbuff,ntref,npoin, nelem, mpoin, melem,
     &     period, intmat, mrhist, irefe, idere, ipact,
     &     xp, rho, p, v, rhov, rhoE,
     &     ibdry_l, ibdry_r )
      real xp(mpoin),rho(mpoin),p(mpoin),v(mpoin),rhov(mpoin)
      real rhoE(mpoin)
      integer intmat(melem,2),mrhist(melem,5),irefe(melem)
      integer idere(melem),ipact(mpoin)
      parameter(pi=3.141592654)
      gamma= 1.4
      gammal=gamma-1.
      cour =0.5
      ntime=3000
      di =0.5
      ctore=.25
      ctode = .1
      epsil=0.005
      nbuff=3
      ntref=2
      nrmax=3
      npoin=128
      nelem=127
      do ie=1,npoin-1
         intmat(ie,1)=ie
         intmat(ie,2)=ie+1
      end do
      if (period .ne. 0.) then
         intmat(nelem,1)=nelem
         intmat(nelem,2)=1
      else
         ibdry_l=1
         ibdry_r=npoin
      end if
      do ie=1,melem
         do ir=1,5
            mrhist(ie,ir)=0
         end do
         irefe(ie)=0
         idere(ie)=0
      end do
      do ie=1,nelem
         mrhist(ie,5)=1
      end do
      do ip=1,npoin
         ipact(ip)=1
      end do
      do ip=npoin+1,mpoin
         ipact(ip)=0
      end do
      do ip=1,npoin/2
         rho(ip) = 8.
         p(ip)=10.
      end do
      do ip=npoin/2,npoin
         rho(ip) = 1.
         p(ip) = 1.
      end do
      do ip=1,npoin
         xp(ip) =float(ip-1)*6.4/float(npoin)
         v(ip) =0.0
         rhov(ip)=rho(ip)*v(ip)
         rhoE(ip)=p(ip)/gammal + 0.5*rho(ip)*v(ip)*v(ip)
      end do
      it=0
      write(50,*)'initial conditions'
      write(50,*)' it npoin nelem'
      write(50,*) it,npoin,nelem
      write(50,*)' xp rho v ',
     &     ' rhoE p '
      do i=1,npoin
         write(50,6) xp(i),rho(i),v(i),rhoE(i),p(i)
      end do
 6    format (5(2x, e12.5))
      return
      end

      subroutine geom(mpoin, melem, npoin, nelem, intmat, xp,
     &     ce, rmatm, rlen, period, mrhist, ipact )
      integer mpoin,melem,npoin,nelem,intmat(melem,2)
      real xp(mpoin),ce(melem,2),rmatm(mpoin),rlen(melem)
      integer mrhist(melem,5),ipact(mpoin)
      do ip=1,npoin
         rmatm(ip)=0.
      end do
      do ie=1,nelem
         rlen(ie)=0.
      end do
      do ie=1,nelem
         if (mrhist(ie,5) .eq. 1 ) then
            rlen(ie) = xp(intmat(ie,2)) - xp(intmat(ie,1))
         endif
      end do
      if ( period .ne. 0. ) then
         do ie=1,nelem
            if (abs(rlen(ie)) .gt. period/2. ) then
               rlen(ie)=period + rlen(ie)
            end if
         end do
      end if
      do ie=1,nelem
         if (mrhist(ie,5) .eq. 1 ) then
            ce(ie,2)=1./rlen(ie)
            ce(ie,1)=-1.*ce(ie,2)
         end if
      end do
      do ie=1,nelem
         if (mrhist(ie,5) .eq. 1 ) then
            do in=1,2
               rmatm(intmat(ie,in)) = rmatm(intmat(ie,in)) + rlen(ie)
            end do
         end if
      end do
      do ip=1,npoin
         if ( ipact(ip).eq.1 ) then
            rmatm(ip) = 2./rmatm(ip)
         endif
      end do
      return
      end

      subroutine grerror(nelem, npoin, melem, mpoin, vref,
     &     tempea, tempec, temppa, temppb, temppc,
     &     epsil, ctore, ctode, nbuff, errorp,
     &     errore, mrhist, ipact,
     &     irefe, idere, ce, rlen, intmat,
     &     ietemp,iptemp,ibdry_l,ibdry_r )
      integer intmat(melem,2),mrhist(melem,5),ipact(mpoin)
      integer irefe(melem),idere(melem)
      integer iptemp(mpoin),ietemp(melem)
      real ce(melem,2),rlen(melem)
      real tempea(melem),tempec(melem),errore(melem)
      real temppa(mpoin),temppb(mpoin),temppc(mpoin),errorp(mpoin)
      real vref(mpoin)
      nbuff=3
      do ie=1,melem
         tempea(ie)=0.
         tempec(ie)=0.
         errore(ie)=0.
         irefe(ie) =0.
         idere(ie) =0.
      end do
      do ip=1,mpoin
         temppa(ip)=0.
         temppb(ip)=0.
         temppc(ip)=0.
         errorp(ip)=0.
      end do
      do ie=1,nelem
         if (mrhist(ie,5) .eq. 1) then
            do in=1,2
               tempea(ie) = tempea(ie) + ce(ie,in)*vref(intmat(ie,in))
               tempec(ie) = tempec(ie) + abs(ce(ie,in)
     &              *abs(vref(intmat(ie,in)) ))
            end do
         end if
      end do
      do ie=1,nelem
         if (mrhist(ie,5) .eq. 1) then
            do in=1,2
               temppa(intmat(ie,in)) = temppa(intmat(ie,in)) +
     &              rlen(ie)*ce(ie,in)*tempea(ie)
               temppb(intmat(ie,in)) = temppb(intmat(ie,in)) +
     &              rlen(ie) * abs(ce(ie,in)) *
     &              abs(tempea(ie))
               temppc(intmat(ie,in)) = temppc(intmat(ie,in)) +
     &              rlen(ie) * abs(ce(ie,in)) *
     &              tempec(ie)
            end do
         end if
      end do
      temppa(ibdry_l) = 0.
      temppa(ibdry_r) = 0.
      do ip=1,npoin
         if (ipact(ip) .eq. 1 ) then
            errorp(ip) = abs(temppa(ip)) /
     &           (temppb(ip) + epsil*temppc(ip) )
         endif
      end do
      do ie=1,nelem
         if (mrhist(ie,5).eq.1) then
            errore(ie)=amax1(errorp(intmat(ie,1)) ,
     &           errorp(intmat(ie,2)) )
         end if
      end do
      do ie=1,nelem
         if (mrhist(ie,5).eq.1) then
            if (errore(ie).gt.ctore) irefe(ie)=1
            if (errore(ie).lt.ctode) idere(ie)=1
         end if
      end do
      do ib=1,nbuff
         do ip=1,npoin
            iptemp(ip)=0
         end do
         do ie=1,nelem
            if (mrhist(ie,5).eq.1) then
               do in=1,2
                  if (irefe(ie) .eq. 1) then
                     iptemp(intmat(ie,in)) = 1
                  endif
               end do
            end if
         end do
         do ie=1,nelem
            if (mrhist(ie,5).eq.1) then
               do in=1,2
                  if (iptemp(intmat(ie,in)) .eq. 1) then
                     irefe(ie) = 1
                  endif
               end do
            end if
         end do
      end do
      do iloop=1,5
         do ie=1,nelem
            ietemp(ie) = 0
            if (mrhist(ie,5).eq.1) then
               ietemp(ie) = mrhist(ie,4) + irefe(ie)
            endif
         end do
         do ip=1,npoin
            iptemp(ip)=0
         end do
         do ie=1,nelem
            if (mrhist(ie,5).eq.1) then
               do in=1,2
                  if (ietemp(ie) .gt. iptemp(intmat(ie,in)) ) then
                     iptemp(intmat(ie,in)) = ietemp(ie)
                  endif
               end do
            end if
         end do
         do ie=1,nelem
            if (mrhist(ie,5).eq.1) then
               do in=1,2
                  if (iptemp(intmat(ie,in))-mrhist(ie,4) .gt. 1) then
                     irefe(ie) = 1
                  endif
                  if (iptemp(intmat(ie,in))-mrhist(ie,4) .ge. 1) then
                     idere(ie) = 0
                  endif
               end do
               ietemp(ie) = mrhist(ie,4) + irefe(ie)
               do in=1,2
                  if (ietemp(ie) .gt. iptemp(intmat(ie,in)) ) then
                     iptemp(intmat(ie,in)) = ietemp(ie)
                  endif
               end do
            end if
         end do
      end do
      return
      end

      subroutine unref(melem, mpoin, nelem, npoin, intmat,
     &     mrhist, idere,ipact )
      integer intmat(melem,2)
      integer mrhist(melem,5),idere(melem)
      integer ipact(mpoin)
      do ie=1,nelem
         if ( idere(ie).eq.1 .and. mrhist(ie,4).ne.0 ) then
            iparent=mrhist(ie,1)
            ichild1=mrhist(iparent,2)
            ichild2=mrhist(iparent,3)
            if ( idere(ichild1).eq.1 .and. idere(ichild2).eq.1 )
     &           then
               do in=1,2
                  ipl=intmat(ichild1,in)
                  ip2=intmat(ichild2,in)
                  if (ipl.ne.intmat(iparent,1) .and.
     &                 ipl.ne.intmat(iparent,2) ) ipact(ipl)=0
                  if (ip2.ne.intmat(iparent,1) .and.
     &                 ip2.ne.intmat(iparent,2) ) ipact(ip2)=0
               end do
               mrhist(ichild1,5)=0
               mrhist(ichild2,5)=0
               mrhist(iparent,5)=1
               idere(ichild1)=0
               idere(ichild2)=0
            end if
         end if
      end do
      return
      end

      subroutine refine(melem, mpoin, nelem, npoin, intmat, nrmax,
     &     mrhist, xp, rho, rhov, rhoE, irefe, ipact )
      integer intmat(melem,2)
      real xp(mpoin)
      real rho(mpoin),rhov(mpoin),rhoE(mpoin)
      integer mrhist(melem,5),irefe(melem)
      integer ipact(mpoin)
      nrmaxl=nrmax-1
      do ie=1,nelem
         if ( irefe(ie).eq.1 .and. mrhist(ie,4).le.nrmaxl ) then
            npoin=npoin+1
            ipact(npoin)=1
            if (npoin .gt. mpoin) then
               write(*,*)'Please increase mpoin. Needed:',npoin
               stop
            end if
            nelem2=nelem+2
            if (nelem2 .gt. melem) then
               write(*,*)'Please increase melem.
     &Needed:',nelem2
               stop
            end if
            xp(npoin) = 0.5*(xp(intmat(ie,1)) + xp(intmat(ie,2)) )
            rho(npoin) = 0.5*( rho(intmat(ie,1)) +
     &           rho(intmat(ie,2)) )
            rhov(npoin) = 0.5*(rhov(intmat(ie,1)) +
     &           rhov(intmat(ie,2)) )
            rhoE(npoin) = 0.5*(rhoE(intmat(ie,1)) +
     &           rhoE(intmat(ie,2)) )
            intmat(nelem+1,1) = intmat(ie,1)
            intmat(nelem+1,2) = npoin
            intmat(nelem+2,1) = npoin
            intmat(nelem+2,2) = intmat(ie,2)
            mrhist(ie,5)=0
            mrhist(nelem+1,5) = 1
            mrhist(nelem+2,5) = 1
            mrhist(ie,2) = nelem+1
            mrhist(ie,3) = nelem+2
            mrhist(nelem+1,1) = ie
            mrhist(nelem+2,1) = ie
            mrhist(nelem+1,4) = mrhist(ie,4) + 1
            mrhist(nelem+2,4) = mrhist(ie,4) + 1
            nelem=nelem+2
         end if
      end do
      return
      end

      subroutine fluxld(mpoin, melem, npoin, nelem, gamma, cour,
     &     intmat, rho, rhov, rhoE, p, v,
     &     rlen, vmax, flux, dt, mrhist, ipact )
      integer mpoin,melem,npoin,nelem,intmat(melem,2)
      real rho(mpoin),rhov(mpoin),rhoE(mpoin)
      real p(mpoin),v(mpoin),flux(mpoin,3)
      real rlen(melem),vmax(mpoin)
      integer mrhist(melem,5),ipact(mpoin)
      cbig=1.e30
      gammal=gamma-1.
      do ip=1,npoin
         if ( ipact(ip).eq.1 ) then
            v(ip) =rhov (ip)/rho (ip)
            p(ip)= gammal*(rhoE(ip) - 0.5*rhov(ip)*v(ip) )
            flux(ip,1) = rhov(ip)
            flux(ip,2) = rhov(ip)*v(ip) + p(ip)
            flux(ip,3) = rhoE(ip)*v(ip) + p(ip)*v(ip)
         end if
      end do
      do ip=1,npoin
         if ( ipact(ip).eq.1 ) then
            vmax(ip) = sqrt(gamma*p(ip)/rho(ip)) + abs(v(ip))
         endif
      end do
      dt= cbig
      do ie=1,nelem
         if (mrhist(ie,5)
     &        .eq. 1 ) then
            do in=1,2
               dt = amin1( dt,
     &              rlen(ie)/vmax(intmat(ie,in)))
            end do
         end if
      end do
      dt =cour * dt
      return
      end

      subroutine deltau(mpoin, melem, npoin,nelem,intmat,
     &     du,dup,flux,dt,ce,rlen,cour,di,rho,rhov,rhoE,diff,
     &     vmax,mrhist)
      integer mpoin,melem,npoin,nelem, intmat(melem,2)
      real du(melem,3), dup(mpoin,3),flux(mpoin,3),dt
      real ce(melem,2),rlen(melem)
      real rho(mpoin),rhov(mpoin),rhoE(mpoin),diff(melem,3)
      real vmax(mpoin)
      integer mrhist(melem,5)
      cbig=1.e20
      csmall=-1.e20
      do im=1,3
         do ie=1,nelem
            du(ie,im) =0
            diff(ie,im) = 0.
         end do
      end do
      rlmin=cbig
      rlmax=csmall
      do ie=1,nelem
         if (mrhist(ie,5).eq.1 .and. rlen(ie).lt.rlmin)
     &        rlmin=rlen(ie)
         if (mrhist(ie,5).eq.1 .and. rlen(ie).gt.rlmax)
     &        rlmax=rlen(ie)
      end do
      do im=1,3
         do ip=1,npoin
            dup(ip,im)=0.
         end do
      end do
      do ie=1,nelem
         if (mrhist(ie,5) .eq. 1 ) then
            do im=1,3
               do in=1,2
                  du(ie,im) = du(ie,im) +
     &                 ce(ie,in)*flux(intmat(ie,in),im)
               end do
            end do
            vv=amax1(vmax (intmat (ie, 1)),vmax (intmat (ie,2) ))
            do in=1, 2
               diff(ie,1) = diff(ie,1) + ce(ie,in)*rho(intmat(ie,in))
     &              *vv
               diff(ie,2) = diff(ie,2) + ce(ie,in)*rhov(intmat(ie,in))
     &              *vv
               diff(ie,3) = diff(ie,3) + ce(ie,in)*rhoE(intmat(ie,in))
     &              *vv
            end do
            dfact = 0.5*di
            do im=1,3
               diff(ie,im)= dfact *diff(ie,im)*rlen(ie)*rlmin
            end do
            do im=1,3
               do in=1,2
                  dup(intmat(ie,in),im)=
     &                 dup(intmat(ie,in),im)
     &                 +0.5*rlen(ie)*du(ie,im)
     &                 +ce(ie,in)*diff(ie,im)
               end do
            end do
         end if
      end do
      return
      end
