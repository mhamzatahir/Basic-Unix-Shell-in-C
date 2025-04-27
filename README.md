# A simple Unix Shell 

A minimal yet functional Unix shell implementation that supports basic command execution with arguments.

## Features

- Interactive shell prompt (`mysh>`)
- Reads and executes user commands
- basic commands like ls, history, pwd, ps, top etc
- Supports commands with arguments (e.g., `ls -l`, `grep pattern file.txt`, `mv file.txt document.txt`)
- Built-in exit handling (via Ctrl+D)
- Proper process forking and waiting

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
