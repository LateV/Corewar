.name "Anchor"
.comment "What does not kill you makes you stronger"

l2:		sti r1, %:live, %1
		live %1
		fork %100
		and r1, %0, r1
		
debut:		live %42			#5
		sti  r4,%:label , %1		#7
		add  r4,r12,r4			#5	
		sub  r10,r11,r10		#5
		zjmp %:init			#3
		fork %:debut			
		live %3


live:	live %1
		zjmp %:live
		live %1
