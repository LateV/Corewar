#!/bin/bash
X=1
while [ $X -le 27001 ]
do
./test_fol/corewar test_fol/test_maps/GagnantT.cor test_fol/test_maps/2014/Machine-gun.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/GagnantT.cor test_fol/test_maps/2014/Machine-gun.cor -dump $X > my_d
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
