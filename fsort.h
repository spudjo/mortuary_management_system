/* 
 * File:   fsort.h
 * Author: Steven
 *
 * Created on August 3, 2019, 8:00 AM
 * For The Sort Functions
 */

#ifndef F_SORT
#define F_SORT

#include "data_structures.h"

// Counts and returns number of bodies in main body_collection
int findSize(BodyPtr body_collection){
	int size = 0;
	for(int i = 0; i < MAX_MORGUE_CAPACITY; i++){
		 if (body_collection[i].name != NULL){
		 	size++;
    	}
	}
	return size;
}

BodyPtr convert_to_body_array(BodyPtr bodycollection){
	
	Stack bstack = (Stack) malloc (sizeof(StackType));
	bstack->top = -1;
	
	for(int i = 0; i < MAX_MORGUE_CAPACITY; i++){
		if(bodycollection[i].name != NULL){
			
			++(bstack->top);
			bstack->ST[bstack->top]=bodycollection[i].id; 
		}		
	}
	
	BodyPtr body_indexes = (BodyPtr) calloc (bstack->top+1, sizeof(Body));
	int index = 0;
	while(bstack->top > -1){
		body_indexes[index] = bodycollection[bstack->ST[bstack->top]];
		index++;
		--(bstack->top);
	}
	return body_indexes;
}

// swap function for all QSorts
void swap(BodyPtr a, BodyPtr b){
	
	BodyPtr temp = (BodyPtr)malloc(sizeof(Body));
	temp->id = a->id;
	temp->name = a->name;
	temp->sex = a->sex;
	temp->age = a->age;
	temp->weight = a->weight;
	temp->height = a->height;
	temp->cause_of_death = a->cause_of_death;
	
	a->id = b->id;
	a->name = b->name;
	a->sex = b->sex;
	a->age = b->age;
	a->weight = b->weight;
	a->height = b->height;
	a->cause_of_death = b->cause_of_death;
	
	b->id = temp->id;
	b->name = temp->name;
	b->sex = temp->sex;
	b->age = temp->age;
	b->weight = temp->weight;
	b->height = temp->height;
	b->cause_of_death = temp->cause_of_death;
	}

int idPartition(BodyPtr arr, int low, int high){
	
	int pivot = arr[high].id;
	int i = low;
	for (int j = low; j <= high-1; j++){
		if(arr[j].id <= pivot){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	
	swap(&arr[i], &arr[high]);
	
	return i;
}

// array must have no gaps (convert hash table to array before adding)
void idQuickSort(BodyPtr arr, int low, int high){
	
	if (low < high){
		//pi is partition index
		int pi = idPartition(arr, low, high);
		idQuickSort(arr, low, pi-1);
		idQuickSort(arr, pi+1, high);
	}
}


int namePartition(BodyPtr arr, int low, int high){
	
	int pivot = (int)arr[high].name[0];
	int i = low;
	for (int j = low; j <= high-1; j++){
		if((int)arr[j].name[0] < pivot){
			swap(&arr[i], &arr[j]);
			i++;
		}
		//if first letter is the same, check rest of the string
		else if((int)arr[j].name[0] == pivot){
			if(strcmp(arr[i].name,arr[high].name)<0){
			swap(&arr[i], &arr[j]);
			i++;
			}
		}
	}
	
	swap(&arr[i], &arr[high]);
	
	return i;
}

// array must have no gaps (convert hash table to array before adding)
void nameQuickSort(BodyPtr arr, int low, int high){
	
	if (low < high){
		//pi is partition index
		int pi = namePartition(arr, low, high);
		nameQuickSort(arr, low, pi-1);
		nameQuickSort(arr, pi+1, high);
	}
}


/*
	int search(Body * ab[], int sin){
	// if search returns -1 then index doesnt exist
	int index = -1;
	for(int i = 0; i < size; i++){
		if(ab[i]->id == sin){
			index = i;
			ab++;
		}
		else{
			ab++;
		}
	}
}
*/

#endif
