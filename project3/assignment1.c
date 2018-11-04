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



	pthread_exit(0);
}

void *takeAwardFirst() {

}

void *takeAwardSecond() {

}

void *takeAwardThird() {

}
