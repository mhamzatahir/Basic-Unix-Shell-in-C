#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#define BUFFER_SIZE 256

void shell() // Function that runs the shell
{
    char buffer[BUFFER_SIZE]; // Create a buffer to hold the input command
    while (1)                 // Infinite loop to keep the shell running
    {
        printf("mysh> ");                           // Display the prompt
        if (fgets(buffer, BUFFER_SIZE, stdin) == 0) // Read the user input
        {
            printf("Nothing entered.\n"); // If nothing was entered, break the loop
            break;
        }
        

        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from the input
        if (strcmp(buffer, "exit") == 0) exit(0);
        pid_t pid = fork(); // Create a child process using fork()
        if (pid < 0)        // If fork fails
        {
            fprintf(stderr, "Fork failed\n");
            continue; // Continue the loop if fork fails
        }
        else if (pid == 0) // If we are in the child process
        {
            execlp(buffer, buffer, (char *)NULL);                     // Execute the command entered by the user
            fprintf(stderr, "Command '%s' not available.\n", buffer); // If execlp fails, print an error
            exit(EXIT_FAILURE);                                       // Exit the child process with failure status
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
