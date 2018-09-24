.name "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum vitae nibh volutpat, consequat ante vitae, elementum nullam."
.comment "fgfgf"
l2:	sti	,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
