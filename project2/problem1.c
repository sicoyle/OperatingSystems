#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1



int main()
{
	//Given code for command parsing
	char *path, *argv[20], buf[80], n, *p;

	int m, status, inword, continu;

	char *inputPath;
	char *outputPath;

	while(1) {
		inword = 0;
		p = buf;
		m = 0;
		continu = 0;

		printf( "\nshhh> ");
		while( ( n = getchar() ) != '\n' || continu ) {
			if( n == ' ' ) {
				if (inword) {
					inword = 0;
					*p++ = 0;
				}
			}
		        else if ( n == '\n' ) 
				continu = 0;
			else if ( n == '\\' && !inword ) 
				continu = 1;
			else {
				if ( !inword ) {
					inword = 1;
					argv[m++] = p;
					*p++ = n;
				}
				else 
					*p++ = n;
			}
		}

		*p++ = 0;
		argv[m] = 0;

		if( strcmp(argv[0],"exit") == 0 ) exit (0);

/*		if( fork() == 0 )
		{
			execvp( argv[0], argv );
			printf ( "didn't exec \n ");
		}

		wait(&status);
*/	
		//End of command parsing

		int count = 0;
		int arguments[18] = {0};
		int pipes = 0;
		int pid = 0;
		int inFlag = 0;
		int outFlag = 0;
		int rightPipe[2];
		int leftPipe[2];

		//Input redirection part
		while(argv[count] != 0) {
			if( strcmp( argv[count], "|") == 0) {
				argv[count] = 0;
				arguments[pipes + 1] = count + 1;
				++pipes;
			} else if( strcmp(argv[count], "<" ) == 0) {
				//input redirection
				inputPath = strdup(argv[count + 1]);
				argv[count] = 0;
				argv[count + 1] = 0;
				inFlag = 1;
			} else if( strcmp(argv[count], ">" ) == 0) {
				//output redirection
				outputPath = strdup(argv[count + 1]);
				argv[count] = 0;
				argv[count + 1] = 0;
				outFlag = 1;
			} else
				arguments[count] = count;

			++count;
		}

		for(int index = 0; index <= pipes; index++) {
			if( (index != pipes) && (pipes > 0)) 
				pipe(rightPipe);


			switch (pid = fork()) {
				case -1:
					//error case
					perror("The fork has failed!");
					break;
				case 0:
					//children
					if ((index == 0) && (inFlag == 1)){
						int inFile = open(inputPath, O_RDONLY, 0400);
						if(inFile == -1) {
							perror("The input file has failed!\n");
							return(EXIT_FAILURE);
						}
	
						close(READ);
						dup(inFile);
						close(inFile);
					}

					if ((index == pipes) && (outFlag == 1)) {
						int outFile = open(path, O_WRONLY | O_CREAT, 0755);
						if(outFile < 0) {
							perror("The ooutput file has failed!\n");
							return(EXIT_FAILURE);
						}
						close(WRITE);
						dup(outFile);
						close(outFile);
					}

					if (pipes > 0) {
						//1st child process
						if (index == 0) {
							close(WRITE);
							dup(rightPipe[WRITE]);
							close(rightPipe[WRITE]);
							close(rightPipe[READ]);
						} else if ( index < pipes){
							//2nd child process
							close(READ);
							dup(leftPipe[READ]);
							close(leftPipe[READ]);
							close(leftPipe[WRITE]);
							close(WRITE);
							dup(rightPipe[WRITE]);
							close(rightPipe[READ]);
							close(rightPipe[WRITE]);
						} else{
							//last child process
							close(READ);
							dup(leftPipe[READ]);
							close(leftPipe[READ]);
							close(leftPipe[WRITE]);
						}
					}
					execvp(argv[arguments[index]], &argv[arguments[index]]);
					perror("The command failed to execute!\n");
					break;
				default:
					//parent process
					if (index > 0) {
						close(leftPipe[READ]);
						close(leftPipe[WRITE]);
					}
	
					leftPipe[READ] = rightPipe[READ];
					leftPipe[WRITE] = rightPipe[WRITE];
	
					wait(&status);
					break;
			}
		}

	}


	return 0;
}

					

