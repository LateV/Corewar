.name "z"
.comment "j"

zjmp	%:live
label: sti r1,%:and, r1
l2:	sti	r1,%:live,%0
	and	r1,%0,r1
live:	live%1
	zjmp	%:live
and:
sti	r1,%:and,r1
