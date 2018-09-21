#!/bin/bash
X=24000
while [ $X -le 50000 ]
do
./test_fol/corewar test_fol/test_maps/2014/youforkmytralala.cor test_fol/test_maps/2014/Wall.cor test_fol/test_maps/2014/Varimathras.cor test_fol/test_maps/2014/ultimate-surrender.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/2014/youforkmytralala.cor test_fol/test_maps/2014/Wall.cor test_fol/test_maps/2014/Varimathras.cor test_fol/test_maps/2014/ultimate-surrender.cor -dump $X > my_d
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
