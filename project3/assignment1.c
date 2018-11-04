#include <pthread.h>
#include <stdio.h>

struct Award {
	float totalAwardAmount;
	float temp;
};

//Functions
void *takeAwardFirst();
void *takeAwardSecond();
void *takeAwardThird();

//Variables to be used
pthread_mutex_t mutex;
struct Award award;

int main() {
	//Initial values
	award.totalAwardAmount = 4000.0;
	award.temp = 0.0;

	//Thread ids and attributes
	pthread_t tid1, tid2, tid3;
	pthread_attr_t attribute;

	printf("First person takes away $ %d \n", award.totalAwardAmount);
	printf("First person takes away $ %d \n", award.temp);

	//Create threads
	pthread_create(&tid1, NULL, (void *(*)(void*))takeAwardFirst, NULL);
	pthread_create(&tid2, NULL, (void *(*)(void*))takeAwardSecond, NULL);
	pthread_create(&tid3, NULL, (void *(*)(void*))takeAwardThird, NULL);

	pthread_exit(0);
}

void *takeAwardFirst() {

}

void *takeAwardSecond() {

}

void *takeAwardThird() {

}
