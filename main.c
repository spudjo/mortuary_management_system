#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

// Mortuary Management System //
// Shawn, Steve Carino, Casey Byrne

// DATA STRUCTS
// bodies
typedef struct Body{
	int id;
	char * name;
	int age;
	int weight;
	int height;
}Body, *BodyPtr;

// stack
typedef struct node{
	BodyPtr data;
	struct node *next
}Node, *NodePtr;

// FUNCTIONS
//
// menu functions
void mainMenu();
void addMenu();
// editMenu()
// deleteMenu()
// searchMenu()
//
// quit()
void quit();

// file functions
void addRecord(char * name, int age, int weight, int height);
//
// editRecord()
//
// deleteRecord()
//
// search()

// readCSV()
//
// writeCSV()
//
// quickSort()
//
// DFTSearch()

void main(int argc,int argv){
	//load Records
	
	//Call main menu:
	mainMenu();
}

void mainMenu(){
	
	char select;
	
	printf("Welcome to St.Anthony's Mortuary\n");
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

void addMenu(){
	char name[50];
	int age = 0;
	int weight = 0;
	int height = 0;
	char confirm;

	printf("Add a Record\n");
	printf("Enter Name:\n");
	scanf("%s",&name);
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

void addRecord(char name[], int age, int weight, int height){
	char confirm;
	
	printf("File: %s Age: %d Weight: %d Height: %d\n", name, age, weight, height);
	fflush(stdin);
	
	//add the data into stack
	
	printf("Add Successful!\n");
	printf("Add another: y/n \n");
	scanf("%c", &confirm);
	switch(confirm){
		case 'y':
			addMenu();
			break;
		case 'Y':
			addMenu();
			break;
		case 'n':
			mainMenu();
			break;
		case 'N':
			mainMenu();
			break;
	}
}

void quit(){
	printf("\n\nExiting application, have a beautiful day.");
	exit(0);
}
