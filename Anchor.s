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
			fork %:live17
			sti r1, %:live6, %1
			sti r1, %:live7, %1
			sti r1, %:live8, %1
live6:		live %1
live7:		live %1
live8:		live %1
			fork %:start
			live %1
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
			fork %-1000
			sti r1, %:live15, %1
			sti r1, %:live16, %1
			sti r1, %:live17, %1
live15:		live %1
live16:		live %1
live17:		live %1
			fork %:start
			live %1
			fork %-1000