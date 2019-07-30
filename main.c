#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

// Mortuary Management System //
// Shawn, Steve Carino, Casey Byrne

//DATA STRUCTS
//bodies
typedef struct Body{
	int id;
	char * name;
	int age;
	int height;
	int weight;
}Body, *BodyPtr;

typedef struct node{
	BodyPtr data;
	struct node *next
}Node, *NodePtr;



//
//stack
//
//FUNCTIONS
//
//menu functions
//mainMenu()
void mainMenu();
//addMenu()
//
//editMenu()
//
//deleteMenu()
//
//searchMenu()
//
//quit()
void quit();

//file functions
//addRecord()
//
//editRecord()
//
//deleteRecord()
//
//search()

//readCSV()
//
//writeCSV()
//
//quickSort()
//
//DFTSearch()

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
			//add
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

void quit(){
	printf("\n\nExiting application, have a beautiful day.");
	exit(0);
}
