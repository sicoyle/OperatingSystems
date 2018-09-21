#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cstring_cmp(const void *a, const void *b){

	const char **ia = (const char **)a;
	const char **ib = (const char **)b;
	return strcmp(*ia, *ib);
}

int main(){
	//3 bc state abbrev + null terminator
	char states[10][2];
	int i, j;
	i = j = 0;
	char temp[10][2];

	while(scanf("%s", &states[i][j]) != EOF){
		i++, j++;
	}

	int count = i;
	size_t strings_len = sizeof(states) / sizeof(char *);

/*	for(i = 0; i < 10; i++){
		for(j = 0; j < 2; j++){
			//sort functionality
			if(strcmp(&states[i][j], &states[i+1][j]) > 0){
				strcpy(&temp[i][j], &states[i][j]);
				printf("\n%s", &temp[i][j]);
				strcpy(&states[i][j], &states[i+1][j]);
				printf("\n%s%s", &states[i][j], &states[i+1][j]);
				strcpy(&states[i+1][j], &temp[i][j]);
			}
		}

		

	}
*/
	qsort(states, strings_len, sizeof(char *), cstring_cmp);



	for(i = 0; i < count; i++)
		for(j = 0; j < 3; j++)
		printf("\n%s", &states[i][j]);

	return 0;

	}
