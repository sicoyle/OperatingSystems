/*Author: Samnatha Coyle
 * Date: 9/22/2018
 * Purpose: This program establishes a child to parent pipe.
 * The child will execute the pre process and its output will connect to the piple
 * to the parent, which will execute the sort process.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
	//variables to establish pipe
	int p[2];

	pipe(p);
	//fork first so child can inherit pipe
	pid_t pid;
       
	pid = fork();

	//error state
	if(pid < 0){
		printf("There was an issue forking.\n");
		exit(2);
	} else if(pid == 0){
		//proper order to work with file descriptor
		//Read in
		close(p[0]);
		dup2(p[1],1);
		close(p[1]);

		//execute program to get input
		execv("pre", NULL);
		_exit(1);
	} else{
		//proper order to work with file descriptor
		//write
		close(p[1]);
		dup2(p[0], 0);
		close(p[0]);

		//execute program to sort
		execv("sort", NULL);
		perror("\nexecl() sort failed\n");
	}
	
	return 0;
}
