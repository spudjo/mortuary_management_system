/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   search_functions.h
 * Author: Shawn
 *
 * Created on August 6, 2019, 1:23 PM
 */

#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H

#include "data_structures.h"

/*
 * Search by id and prints details if exists
 * User enters an interger that is validated by range
 * This int is used to check the hash table for an existing record
 * If record exists, displays Body data
 */
void search_by_id(BodyPtr body_collection)
{   
    fflush(stdin);
    char *id_string = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_entry;
    while (1)
    {
        valid_entry = 1;
        printf("Enter ID (0-999): ");  
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
    id = atoi(id_string);;
    int valid_id = validate_existing_id(body_collection, id);

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

/*
 * Search by name
 * Creates 26-dimensional stack tree, each tree containing all records
 * organized by first letter (A is stack 0, B is stack 1, etc)
 * User enters a name which is then verified as containing all alphas or spaces
 * For character in name input is then used to check appropriate stack for
 * a valid Body record
 * If no matching name is found, all bodies with the same first letter are 
 * printed instead
 */
void search_by_name(BodyPtr body_collection)
{
    //
    // Alphabetized tree search
    // 
    int size = findSize(body_collection);
    BodyPtr body_arr = (BodyPtr)calloc(size, sizeof(Body));
    body_arr = convert_to_body_array(body_collection);
    // make a stack for every character in the alphabet
    StackType alphas[26];
    // initialize
    for(int i = 0; i < 26; i++)
    {	
        alphas[i].top = -1;	
    }
    int fi;
    for(int i = 0; i < MAX_MORGUE_CAPACITY; i++)
    {
        if(validate_existing_id(body_collection, i)==1)
        {
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

    fflush(stdin);
    fgets(name, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    strcpy(name, remove_newline(name));

    // checks if character is a letter
    int is_alpha = 1;

    for (int i = 0; i < MAX_STRING_CAPACITY && name[i] != '\0'; i++)
    {
        is_alpha = isalpha(name[i]);
        if (is_alpha == 0 && name[i] != ' ')
        {
            break;
        }
    }
    /// end alpha check

    if (is_alpha == 0)
    {
        printf("Invalid entry: Please only enter alphabets\n");
        return;
    }

    name[0] = toupper(name[0]);

    int key = (int)name[0] -65;
    int currid;
    int curr = alphas[key].top;

    while((strcmp(tname, name) != 0) && curr >= 0)
    {

        currid = alphas[key].ST[curr];
        strcpy(tname,body_collection[currid].name);
        curr--;
    }

    int valid_id = validate_existing_id(body_collection, currid);
    int comp = strcmp(tname, name);
    if (valid_id == 1 && comp == 0)
    {
        printf("\nRecord found!\n");
        print_body_info(body_collection[currid]);
    }
    else
    {
        printf("\nNo matching record found!\n");

        if(alphas[key].top>-1)
        {
            printf("\nDid you mean one of these?\n");
            for (int i = 0; i < alphas[key].top;i++)
            {
                print_body_info(body_collection[alphas[key].ST[i]]);
            }
        }
    }
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* SEARCH_FUNCTIONS_H */

