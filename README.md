
This README should hold a good amount of documentation with
the current goal of the project, how to compile, etc;.

According to Ivo, the readme should specifically contain:
  1. Our own notes, written out so others can understand it.
  2. A guide to our project design and implementation.

_However_, it appears that #2 will specifically refer to the DOC_P1.md file.
Appendix D is what we should model our DOC files after.

[comment]: <> (This is a markdown comment, it will not be included)
[comment]: <> (Note that the following line has a soft break)
For this README:  
[Markdown Reference](https://en.support.wordpress.com/markdown-quick-reference/)

#### Common Commands to Run

Compiling the Kernel
> cd $PINTOS_ROOT/src/threads  
> make

Running a Test
> pintos -- run *test_name*  

_TODO_ insert more information on "make check", especially
as it appears for the src/threads/build makefile that runs
all tests.

#### Running GDB
###### (this is virtually unused at the moment, and might be replaced by some other means of debugging such as eclipse)
1. Start Pintos with GDB
> pintos --gdb -- run *test_name*

2. Run GDB in a new terminal tab.
> pintos-gdb kernel.o

3. Connect the GDB to the current pintos execution.
either
  > target remote localhost:1234  

  OR use the macro
  > debugpintos

Refer to Appendix E (section 5) for more information on commands that can be run in GDB, including setting breakpoints and continuing.

#### _TODO_

_Primary Task:_
Working on the priority scheduler now! See page _19_ of the pintos documentation to see the FAQ.

