set term svg
set output "rho.svg"
set xlabel "x"
set ylabel "rho"
plot [0:8][0:8] \
     "<awk 'NR > 4' 0000500.dat | sort -g" u 1:2 w p pt 6 t ""

set output "level.svg"
set ylabel "level"
plot \
     [0:8][0:5] \
     "<awk 'NR > 4' 0000500.dat | sort -g" u 1:6 w p pt 6 t ""
