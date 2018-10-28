# Corewar

# What is Corewar?
 
 - Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.
 - The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc...
 - The game ends when all the processes are dead. The winner is the last player reported to be “alive”.
# Breakdown of the project’s objectives
- The assembler: this is the program that will compile your champions and translate
them from the language you will write them in (assembly language) into “Bytecode”.Bytecode
is a machine code, which will be directly interpreted by the virtual
machine.
- The virtual machine: It’s the “arena” in which your champions will be executed.
It offers various functions, all of which will be useful for the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes;
we are asking you for a gladiator fight, not a one-man show simulator.
- The champion: This one is a special case. Later, in the championship, you will
need to render a super powerful champion, who will scare the staff team to death.
However, rendering this kind of champion is serious work. And since, for now, we
are mostly interested in your capacity to create Corewar’s other programs (i.e. the
assembler and virtual machine), your current champion will only need to prove to
us that you can write bits and pieces of Corewar ASM. This means that the champion
you should render for this project only needs to scare the bejesus out of a
neurasthenic hedgehog.
### Usage:

```sh
make
```

```sh
./asm <sourcefile.s>
```
It will read the assembly’s code processed from the file .s given as argument, and write the resulting bytecode in a file named same as the argument by replacing the extension .s  by  .cor
 
```sh
./corewar [-dump N] [-s N] [-a] [-log] [-mon][-v [-force --stealth]] <champion1.cor>
```
##### TEXT OUTPUT MODE MODE 

 - -a      : Prints output from "aff" (Default is to hide it)
 
- -dump N : Dumps memory after N cycles then exits

- -s N    : Runs N cycles,dumps memory, pauses, then repeats

- -log    : Show operations

- -mon N  : Show operations on N-th cycle only


##### NCURSES OUTPUT MODE 

- -v      : Ncurses output mode

- --stealth: Hides the real contents of the memory

- -force  : Start game from the N-th cycle
#### NCURSES OUTPUT MODE EXAMPLE
```sh
./corewar -v Car.cor Anchor.cor Gagnant.cor Octobre_Rouge_V4.2.cor 
```
![Alt Text](https://github.com/LateV/Corewar/blob/master/screenshots/Screen1.png)


![Alt Text](https://github.com/LateV/Corewar/blob/master/screenshots/Screen2.png)
