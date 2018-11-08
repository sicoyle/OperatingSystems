/*
 * Author: Samantha Coyle
 * Assignment 2 Homework 3
 * Due Date: Nov 9, 2018
 * */

#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

//Create award struct
struct Award {
	int currentAwardAmount;
	int givenOut;
};

//Functions
void student(char c);

//Variables to be used
struct Award award;

//Create mutex for mutual exclusion
pthread_mutex_t mutex;

int main() {
	//Initial values
	award.currentAwardAmount = 4000;
	award.givenOut = 0;

	//Threads
	pthread_t a,b,c;

	//Create threads
	pthread_create(&a, NULL, (void *(*)(void*))student, (void*)'A');
	pthread_create(&b, NULL, (void *(*)(void*))student, (void*)'B');
	pthread_create(&c, NULL, (void *(*)(void*))student,(void*)'C');

	//Have threads wait for completion of others
	pthread_join(a, NULL);
	pthread_join(b, NULL);
	pthread_join(c, NULL);

	printf("Total amount awarded: $ %d \n\n", award.givenOut);

	pthread_exit(0);
}

void student(char c) {
	//Variables
	int total = 0;
	int temp;

	//Lock for mutual exclusion
	pthread_mutex_lock(&mutex);
	
	//Loop through while still money present
	while(0 < award.currentAwardAmount) { 
		//Adjust award amount
		temp = ceil(award.currentAwardAmount * 0.25);
		award.currentAwardAmount -= temp;
		total += temp;
		printf("%c = %d \n", c, temp);

		//Sleep threads
		sleep(1);
		
		//Unlock
		pthread_mutex_unlock(&mutex);
	}
	
	award.givenOut += total;
}
