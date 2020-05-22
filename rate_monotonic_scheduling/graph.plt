set multiplot
     plot 'polar.dat' using 1:2 with boxes notitle lt rgb 'red'
     plot 'polar.dat' using 1:3 with boxes notitle lt rgb 'blue'
     plot 'polar.dat' using 1:4 with boxes notitle lt rgb 'green'
		set xtics("0" 0 "20" 2000)
unset multiplot
