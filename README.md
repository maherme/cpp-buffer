# cpp-buffer
A buffer based on priority queue

1. Functionality:

This program (coded in C++) reads from STDIN multiple commands:

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

2. Organization:

This repository contains the code to implement the functionality described above and also some unitary tests.
The repository is organized as follow:
  
|── main.cpp
├── modules
│   ├── Data
│   │   ├── CMakeLists.txt
│   │   ├── Data.cpp
│   │   ├── Data.h
│   └── functions
│       ├── CMakeLists.txt
│       ├── functions.cpp
│       └── functions.h
└── test.cpp

When repository is cloned you should execute the following commands:
$cmake -H. -Bbuild (this command will configure the test environment (googletest) and it will create the build folder where the executable files will be placed).
$cmake --build build (this command will compile 2 applications: cpp_buffer and test)

cpp_buffer application implements the functionality described in 1.
test application implements some unitary test cases coded in test.cpp file.
