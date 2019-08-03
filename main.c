#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

// Mortuary Management System //
// Shawn, Steve Carino, Casey Byrne
// Roles:
// Steven: Search, Menu Structure, View Details
// Casey: File I/O, Delete
// Shawn: Data Structure, Add, Update, Display All Records

// DATA STRUCTS
// bodies
typedef struct Body{
	int id;
	char * name;
	char sex;
	int age;
	double weight;
	double height;
	char* cause_of_death;
	// date date_of_death; 
}Body, *BodyPtr;

// Data Structure -> Hast Table
// Hash Function -> Add ASCII values, Division function -> Linear Probing for collision

// stack
typedef struct node{
	BodyPtr data;
	struct node *next;
}Node, *NodePtr;

// FUNCTIONS
//
// menu functions
void mainMenu();
void addMenu();
// editMenu()
// deleteMenu()
// searchMenu()
// displayMenu()
//
// quit()
void quit();
//for splitting up text for legibility
void stars(int i);

// file functions
void addRecord(char * name, int age, int weight, int height);
//
// editRecord()
//
// deleteRecord()
//
int search();
// sort()
void searchName(char * name);
//
//quick sort
void idQuickSort(BodyPtr arr, int low, int high);
int idPartition(BodyPtr arr, int low, int high);
void swap(BodyPtr a, BodyPtr b);
// readCSV()
//
// writeCSV()
void printRecords(BodyPtr arr);

int size = 10;

void main(int argc,int argv){
	//load Records
	
	//Call main menu:
	//BodyPtr body_collection = (BodyPtr*)calloc(size, sizeof(Body));
	BodyPtr aa = (BodyPtr )calloc(size, sizeof(Body));
	BodyPtr ab = aa;
	int j = 55;
	for(int i = 0; i < size; i++){
		j--;
		aa->id = j;
		printf("main: %d\n", aa->id);
		aa++;
	}
	aa--;
	
	printf("beginning and end ids: %d  %d", ab->id, aa->id);
	printRecords(ab);
	printf("\n\nSorted:");
	idQuickSort(ab, 0, size-1);
	printRecords(ab);

	//mainMenu();
}

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


void mainMenu(){
	char select;
	
	stars(2);
	printf("Welcome to St.Anthony's Mortuary\n");
	stars(1);
	printf("Options:\n");
	printf("Add record: a  Edit record: e  Delete record: d  Search records: s  Quit: q\n");
	scanf("%c", &select);
	
	switch(select){
		case 'a':
			addMenu();
		case 'e':
			//edit
		case 'd':
			//delete
		case 's':
			//search
		case 'q':
			quit();		
	}
}

void printRecords(Body * arr){
	BodyPtr temp = arr;
	
	for(int i = 0; i < size; i++){
	printf("\nID: %d", temp->id);
	temp++;
	}

}



void addMenu(){
	char name[50];
	int age = 0;
	int weight = 0;
	int height = 0;
	char confirm;

	printf("Add a Record\n");
	printf("Enter Name:\n");
	scanf("%s",&name);
	fflush(stdin);
	printf("Enter Age:\n");
	scanf("%d", &age);
	printf("Enter Weight at death:\n");
	scanf("%d", &weight);
	printf("Enter Height at death:\n");
	scanf("%d", &height);
	printf("\n");
	printf("File: %s Age: %d Weight: %d Height: %d\n", name, age, weight, height);
	printf("Save File? y/n \n");
	
	fflush(stdin);
	scanf("%c", &confirm);
	
	switch(confirm){
		case 'y':
			addRecord(name, age, weight, height);
			break;
		case 'Y':
			addRecord(name, age, weight, height);
			break;
		case 'n':
			addMenu();
			break;
		case 'N':
			addMenu();
			break;
	}
}

// array must have no gaps (convert hash table to array before adding)
void idQuickSort(BodyPtr arr, int low, int high){
	printf("low: %d high: %d", low, high);
	
	if (low < high){
		//pi is partition index
		int pi = idPartition(arr, low, high);
		idQuickSort(arr, low, pi-1);
		idQuickSort(arr, pi+1, high);
	}
}

int idPartition(BodyPtr arr, int low, int high){
	
	int pivot = &arr[high].id;
	int i = low;
	printf("partitioning low: %d", low);
	for (int j = low; j <= high-1; j++){
		if(arr[j].id <= pivot){
			printf("swapping");
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}

void swap(BodyPtr a, BodyPtr b){
	
	Body temp;
	
	temp.id = a->id;
	temp.name = a->name;
	temp.sex = a->sex;
	temp.age = a->age;
	temp.weight = a->weight;
	temp.height = a->height;
	temp.cause_of_death = a->cause_of_death;
	
	a->id = b->id;
	a->name = b->name;
	a->sex = b->sex;
	a->age = b->age;
	a->weight = b->weight;
	a->height = b->height;
	a->cause_of_death = b->cause_of_death;
	
	b->id = temp.id;
	b->name = temp.name;
	b->sex = temp.sex;
	b->age = temp.age;
	b->weight = temp.weight;
	b->height = temp.height;
	b->cause_of_death = temp.cause_of_death;
	}

void addRecord(char name[], int age, int weight, int height){
	char confirm;
	
	printf("File: %s Age: %d Weight: %d Height: %d\n", name, age, weight, height);
	fflush(stdin);
	
	//add the data into stack
	stars(1);
	printf("Add Successful!\n");
	stars(2);
	printf("Add Another? y/n \n");
	scanf("%c", &confirm);
	switch(confirm){
		case 'y':
			fflush(stdin);
			addMenu();
			break;
		case 'Y':
			fflush(stdin);
			addMenu();
			break;
		case 'n':
			fflush(stdin);
			mainMenu();
			break;
		case 'N':
			fflush(stdin);
			mainMenu();
			break;
	}
}

void quit(){
	printf("\n\nExiting application, have a beautiful day.");
	exit(0);
}

void stars(int i){
	//how many stars do you need?
	switch(i){
	case 3:
	printf("********** **********\n");
	case 2:
	printf("********** **********\n");
	case 1:
	printf("********** **********\n");
	}
}
