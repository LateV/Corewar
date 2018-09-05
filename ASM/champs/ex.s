.name     "ydor"
.comment "j"

sti:sti r1,%:live,%1
	and	r1,r0,r1
live: live r1
	zjmp%:live
