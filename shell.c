#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#define BUFFER_SIZE 256 
#define ARGS_LIMIT 20 //Arguements limit

void shell() // Function that runs the shell
{
    char buffer[BUFFER_SIZE]; // Create a buffer to hold the input command
    while (1) // Infinite loop to keep the shell running
    {
        printf("mysh> "); // Display the prompt
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL)
        {
            printf("Exiting...\n");
            break;
        }
        buffer[strlen(buffer)-1] = '\0'; // Remove the newline character from the input    
        
        if (strcmp(buffer, "exit") == 0) 
        {
            printf("Exiting...\n");
            break;
        }
        
        if (strlen(buffer) == 0) 
        {
            printf("Nothing entered.\n");
            continue;
        }

        char *args[ARGS_LIMIT];
        int i=0;
        char *token=strtok(buffer, " ");
        // tokenize inputs into commands and arguements
        while(token != NULL && i<ARGS_LIMIT-1)
        {
            args[i]=token;
            token=strtok(NULL, " ");
            i++;
        }
        args[i]=NULL;

        pid_t pid = fork(); // Create a child process using fork()
        if (pid < 0) // If fork fails
        {
            fprintf(stderr, "Fork failed\n");
            continue; // Continue the loop if fork fails
        }
        else if (pid == 0) // If we are in the child process
        {
            execvp(args[0], args); // Execute the command entered by the user
            fprintf(stderr, "Command '%s' not available.\n", buffer); // If execlp fails, print an error
            exit(EXIT_FAILURE); // Exit the child process with failure status
        }
        else // Parent process
        {
            int status;
            waitpid(pid, &status, 0); // Wait for the child process to finish
        }
    }
}

int main()
{
    shell(); // Call the shell function to start the shell
    return 0;
}

