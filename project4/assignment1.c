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

void LRUSolution(int arr[], int size, int NumberOfFrames) {
	//Variables
	bool page[PAGES] = {false};
	int pageFaults = 0;
	int i;
	int index = 0;
	int frame[NumberOfFrames];
	int counter;
	int p;
	int opt;
	int lru;

	//For every page number in the reference string
	for(i = 0; i < size; i++) {
		//check if valid frame open and current page not present	
		if((index < NumberOfFrames) && (!page[arr[i]])){
			//Put page number in frame and mark value as true
			frame[index++] = arr[i];
			page[arr[i]] = true;

			//Increment page fault
			pageFaults++;

		}
		
		//Check if no valid frame and value not in page
		if((index >= NumberOfFrames) && (!page[arr[i]])) {
			//Variables
			counter = 0;
			bool visitedValue[PAGES] = {false};

			//Increment page fault for value not being present
			pageFaults++;

			//Check for least recently used ie previous page value
			for(p = i - 1; ; p--) {
				//First frame
				if((counter == NumberOfFrames) || (p < 0))
					break;

				//If page and it's not a previously visited page
				if((page[arr[p]]) && (!visitedValue[arr[p]])) {
					//Assign as lru and mark as true
					lru = arr[p];
					visitedValue[arr[p]] = true;
					counter++;
				}
			}

			//Print page number being replaced
			printf("Number %d is being replaced.\n\n", lru);
			page[lru] = false;

			//Loop through frames
			for(opt = 0; opt < NumberOfFrames; opt++) {
				if(frame[opt] == lru)
					break;
			}

			//Put page number into frame
			frame[opt] = arr[i];
			page[arr[i]] = true;
		}

		//Display the contents of the frames
		ShowFrames(frame, index);
	}

	//Calculate page faults and hits
	ShowData(pageFaults);
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
	int p;
	int opt;
	int furthest;

	//Loop through all of the pages in the reference string	
	for(i = 0; i < size; i++) {
		//Check if there is a valid frame and the current page is not present
		if((index < NumberOfFrames) && (!page[arr[i]])) {
			frame[index++] = arr[i];
			page[arr[i]] = true;

			//Increment page fault
			pageFaults++;
		}

		//Check if no valid frame and value not in page
		if((index >= NumberOfFrames) && (!page[arr[i]])) {
			//Variables
			counter = 0;
			bool visitedValue[PAGES] = {false};

			//Increment page fault
			pageFaults++;

			//Loop through the pages to check ahead
			for(p = i + 1; ; p++) {
				//Last frame
				if((counter == NumberOfFrames) || (p == size))
					break;
				
				//If next page present and has a page value
				if((page[arr[p]]) && (!visitedValue[arr[p]])) {
					furthest = arr[p];
					visitedValue[arr[p]] = true;
					counter++;
				}
				
			}

			//Display page being replaced
			printf("Number %d is being replaced.\n", furthest);
			page[furthest] = false;

			//Loop through frames 
			for(opt = 0; opt < NumberOfFrames; opt++)
				if(frame[opt] == furthest)
					break;

			//Put page number into frame
			frame[opt] = arr[i];
			page[arr[i]] = true;
		}
		
		//Display current state
		ShowFrames(frame, index);
	}
	
	//Display page faults/hits
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
	int a[30];
	for(i=0;i<30;i++){
		a[i]=rand()%5+1;
	}	
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
