# OperatingSystems

For assignment #1:

pre.c accepts a state abbreviation followed by its population. Example input is as follows:
TX 26
NC 9
MD 5
NY 19
Ctrl-D (to terminate the input.)

The program will spit out the state abbreviations with populations > 10.

To execute:

gcc -o pre pre.c

Then enter input as desired.

sort.c accepts state abbreviations seperated by spaces. It sorts the states. Example input is as follows:
TX CA ND SD MD Ctrl-D (to terminate the input.)

The program will print the state abbreviations in alphabetical order.

To execute:

gcc -o sort sort.c

homework1problem2.c executes pre.c and writes the output of that into sort.c to sort it.

To execute:

./pre | ./sort

homework1problem3.c has a child-To-parent pipe. The process ids are printed out and the program will use argv and
argc to execute the user inputed command.

To execute:

gcc homework1problem3.c

./a.out "ls -t -l"

What is in quotes can be changed to execute different commands. 
