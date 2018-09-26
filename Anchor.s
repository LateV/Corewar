.name "Anchor"
.comment "What does not kill you makes you stronger"

start:		sti r1, %:live, %1
			sti r1, %:live1, %1
			sti r1, %:live2, %1
live:		live %1
live1:		live %1
live2:		live %1
			fork %:start
			live %1
			fork %:live16
			sti r1, %:live3, %1
			sti r1, %:live4, %1
			sti r1, %:live5, %1
live3:		live %1
live4:		live %1
live5:		live %1
			fork %:start
			live %1
			fork %:point
			sub r5, r6, r7
			sti r1, %:live6, %1
			sti r1, %:live7, %1
			sti r1, %:live8, %1
live6:		live %1
live7:		live %1
live8:		live %1
			zjmp %:live6
point:		live %1
			fork %:live15
			sti r1, %:live9, %1
			sti r1, %:live10, %1
			sti r1, %:live11, %1
live9:		live %1
live10:		live %1
live11:		live %1
			fork %:start
			live %1
			fork %:live9
			sti r1, %:live12, %1
			sti r1, %:live13, %1
			sti r1, %:live14, %1
live12:		live %1
live13:		live %1
live14:		live %1
			fork %:start
			live %1
			fork %2000
			sti r1, %:live15, %1
			sti r1, %:live16, %1
			sti r1, %:live17, %1
live15:		live %1
live16:		live %1
live17:		live %1
			fork %:start
start1:		sti r1, %:live18, %1
			sti r1, %:live19, %1
			sti r1, %:live20, %1
live18:		live %1
live19:		live %1
live20:		live %1
			fork %:start1
			live %1
			fork %:live16
			sti r1, %:live21, %1
			sti r1, %:live22, %1
			sti r1, %:live23, %1
live21:		live %1
live22:		live %1
live23:		live %1
			fork %:start1
			live %1
			fork %:point1
			sub r5, r6, r7
			sti r1, %:live24, %1
			sti r1, %:live25, %1
			sti r1, %:live26, %1
live24:		live %1
live25:		live %1
live26:		live %1
			zjmp %:live6
point1:		live %1
			fork %:live15
			sti r1, %:live27, %1
			sti r1, %:live28, %1
			sti r1, %:live29, %1
live27:		live %1
live28:		live %1
live29:		live %1
			fork %:start1
			live %1
			fork %:live9
			sti r1, %:live30, %1
			sti r1, %:live31, %1
			sti r1, %:live32, %1
live30:		live %1
live31:		live %1
live32:		live %1
			fork %:start1
			live %1
			fork %1500
			sti r1, %:live33, %1
			sti r1, %:live34, %1
			sti r1, %:live35, %1
live33:		live %1
live34:		live %1
live35:		live %1
			fork %:start1
			live %1
			fork %-1000
			ld %190317831, r5
			ld %10, r7
			sti  r5,%7 , %1