# CS 415: Shell Lab
This project aims to create a shell program, similar to the terminal window in Linux. The objective of this project is to provide users with a tool that allows them to interact with the Operating System. The project aims to demonstrate the ability to use different system calls, arrays, strings, and tokenizing. In addition, users will learn how to create new processes and interact with the file system.

<h3>Learning Goals</h3>
The primary learning goals of this project are:

* Practice finding and using documentation for system calls.
* Learn how to use fork to create a new process.
* Demonstrate the ability to create a program in C that uses several different system calls, arrays, strings, and tokenizing.

<h3>Program Description</h3>
The project is divided into three parts:

<h4>Part A - Basic Shell</h4>
This part involves setting up a loop that reads in a command with arguments. The command and arguments should be parsed, and if the command is an echo command, the rest of the arguments (excluding the echo) will be printed to the STDOUT. The program should also have an exit command to terminate the program.

<h4>Part B - File System Commands</h4>
In this part, directories will be added into the shell program. The program should have commands such as ls, cd, mkdir, and rmdir, which will interact with the file system. Appropriate error messages should be printed if the user input is not correct.

<h4>Part C - Launching Processes</h4>
This part involves launching a process in the shell program. If the first token is not recognized as a command from the previous parts, the first token should be treated as an executable program, and a new process should be launched to run the program. If the executable program's output needs to be redirected to a file instead of the terminal, the output should be redirected to the specified file.
