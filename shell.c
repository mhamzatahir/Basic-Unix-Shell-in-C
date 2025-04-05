#include "header.h"
void shell()
{
    char buffer[BUFFER_SIZE];
    while(1)
    {
        printf("mysh> ");
        if(fgets(buffer, BUFFER_SIZE, stdin)==0)
        {
            printf("Nothing entered.");
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        pid_t pid = fork();
        if(pid<0)
        {
            fprintf(stderr, "Fork failed");
            continue;
        }
        else if(pid==0)
        {
            execlp(buffer, buffer, (char *)NULL);
            fprintf(stderr, "Command '%s' not available.\n", buffer);
            exit(EXIT_FAILURE);
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}
int main()
{
    shell();
    return 0;
}