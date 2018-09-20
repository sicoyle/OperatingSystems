#include <stdio.h>
#include <string.h>

typedef struct state{
	char name[2];
	int pop;
} state;

int main(){
	state populations[10];
	int count = 0;
	char temp[2];
	int p;

	//need to add in while !EOF
	while((count < 10) && (scanf("%2s", &*temp) != EOF)){
		scanf("%d", &p);

		strcpy(populations[count].name, temp);
		populations[count].pop = p;

		count++;

	}

	printf("\n\n");

	for(int i = 0; i < count; i++){
		if(populations[i].pop >= 10)
			printf("%s\n", populations[i].name);
	}

	return(0);
}	
