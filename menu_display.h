/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu_display.h
 * Author: Steven
 *
 * Created on August 3, 2019, 2:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "data_structures.h"
#include "fsort.h"

#ifndef MENU_DISPLAY_H
#define MENU_DISPLAY_H

//
// Design templates //
// 
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

//
// MENUS
//

// ADD MENU

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
			//add the record
			break;
		case 'Y':
			//add the record
			break;
		case 'n':
			addMenu();
			break;
		case 'N':
			addMenu();
			break;
	}
}

// QUIT MENU
void quit(){
	printf("\n\nExiting application, have a beautiful day.");
	exit(0);
}

// MAIN MENU
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



#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MENU_DISPLAY_H */
