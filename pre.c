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

	printf("Hello\n");


	//need to add in while !EOF
	while((count < 3)){
		printf("Enter abbreviation: ");
		scanf("%2s", &*temp);
		printf("Enter population: ");
		scanf("%d", &p);

		strcpy(populations[count].name, temp);
		populations[count].pop = p;

		//printf("Contents of p: %d ", p);

		count++;
	}

	for(int i = 0; i < 3; i++){
		if(populations[i].pop >= 10)
			printf("States: %s", populations[i].name);
	}

	return(0);
}	
