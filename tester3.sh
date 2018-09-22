#!/bin/bash
X=1
while [ $X -le 24367 ]
do
./test_fol/corewar test_fol/test_maps/2014/_.cor test_fol/test_maps/2014/Asombra.cor test_fol/test_maps/2014/_honeybadger.cor test_fol/test_maps/2014/big_feet.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/2014/_.cor test_fol/test_maps/2014/Asombra.cor test_fol/test_maps/2014/_honeybadger.cor test_fol/test_maps/2014/big_feet.cor -dump $X > my_d
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
