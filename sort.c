/* Author: Samantha Coyle
 * Date: 9/22/2018
 * Purpose: This program takes in state abbreviations and sorts
 * them into alphabetical order.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv){
	//no more than 10 states
	if(argc > 11){
		printf("%s\n", "Too many states entered");
		exit(1);
	} else{	
		struct st_ex structs[argc - 1]; 

		//Copy over state abbreviations to the struct state name variable
		for(int i = 1; i < argc; i++){
			strcpy(structs[i].name, argv[i]);
		}

		size_t structs_len = sizeof(structs) / sizeof(struct st_ex) + 1;

		//Sort struct state abbreviations
		qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_state);
		//Print out sorted list
		for(int i = 1; i < argc; i++)
			printf("\n%s\n", &*structs[i].name);
	}

	return 0;
}
