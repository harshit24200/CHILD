#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
	char *str;
	pipe(fd);

    pid_t sg;
    sg = fork();
    switch(sg){
        
        case 0:
		    close(fd[1]);
		    read(fd[0], &str, 19);
		    printf("Child process id = %d,\n", getpid());
            printf("Message received ' %s '\n\n", str);
		    close(fd[0]);

        default:
		    close(fd[0]);   
		    str = "end term practical"; 
		    write(fd[1], &str, 19);
		    printf("PID = %d, Message Sent\n", getpid());
            close(fd[1]);
    }
    
    return 0;
}
