/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu_functions.h
 * Author: Shawn
 *
 * Created on August 3, 2019, 12:17 PM
 */

#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "data_structures.h"
#include "fsort.h"
#include "menu_display.h"

/*
 * Deletes Body in collection based on ID provided
 */
void delete_body(BodyPtr body_collection)
{
    printf("\n***************************************************************************\n");
    printf("*                        D E L E T E   M E N U                            *");
    stars(1);
    printf("Enter ID of body to delete: ");
    int id;
    Body temp_body;
    char select;
    scanf("%d", &id);
    getchar();
    
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 0)
    {
        printf("\nRecord not found!\n");
        return;
    }
    
    printf("\nDelete the following record?\n");
    print_body_info(body_collection[id]);
    
    while (select != 'Y' && select != 'y' && select != 'N' && select != 'n')
    {
        printf("\nOptions: Y / N\n");
        printf("Selection: ");
        select = getchar();
        getchar();

        if (select == 'Y' || select == 'y')
        {
            printf("\nRecord deleted!\n");
            Body body = {};
//            printf("Temp: %s\n", body.name);
            body_collection[id] = body;
//            printf("Collection: %s\n", body_collection[id].name);
        } 
        else if (select == 'N' || select == 'n')
        {
            printf("\nRecord will not be deleted\n");
        }
    }
}

/*
 * Updates a Body in collection
 * Creates a duplicate of Body based on ID to make changes to, then overwrites
 * Body in collection with duplicate upon user confirmation
 */
void update_body(BodyPtr body_collection)
{
    printf("\n***************************************************************************\n");
    printf("*                            E D I T   M E N U                            *\n");
    stars(1);

    // Takes in user input as a string then validates two things
    // 1) Checks that it is an interger (no letters)
    // 2) Checks that it is within the range of 0 and MAX_MORGUE_CAPACITY - 1
    // If either of these two conditions fail, program will loop until valid
    // input is given
    fflush(stdin);
    char *id_string = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_entry;
    while (1)
    {
        valid_entry = 1;
        printf("Enter ID of body to update (0-999): ");  
        fgets(id_string, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        id_string = remove_newline(id_string);
        
        valid_entry = is_valid_int(id_string, 0, 999);
        
        if (valid_entry == 0)
        {
            printf("Invalid Entry\n"); 
        }
        else
        {
            break;
        }
    }
    // End of input check
    
    int id;
    Body temp_body;
    char *select = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));;
    id = atoi(id_string);

    // checks if ID exists in collection
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 0)
    {
        printf("Record not found!\n");
        return;
    }
    temp_body = body_collection[id];
    // end
    
    while (select[0] != 'q' && select[0] != 'x')
    {      
        stars(1);
        printf("Editing the following record:\n");        
        printf("");
        print_body_info(temp_body);
        printf("\n");
        printf("Options:\n");
        printf("Name: n         Sex: s         Age: a         Weight: w         Height: h\n");
        printf("Date of death: d               Cause of death: c\n");
        printf("Quit and Save : q              Quit without Saving: x\n");
        printf("Selection: ");
 
        fgets(select, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        select = remove_newline(select);
        
        switch(select[0]){
            case 'n':
                temp_body = set_body_name(temp_body);
                break;
            case 's':
                temp_body = set_body_sex(temp_body);
                break;
            case 'a':
                temp_body = set_body_age(temp_body);
                break;
            case 'd':
                temp_body = set_body_date_of_death(temp_body);
                break;
            case 'w':
                temp_body = set_body_weight(temp_body);
                break;
            case 'h':
                temp_body = set_body_height(temp_body);
                break;
            case 'c':
                temp_body = set_body_cause_of_death(temp_body);
                break;		
	}
    }  
    
    if (select[0] == 'q')
    {
       body_collection[id] = temp_body; 
       printf("Record updated!\n");
       return;
    }  
    printf("Record will not be updated\n");
}

/*
 * Adds body to collection
 * TODO:
 * Confirmation before adding to collection
 */
void add_body(BodyPtr body_collection)
{
    printf("\n***************************************************************************\n");
    printf("*                              A D D   M E N U                            *\n");
    stars(1);
    
    Body body = create_body_empty();
    body = set_body_name(body);
    body = set_body_sex(body);
    body = set_body_age(body);
    body = set_body_weight(body);
    body = set_body_height(body);
    body = set_body_date_of_death(body);
    body = set_body_cause_of_death(body);
    body.id = generate_hash_code(body_collection, body);
    printf("\n");
    print_body_info(body);
    char select;
    
    while (select != 'Y' && select != 'y' && select != 'N' && select != 'n')
    {
        printf("\nSave this record?\n");
        printf("Options: Y / N\n");
        printf("Selection: ");
        
        select = getchar();
        getchar();

        if (select == 'y' || select == 'Y')
        {
            add_to_collection(body_collection, body);
            printf("\n");
            rip_in_peace();
        }
        else if (select == 'N' || select == 'n')
        {
            printf("\nRecord not saved...\n");
        }  
    } 
}


void search_body(BodyPtr body_collection)
{
    char *select = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    while(1)
    {
        printf("\n***************************************************************************\n");
        printf("*                        S E A R C H   M E N U                            *\n");
        stars(1);
        printf("*  Search by ID: i       Search by name: n                                *\n");
        printf("*  Return: r                                                              *\n");
        stars(1);
        printf("Selection: ");
        fgets(select, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        select = remove_newline(select);
        
        switch(select[0]){
            case 'i':
                search_by_id(body_collection);
                break;
            case 'n':
            	search_by_name(body_collection);
                break;
            case 'r':
                return;
        }
    }
}

void search_by_id(BodyPtr body_collection)
{
    int id;
    int valid_id;
    printf("\nEnter ID: ");
    scanf("%d", &id);
    getchar();
    valid_id = validate_existing_id(body_collection, id);

    if (valid_id == 1)
    {
        printf("\nRecord found!\n");
        print_body_info(body_collection[id]);
    }
    else
    {
        printf("\nNo matching record found!\n");
    }
}

void search_by_name(BodyPtr body_collection)
{
	//
	// Alphabetized tree search
	//
	printf("initing sze");
	int size = findSize(body_collection);
	BodyPtr body_arr = (BodyPtr)calloc(size, sizeof(Body));
	body_arr = convert_to_body_array(body_collection);
	// make a stack for every character in the alphabet
	printf("initing stack");
	StackType alphas[26];
	// initialize
	for(int i = 0; i < 26; i++){
		
	alphas[i].top = -1;
	
	printf("??");
	}
	printf("??");
	int fi;
	for(int i = 0; i < size; i++){
		if(body_collection[i].name !=NULL){
			fi = (int)body_collection[i].name[0] - 65;
			//get stack in alphas to input
			++(alphas[fi].top);
			alphas[fi].ST[alphas[fi].top]= body_collection[i].id; 
		}		
	}
	
	// Prompt for search terms
	
	char * name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
	char * tname = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    
	printf("\nEnter Name: ");
    scanf("%s", name);
    
    int key = (int)name[0] -65;
    int currid = 0;
    
    while(strcmp(tname, name)!=0 && alphas[key].top>-1){
    	currid = alphas[key].ST[alphas[key].top];
    	tname = body_collection[currid].name;
    	alphas[key].top--;
	}
	
	int valid_id = validate_existing_id(body_collection, currid);
	
    if (valid_id == 1)
    {
        printf("\nRecord found!\n");
        print_body_info(body_collection[currid]);
    }
    else
    {
        printf("\nNo matching record found!\n");
    }

}

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MENU_FUNCTIONS_H */

    
