/*
 * Author: Samantha Coyle
 * Assignment 4 Homework
 * Due Date: Nv 27, 2018
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define PAGES 6 
#define MAX 30

//Function to show the current state of the frames
void ShowFrames(int arr[],int size) {
	//Variables
	int index = 0;

	for(index; index < size; index++)
		printf("%d ", arr[index]);
	
	printf("\n");
}

void ShowData(int faults) {
	//Variables	
	int hits = MAX - faults;

	//Print page fault/hit count
	printf("\nNumber of page faults: %d", faults);
	printf("\nNumber of page hits: %d\n\n", hits);
}

//The most optimal solution for the page replacement algorithms
void OptimalSolution(int arr[], int size, int NumberOfFrames) {
	//Variables
	bool page[PAGES] = {false};
	int pageFaults = 0;
	int frame[NumberOfFrames];
	int index = 0;
	int i;
	int counter;
	int j;
	int k;
	int furthest;

	//Loop through all of the pages	
	for(i = 0; i < size; i++) {
		//Check if there is a valid frame and there are pages
		if((index < NumberOfFrames) && (!page[arr[i]])) {
			pageFaults++;
			frame[index++] = arr[i];
			page[arr[i]] = true;
		} else if((index >= NumberOfFrames) && (!page[arr[i]])) {
			bool visited[PAGES] = {false};
			counter = 0;
			pageFaults++;

			for(j = i + 1; ; j++) {
				if((counter == NumberOfFrames) || (j == size))
					break;

				if((page[arr[j]]) && (!visited[arr[j]])) {
					furthest = arr[j];
					visited[arr[j]] = true;
					counter++;
				}
			}

			printf("Number %d is being replaced.\n\n", furthest);
			page[furthest] = false;

			for(k = 0; k < NumberOfFrames; k++)
				if(frame[k] == furthest)
					break;

			frame[k] = arr[i];
			page[arr[i]] = true;
		}
		
		//Display current state
		ShowFrames(frame,index);
	}
	
	ShowData(pageFaults);
}

void LRUSolution(int arr[], int size, int NumberOfFrames) {
	//Variables
	bool page[PAGES] = {false};
	int pageFaults = 0;
	int i = 0;
	int index = 0;
	int frame[NumberOfFrames];
	int counter;
	int j;
	int k;
	int lru;

	for(i; i < size; i++) {
		if((index < NumberOfFrames) && (!page[arr[i]])){
			pageFaults++;
			frame[index++] = arr[i];
			page[arr[i]] = true;
		} else if((index >= NumberOfFrames) && (!page[arr[i]])) {
			pageFaults++;
			counter = 0;
			bool visited[PAGES] = {false};

			for(j = i - 1; ; j--) {
				if((counter == NumberOfFrames) || (j < 0))
					break;
				if((page[arr[j]]) && (!visited[arr[j]])) {
					lru = arr[j];
					visited[arr[j]] = true;
					counter++;
				}
			}

			printf("Number %d is being replaced.\n\n", lru);
			page[lru] = false;

			for(k = 0; k < NumberOfFrames; k++) {
				if(frame[k] == lru)
					break;
			}

			frame[k] = arr[i];
			page[arr[i]] = true;
		}

		ShowFrames(frame, index);
	}

	ShowData(pageFaults);
}

int main() {
	int NumberOfFrames = 0;
	printf("Please enter the number of frames you would like: ");
	scanf("%d",&NumberOfFrames);
	
	//Variables
	int i = 0;
	int arr[NumberOfFrames];
	bool page[PAGES] = {false};
	//int a[30];
	//for(i=0;i<30;i++){
	//	a[i]=rand()%PAGES;
	//}
	int a[MAX]=  { 2,3,5,1,5,5,4,4,3,5,1,1,2,3,2,2,1,3,3,2,2,5,3,4,3,3,2,2,4,1 };
	
	printf("Here is the reference string: ");
	ShowFrames(a, MAX);

	printf("\n");

	printf("-------------------------LRU Solution--------------------------\n");
	LRUSolution(a, MAX, NumberOfFrames);

	printf("------------------------Optimal Solution-----------------------\n");
	OptimalSolution(a, MAX, NumberOfFrames);

	printf("Check out how LRU differs from Optimal!\n");	
	
	return 0;
}
