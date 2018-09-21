#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct st_ex{
	char name[3];
//	int pop;
};

int struct_cmp_by_state(const void *a, const void *b){

	struct st_ex *ia = (struct st_ex *)a;
	struct st_ex *ib = (struct st_ex *)b;

	return strcmp(ia -> name, ib -> name);
}
/*
void print_struct_array(struct st_ex *array, size_t len){
	size_t i;

	for(i = 0; i < len; i++)
		printf("%s\n", array[i].name);

	printf("\n");
}
*/
	



int main(int argc, char **argv){

	//no more than 10 states
	if(argc > 11){
		printf("%s", "Too many states entered");
		exit(1);
	}
	else{
		
		struct st_ex structs[argc - 1]; 

/*		for(int i = 1; i < (argc); i++)
			for(int j = 0; j < 2; j++)
				strcpy(&*structs[i].name, &argv[i][j]);
*/

		for(int i = 1; i < argc; i++){
			strcpy(structs[i].name, argv[i]);
		}

		

		for(int i = 1; i < argc; i++)
			printf("%s\n", &*structs[i].name);
		


		
		size_t structs_len = sizeof(structs) / sizeof(struct st_ex);

		printf("%s%ld\n", "length: ", structs_len);

		qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_state);
		
		printf("\n%s\n\n", "Results from sort");

		for(int i = 1; i < argc; i++)
			printf("%s\n", &*structs[i].name);
		
//		print_struct_array(structs, structs_len);

	}

	return 0;
}
