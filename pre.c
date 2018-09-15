#include <stdio.h>

int main (int argc, char **argv){

	//Check for at most 10 states in the list
	//argc[0] = executable
	//argc[1-21] = states and corresponding populations
	if(argc > 21){
		printf("There should be no more than 10 states entered \n");
		return(-1);
	}

	//print out list
	printf ("Number of inputs entered: %d \n", argc);
	
	for(int i = 0; i < argc; i++)
		printf ("Input entered: %s \n", argv[i]);

	






	return(0);
}
