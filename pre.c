/*
 * Author: Samantha Coyle
 * Date: 9/20/2018
 * Operating Systems CS4328
 * 
 * Summary: This program takes in user input of state and population information and outputs
 * the state abbreviation if the population size is greater than 10
 * */

#include <stdio.h>
#include <string.h>

//Create struct to hold state abbreviation and corresponding population
typedef struct state{
	char name[2];
	int pop;
} state;

int main(){

	//variables
	state populations[10];
	int count = 0;
	char temp[2];
	int p;

	//Loop while less than 10 states and not eof
	while((count < 10) && (scanf("%2s", &*temp) != EOF)){
		
		scanf("%d", &p);
		strcpy(populations[count].name, temp);
		populations[count].pop = p;

		count++;
	}

	printf("\n\n");

	//Loop through and print state abbreviation if populatin >= 10
	for(int i = 0; i < count; i++){
		if(populations[i].pop >= 10)
			printf("%s\n", populations[i].name);
	}

	return(0);
}	
