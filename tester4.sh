#!/bin/bash
X=1275
while [ $X -le 24367 ]
do
./test_fol/corewar test_fol/test_maps/2014/casimir.cor test_fol/test_maps/2014/champ.cor test_fol/test_maps/2014/corelol.cor test_fol/test_maps/2014/darksasuke.cor -d $X > std_d
X=$((X+1))
./corewar test_fol/test_maps/2014/casimir.cor test_fol/test_maps/2014/champ.cor test_fol/test_maps/2014/corelol.cor test_fol/test_maps/2014/darksasuke.cor -dump $X > my_d
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
