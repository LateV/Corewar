#!/bin/bash
X=1350
while [ $X -le 5100 ]
do
./test_fol/corewar test_fol/test_maps/std/Octobre_Rouge_V4.2.cor test_fol/test_maps/std/zork.cor test_fol/test_maps/std/turtle.cor test_fol/test_maps/GagnantT.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/std/Octobre_Rouge_V4.2.cor test_fol/test_maps/std/zork.cor test_fol/test_maps/std/turtle.cor test_fol/test_maps/GagnantT.cor -dump $X > my_d
LA="$(diff my_d std_d)"
if [ $LA="" ] ; then
		echo "$X no"
		diff my_d std_d > Leka
	else
		echo "$X different"
		diff my_d std_d > Leka
		break
fi
X=$((X+1))
done
