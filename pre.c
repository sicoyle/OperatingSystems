#include <stdio.h>

int main (int argc, char **argv){

	//print out list
	printf ("Number of inputs entered: %d \n", argc);
	
	for(int i = 0; i < argc; i++)
		printf ("Input entered: %s \n", argv[i]);








	return(0);
}
