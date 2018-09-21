#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct st_ex{
	char name[3];
	int pop;
};

int struct_cmp_by_state(const void *a, const void *b){

	struct st_ex *ia = (struct st_ex *)a;
	struct st_ex *ib = (struct st_ex *)b;

	return strcmp(ia -> name, ib -> name);
}

void print_struct_array(struct st_ex *array, size_t len){
	size_t i;

	for(i = 0; i < len; i++)
		printf("%s\n", array[i].name);

	printf("\n");
}

int main(){
	struct st_ex structs[] = {{"TX", 10}, {"CA", 8}, {"SC", 1}, {"SD", 90}};

	size_t structs_len = sizeof(structs) / sizeof(struct st_ex);

	print_struct_array(structs, structs_len);

	qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_state);

	print_struct_array(structs, structs_len);

	return 0;
}
