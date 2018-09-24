.name "Anchor"
.comment "What does not kill you makes you stronger"

l2:		sti r1, %:live, %1
		live %1
		fork %:init
		and r1, %0, r1
live:	live %1
		zjmp %:live
		live %1
init:		ld   %393216,r4		 	#7	
		ld   %917504,r12		#7	
		ld   %1,r11			#7
		ld   %6,r10	 		
debut:		live %42			#5
		sti  r4,%:l2 , %1		#7
		add  r4,r12,r4			#5	
		sub  r10,r11,r10		#5
		fork %:init	
		zjmp %:init			#3		
		live %3