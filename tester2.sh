#!/bin/bash
X=20000
while [ $X -le 50000 ]
do
./test_fol/corewar test_fol/test_maps/std/fluttershy.cor test_fol/test_maps/std/toto.cor test_fol/test_maps/std/Car.cor test_fol/test_maps/std/bigzork.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/std/fluttershy.cor test_fol/test_maps/std/toto.cor test_fol/test_maps/std/Car.cor test_fol/test_maps/std/bigzork.cor -dump $X > my_d
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
