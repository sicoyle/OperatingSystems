/* Author: Samantha Coyle
 * Date: 9/22/2018
 * Purpose: This program takes in state abbreviations and sorts
 * them into alphabetical order.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct st_ex{
	char name[3];
//	int pop;
};

//Comparator function to compare state abbreviations
int struct_cmp_by_state(const void *a, const void *b){

	struct st_ex *ia = (struct st_ex *)a;
	struct st_ex *ib = (struct st_ex *)b;

	return strcmp(ia -> name, ib -> name);
}

int main(){
	//Variables
	int i = 0;	
	struct st_ex stateAbbreviations[SIZE]; 

	//struct size	
	memset(&stateAbbreviations, 0 , sizeof(stateAbbreviations) + 1);

	//read in the states
	while((SIZE > i++) && (scanf("%s", stateAbbreviations[i].name) != EOF)){}
	
	//get actual size of struct to fix bug of skipping sorting last state
	size_t actual = sizeof(stateAbbreviations) / sizeof(struct st_ex) + 1;

	//sort
	qsort(stateAbbreviations, actual, sizeof(struct st_ex), struct_cmp_by_state);

	i = 0;

	//print sorted list		
	while(i < SIZE + 1){
		printf("%s\n", stateAbbreviations[i].name);
		i++;
	}

	printf("\n");

	return(0);
}
