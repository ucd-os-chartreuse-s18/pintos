### README for Project 1: Threads

#### Design Document

The design document can be found in *DOC_P1.md* in the same 
folder as this _README_

#### Group Participants
 
Matthew Moltzau <matthew.moltzau@ucdenver.edu>  
Michael Hedrick <michael.hedrick@ucdenver.edu>

#### Common Commands to Run

##### Compiling the Kernel Manually
> cd $PINTOS_ROOT/src/threads  
> make

##### Running a Single Test 
> pintos -v -- run *test_name*  

##### Running the Testing Script  
The script will run tests as they appear in the script 
internally. We have two separate scripts 1) The original
_and_ 2) The one accessible from any place in the commandline
provided src/utils is in $PATH. This version may also accept 
"debug" as an argument, which passes --gdb when running the pintos kernel.
> p1-thread-tests

_OR_
> cd $PINTOS_ROOT/src/threads  
> bash pintos-p1-tests.sh

#### _TODO_

_Alarm:_  
The alram may need to be updated. See details in the design doc.

*DOC_P1:*  
There are just a couple loose strings in the design doc.
