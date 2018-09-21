#!/bin/bash
X=1
while [ $X -le 24367 ]
do
./test_fol/corewar test_fol/test_maps/std/Octobre_Rouge_V4.2.cor test_fol/test_maps/std/zork.cor test_fol/test_maps/std/turtle.cor test_fol/test_maps/GagnantT.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/std/Octobre_Rouge_V4.2.cor test_fol/test_maps/std/zork.cor test_fol/test_maps/std/turtle.cor test_fol/test_maps/GagnantT.cor -dump $X > my_d
LA="$(diff my_d std_d)"
if [ $LA="" ] ; then
		echo "$X ok"
		diff my_d std_d > Leka
	else
		echo "$X ko"
		diff my_d std_d > Leka
		break
fi
done
