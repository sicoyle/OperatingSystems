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
int main(){
	//variables to establish pipe
	int p[2];
	int bytes;

	//fork first so child can inherit pipe
	pid_t pid = fork();

	pipe(p);

	//error state
	if(pid < 0){
		printf("There was an issue forking.\n");
		exit(1);
	} else if(pid == 0){
		//child
		close(1);
		dup(p[1]);
		close(p[1]);
		close(p[0]);
		
		//execute program
		execl("./pre", "pre", (char *) 0);
		//return(EXIT_FAILURE);

		kill(pid, SIGTERM);
	} else{
		//parent
		wait();
		close(0);
		open(1);//added
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		
		//execute program
		execl("./sort", "sort", (char *) 0);
		//return(EXIT_FAILURE);
	}
	





	return 0;
}
