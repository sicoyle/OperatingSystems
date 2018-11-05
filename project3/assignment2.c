#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

struct Award {
	int currentAwardAmount;
	int givenOut;
};

//Functions
void student(char c);

//Variables to be used
struct Award award;

pthread_mutex_t mutex;

int main() {
	//Initial values
	award.currentAwardAmount = 4000;
	award.givenOut = 0;

	pthread_t a,b,c;

	//Create threads
	pthread_create(&a, NULL, (void *(*)(void*))student, (void*)'A');
	pthread_create(&b, NULL, (void *(*)(void*))student, (void*)'B');
	pthread_create(&c, NULL, (void *(*)(void*))student,(void*)'C');

	pthread_join(a, NULL);
	pthread_join(b, NULL);
	pthread_join(c, NULL);

	printf("Total award money given out: $ %d \n", award.givenOut);

	pthread_exit(0);
}

void student(char c) {
	int total = 0;
	int temp;

	pthread_mutex_lock(&mutex);
	
	while(0 < award.currentAwardAmount) { 
		temp = ceil(award.currentAwardAmount * 0.25);
		award.currentAwardAmount -= temp;
		total += temp;
		printf("%c = %d \n", c, temp);
		sleep(1);
		
		pthread_mutex_unlock(&mutex);
	}
	
	award.givenOut += total;
}
