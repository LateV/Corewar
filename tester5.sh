#!/bin/bash
X=26000
while [ $X -le 27001 ]
do
./test_fol/corewar test_fol/test_maps/std/Gagnant.cor test_fol/test_maps/std/Gagnant.cor test_fol/test_maps/std/Gagnant.cor test_fol/test_maps/std/Gagnant.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/std/Gagnant.cor test_fol/test_maps/std/Gagnant.cor test_fol/test_maps/std/Gagnant.cor test_fol/test_maps/std/Gagnant.cor -dump $X > my_d
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
