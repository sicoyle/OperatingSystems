#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	//Given code for command parsing
	char *path, *argv[20], buf[80], n, *p;

	int m, status, inword, continu;

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

		if( fork() == 0 )
		{
			execvp( argv[0], argv );
			printf ( "didn't exec \n ");
		}

		wait(&status);
	}
	//End of command parsing

	int arguments[18] = {0};
	int pipes = 0;
	int pid = 0;

	//Input redirection part
	while(argv[count] != 0) {
		if( strcmp( argv[count], "|") == 0) {
			argv[count] = 0;
			arguments[pipes + 1] = count + 1;
			pipes++;
		} else if( strcmp(argv[count], "<" ) == 0) {
			//input redirection


		} else if( strcmp(argv[count], ">" ) == 0) {
			//output redirection

		} else
			arguments[count] = count;





	return 0;
}

					

