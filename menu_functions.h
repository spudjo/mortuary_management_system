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
#include "fsearch.h"
#include "menu_display.h"

//const int MAX_MORGUE_CAPACITY = 1000;
//const int MAX_STRING_CAPACITY = 100;

/*
 * Deletes Body in collection based on ID provided
 */
void delete_body(BodyPtr body_collection)
{
    printf("\n***************************************************************************\n");
<<<<<<< Updated upstream
    printf("*                        D E L E T E   M E N U                            *");
    printf("\n***************************************************************************\n");
=======
    printf("*                        D E L E T E   M E N U                            *\n");
>>>>>>> Stashed changes
    stars(1);
    // Takes in user input as a string then validates two things
    // 1) Checks that it is an interger (no letters)
    // 2) Checks that it is within the range of 0 and MAX_MORGUE_CAPACITY - 1
    // If either of these two conditions fail, program will loop until valid
    // input is given
    fflush(stdin);
    char *id_string = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    
    // variable that will hold 0 or 1 to signify if user input for id is valid
    int valid_entry;
    
    // loop for user input
    while (1)
    {
        valid_entry = 1;
        printf("Enter ID of body to update (0-%d): ", MAX_MORGUE_CAPACITY - 1);  
        fgets(id_string, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        id_string = remove_newline(id_string);
        
        // validate that input is an int between valid range
        valid_entry = is_valid_int(id_string, 0, MAX_MORGUE_CAPACITY - 1);
        
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
    id = atoi(id_string);;
    char *select = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));

    // check if id exists in hash table
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 0)
    {
        printf("\nRecord not found!\n");
        return;
    }
    
    printf("\nDelete the following record?\n");
    print_body_info(body_collection[id]);
    
    // deletion verification loop
    while (select[0] != 'Y' && select[0] != 'y' && select[0] != 'N' && select[0] != 'n')
    {
        printf("\nOptions: Y / N\n");
        printf("Selection: ");
        fgets(select, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        select = remove_newline(select);

        if (select[0] == 'Y' || select[0] == 'y')
        {
            printf("\nRecord deleted!\n");
            Body body = {};
            body_collection[id] = body;
        } 
        else if (select[0] == 'N' || select[0] == 'n')
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
    
    // variable that will hold 0 or 1 to signify if user input for id is valid
    int valid_entry;
    
    while (1)
    {
        valid_entry = 1;
        printf("Enter ID of body to update (0-%d): ", MAX_MORGUE_CAPACITY - 1);  
        fgets(id_string, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        id_string = remove_newline(id_string);
        
        // checks that user input is an integer between specified range
        valid_entry = is_valid_int(id_string, 0, MAX_MORGUE_CAPACITY - 1);
        
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
        stars(2);
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
        printf("\n");
        
        // check first character of user input
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
 */
void add_body(BodyPtr body_collection)
{
    printf("\n***************************************************************************\n");
    printf("*                              A D D   M E N U                            *\n");
    stars(1);
    
    // creates empty body and sets all fields based on validated user input
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
    
    // confirmation check loop, breaks when input is 'y' or 'n'
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

/*
 * Search for body in collection
 */
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
                break;
            case 'r':
                return;
        }
    }
}

<<<<<<< Updated upstream
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

=======
/*
 * Displays bodies in collection sorted by ID or name, in ascending or
 * descending order
 */
void display_body(BodyPtr body_collection)
{
    // Allocate an array with the number of records we have in hash table
    int arrSize = 0;
    arrSize = findSize(body_collection);
    
    // Temporary array to hold bodies without NULL bodies
    BodyPtr body_arr = (BodyPtr)calloc(arrSize, sizeof(Body));
    
    // At this point, body_arr contains all the bodies
    // from the main body_collection, minus any nulls
    // This array will be used in below sort functions
    body_arr = convert_to_body_array(body_collection);

    // variable to hold selection
    char *select = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));;
    
    // main program loop
    while(1) 
    {
        printf("\n***************************************************************************\n");
        printf("*                      D I S P L A Y   M E N U                            *\n");
        stars(1);
        printf("*  Display by ID:      Ascending: i     Descending: d                     *\n");
        printf("*  Display by name:    Ascending: a     Descending: z                     *\n");
        printf("*  Return: r                                                              *\n");
        stars(1);
        printf("Selection: ");
        fgets(select, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        select = remove_newline(select);
        
        // checks first character of input string
        switch(select[0]){
            case 'i':
                // display id ascending
                printf("\n");
                printf("Records by ID: Ascending\n");
                printf("****************************************\n");
                idQuickSort(body_arr, 0 , arrSize-1);
                printSorted(body_arr, arrSize);
                break;
            case 'd':
                // display id descending
                printf("\n");
                printf("Records by ID: Descending\n");
                printf("****************************************\n");
                idQuickSort(body_arr, 0 , arrSize-1);
                printSortedR(body_arr, arrSize);
                break;
            case 'a':
                // display name ascending
                nameQuickSort(body_arr, 0 , arrSize-1);
                printf("\n");
                printf("Records by Name: Ascending\n");
                printf("****************************************\n");
                printSorted(body_arr, arrSize);
                break;
            case 'z':
                // display name descending
                nameQuickSort(body_arr, 0 , arrSize-1);
                printf("\n");
                printf("Records by Name: Descending\n");
                printf("****************************************\n");
                printSortedR(body_arr, arrSize);
                break;
            case 'r':
                return;
                break;
        }      
    }
}
>>>>>>> Stashed changes

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* MENU_FUNCTIONS_H */

    