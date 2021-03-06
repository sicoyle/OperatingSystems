/*Homework assignment 2
 * Summary: Create a small shell script that can excuate a command with arguments,
 * recognize multiple pipe requests and handle them,
 * recognize redirection requests and handle them, 
 * and type exit to quit the shell.
 * Author: Samantha Coyle
 * Data: 10/18/2018
 **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

//define variables
#define READ 0
#define WRITE 1

int main()
{
	//Given code for command parsing
	char *path, *argv[20], buf[80], n, *p;
	int m, status, inword, continu;
	char *inputPath;
	char *outputPath;
	int arguments[20] = {0};

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

		//End of command parsing

		//Variables for pipe/command handling		
		int count = 0;
		int pipes = 0;
		int pid = 0;
		int inFlag = 0;
		int outFlag = 0;
		int rightPipe[2];
		int leftPipe[2];
		int index = 0;

		//Input redirection part
		while(argv[count] != 0) {
			if( strcmp( argv[count], "|") == 0) {
				//pipe handling
				argv[count] = 0;
				arguments[pipes + 1] = count + 1;
				++pipes;
			} else if( strcmp(argv[count], "<" ) == 0) {
				//input redirection
				inputPath = strdup(argv[count + 1]);
				argv[count] = 0;
				argv[count + 1] = 0;
				inFlag = 1;
				
				//Increment to allow for output redirection if applicable
				count++;
			} else if( strcmp(argv[count], ">" ) == 0) {
				//output redirection
				outputPath = strdup(argv[count + 1]);
				argv[count] = 0;
				argv[count + 1] = 0;
				outFlag = 1;

				//Increment to allow for input redirection if applicable
				count++;
			} else
				arguments[count] = count;

			++count;
		}

		//Loop through all of the pipes and execute commands
		for(index; index <= pipes; index++) {
			//Create right pipe
			if( (pipes > 0) && (index != pipes)) 
				pipe(rightPipe); //right pipe becomes next's child's left pipe

			//Command execution
			switch (pid = fork()) {
				case -1:
					//error case
					perror("The fork has failed!");
					break;
				case 0:
					//child process
					//Redirection and execute
					if ((index == 0) && (inFlag == 1)) {
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
						int outFile = open(outputPath, O_WRONLY | O_CREAT, 0755);
						if(outFile < 0) {
							perror("The ooutput file has failed!\n");
							return(EXIT_FAILURE);
						}
						close(WRITE);
						dup(outFile);
						close(outFile);
					}

					//manage pipes
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
	
					//Wait for child
					wait(&status);
					break;
			}
		}
	}

	return 0;
}

					

