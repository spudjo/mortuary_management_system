/* 
 * File:   fsort.h
 * Author: Steven
 *
 * Created on August 3, 2019, 8:00 AM
 * For The Sort Functions
 */


#ifndef F_SORT
#define F_SORT


// array must have no gaps (convert hash table to array before adding)
void idQuickSort(BodyPtr arr, int low, int high){
	
	if (low < high){
		//pi is partition index
		int pi = idPartition(arr, low, high);
		idQuickSort(arr, low, pi-1);
		idQuickSort(arr, pi+1, high);
	}
}

int idPartition(BodyPtr arr, int low, int high){
	
	int pivot = arr[high].id;
	int i = low;
	printRecords(arr);
	for (int j = low; j <= high-1; j++){
		if(arr[j].id <= pivot){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	
	swap(&arr[i], &arr[high]);
	
	return i;
}

void swap(BodyPtr a, BodyPtr b){
	BodyPtr temp = (BodyPtr*)malloc(sizeof(Body));
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

#endif
