.name "Anchor"
.comment "What does not kill you makes you stronger"

l2:		sti r1, %:live, %1
		live %1
		fork %:init
		and r1, %0, r1
live:	live %1
		zjmp %:live
		live %1
init:		ld   %393216,r4		 	
		ld   %917504,r12		
		ld   %1,r11			
		ld   %6,r10
		ld   %500, r5	

label:  zjmp %:q
q:		sti   r1,%:l2,%1  
		sti   r1,%:l2,%15 				
debut:		live %42			
		sti  r4,r5 , %1		
		add  r4,r1,r4
		add  r4,r5,r5			
		sub  r10,r11,r10
		sti  r4,r5 , %1	
		fork %:l2
		zjmp %:init				
		live %3