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
    printf("*                        D E L E T E - R E C O R D                        *");
    printf("\n***************************************************************************\n");
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
    printf("*                          E D I T - R E C O R D                          *");
    printf("\n***************************************************************************\n");
    stars(1);
    printf("Enter ID of body to update: ");
    int id;
    Body temp_body;
    char select;
    scanf("%d", &id);
    getchar();
    printf("\n");
    
    // checks if ID exists in collection
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 0)
    {
        printf("Record not found!\n");
        return;
    }
    
    temp_body = body_collection[id];
    // end
    
    while (select != 'q' && select != 'x')
    {      
        printf("Editing the following record:\n");        
        printf("");
        print_body_info(temp_body);
        printf("\n");
        printf("Options:\n");
        printf("Name: n         Sex: s         Age: a         Weight: w         Height: h\n");
        printf("Date of death: d               Cause of death: c\n");
        printf("Quit and Save : q              Quit without Saving: x\n");
        printf("Selection: ");
 
        select = getchar();
        getchar();
        printf("\n");
        
        switch(select){
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
    
    if (select == 'q')
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
    printf("*                           A D D - R E C O R D                           *");
    printf("\n***************************************************************************\n");
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

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MENU_FUNCTIONS_H */

    