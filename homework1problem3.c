/*Author: Samantha Coyle
 * Date: 9/22/2018
 * Purpose: This program takes in a UNIX command and forks a child to
 * execute it. It uses argv and argc to pass parameters to main(). When
 * the child process is executing the command, the parent waits for the
 * child termination. Print process id's of each process.
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv){
	int pid;
	int status;

	pid = fork();

	//error
	if(pid < 0){
		printf("There was an issue forking.\n");
		exit(1);
	} else if(pid == 0){
		//Child
		printf("Child process started.\n");
		printf("Executing %s command.\n", argv[1]);
		printf("Output of command passed is:\n");
		system(argv[1]);
	} else{
		//parent process
		printf("Parent process started.\n");
		wait( (int *)0);
		wait(&status);//wait for child to exit and store child's exit status
		printf("\nParent process finished.\n");
		printf("The child's pid is %d and the parent's pid is %d.\n", getpid(), getppid());

	}


	return 0;
}
