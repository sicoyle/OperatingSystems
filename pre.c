#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){

	//Variables
	int i, j;
	//10 for number of states entered, and 8 for state abbreviation plus space plus 5 spots for population
	char List[10][8];
	char abbreviation[10][2];
	char population[10][5];
	char trash;
		printf("Enter in a list of US states and their populations. Enter in the form: "
				"TX 26 "
				"NC 9 "
				"MD 5 "
				"NY 19 "
				"Ctrl-D (to terminate the program. \n");
	
//	while(scanf("%2s, %[ ], %s", List[i], population[i]) != EOF){
	//Read in input
//		i++;
//	}

/*	//Reads in list right, but not population
	while(scanf("%2s, %c", &List[i][j], &population[i][j]) != EOF){
		printf("List: %s \n", &List[i][j]);
		printf("pop: %c \n", population[i][j]);
		
		
		i++, j++;
	}
*/

	



/*	while(scanf("%s", str){
			abbreviation[i] = strtok(str, delim);
			
			population[i] = strtok(NULL, delim);
			}

*/
	



//	for(i = 0; i < 10; i++){
//		//printf("%s, %s", List[i], population[i]);	
//		printf("State abbreviation: %s \n", List[i]);
//	       	printf("Population: %s \n", population[i]);
//	}	




	return(0);
}
