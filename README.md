# Corewar
Corewar
Usage: ./asm <sourcefile.s>
Usage: ./corewar [-dump N] [-s N] [-a] [-log] [-mon][-v [-force --stealth]] <champion1.cor> <...>
 ~~~*** TEXT OUTPUT MODE MODE ***~~~~
 -a      : Prints output from "aff" (Default is to hide it)
-dump N : Dumps memory after N cycles then exits
-s N    : Runs N cycles,dumps memory, pauses, then repeats
-log    : Show operations
-mon N  : Show operations on N-th cycle only
~~~*** NCURSES OUTPUT MODE ***~~~~
-v      : Ncurses output mode
--stealth: Hides the real contents of the memory
-force  : Start game from the N-th cycle
