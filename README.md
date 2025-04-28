# A simple Unix Shell 

A minimal yet functional Unix shell implementation that supports **command execution, built-ins, and argument handling**.

## Features

✅ **Command Execution**
- Runs External programs (`ls`, `grep`, `pwd`, `ps`, `top`, etc.) with arguments
- Example:
  
  ```bash
  mysh> ls -l
  mysh> top
  mysh> grep "pattern" doc.txt

✅ **Built-in Commands**
- cd
- history
- exit
- Example:

  ```bash
  mysh> cd /
  mysh> pwd
  /
  mysh> history
  1:  cd /
  2:  pwd
  3:  history
  mysh> exit
  Exiting...

✅ **Process Handling**
- Proper `fork()` + `execvp()` flow
- The parent waits for the child process

✅ **Error Handling**
- Reports failed commands
- cd displays error in the absence of the directory
- Example:

  ```bash
  mysh> wasd
  Command 'wasd' not available.
  mysh> cd folder
  cd: No such file or directory
  
## How It Works

1. Reads user input from stdin
2. Tokenizes input into command and arguments
3. Forks a child process to execute the command
4. Parent process waits for child completion
5. Handles errors during forking and execution

## Usage

1. Compile the program:
   ```bash
   gcc shell.c -o shell

2. To run the program:
   ```bash
   ./shell
