# cpp-buffer

A buffer based on priority queue

## Functionality:

This program reads from STDIN multiple commands:

exit
- program finishs

value:priority
- value is integer
- priority is integer
- save the value to the buffer so it is ordered by priority
- if there are two same priorities they will be stored in order they come

print
- it prints buffer to STDOUT

get
- it prints the first element of the buffer

remove
- it removes the first element of the buffer

## Quick Start:

Once you have cloned the project in your local directory execute:
```
$cmake -H. -Bbuild
```
This command will configure the test environment and it will create the build folder where the executable files will be placed.

You can complie the code using:
```
$cmake --build build
```
This command will compile two applications: cpp_buffer and test:
- cpp_buffer application implements the functionality described above.
- test application implements some unitary test cases coded in test.cpp file.
