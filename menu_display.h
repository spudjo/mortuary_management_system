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

#ifndef MENU_DISPLAY_H
#define MENU_DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "data_structures.h"
#include "menu_functions.h"
#include "fsort.h"
#include "file_io.h"

//
// Prints out introduction //
//
void print_introduction()
{
    printf("***************************************************************************\n");
    printf("*  ____   _           _            _    _                           _     *\n");
    printf("* / ___| | |_        / \\    _ __  | |_ | |__    ___   _ __   _   _ ( )___ *\n");
    printf("* \\___ \\ | __|      / _ \\  | '_ \\ | __|| '_ \\  / _ \\ | '_ \\ | | | ||// __|*\n");
    printf("*  ___) || |_  _   / ___ \\ | | | || |_ | | | || (_) || | | || |_| |  \\__ \\*\n");
    printf("* |____/  \\__|(_) /_/   \\_\\|_| |_| \\__||_| |_| \\___/ |_| |_| \\__, |  |___/*\n");
    printf("*  __  __               _                                    |___/        *\n");
    printf("* |  \\/  |  ___   _ __ | |_  _   _   __ _  _ __  _   _                    *\n");
    printf("* | |\\/| | / _ \\ | '__|| __|| | | | / _` || '__|| | | |                   *\n");
    printf("* | |  | || (_) || |   | |_ | |_| || (_| || |   | |_| |                   *\n");
    printf("* |_|  |_| \\___/ |_|    \\__| \\__,_| \\__,_||_|    \\__, |                   *\n");
    printf("*                                                |___/                    *\n");
    printf("***************************************************************************\n");
}

void print_random_image()
{
    srand(time(NULL));
    int number_of_images = 3;
    int random_number = rand() % number_of_images;

    
    switch(random_number){
        case 0:
            print_skull_bois();
            break;
        case 1:
            print_floaty_bois();
            break;
        case 2:
            print_rosy();
            break;
     }   
}

void print_skull_bois()
{
    printf("***************************************************************************\n");                
    printf("* (/_   .-.               ==.      .==     .-.                            *\n");       
    printf("*  \\\\, (o.o)               /,     ,/      (o.o)        Kimberley Byrne    *\n");       
    printf("*   ()  (=)               //     //        (n)         Steven Carino      *\n");         
    printf("*    \\\\.=\"=-.  (|/       ()     ()       .-=\"=-.  \\)   Shawn Pudjowargono *\n");     
    printf("*      ==|==\\\\,/          \\\\   //       // =T= \\\\,/                       *\n");         
    printf("*       ===  ()            \\\\ //       () ==|== ()                        *\n");
    printf("*       =.=                (OwO)        \\  =\"=                \\)/ .-.     *\n");
    printf("*      (OwO)____            =,=         /)(OwO)                /,(o,o)    *\n");                          
    printf("*       \\\\ ----()\\         =====          // \\\\               ()  (w)     *\n");
    printf("*        \\\\      `\\       .==I==.        //   \\\\       /_ ___  \\\\,=\",     *\n");                 
    printf("*         ()       \"==  //  (=)  \\\\     ()     ()      '-()-()   =/=\\\\    *\n");     
    printf("*        //            ()  (d'b)  ()     \\\\    ||       //\\\\||  ==== ()   *\n");      
    printf("*       '/              \\`  '-'  `/       \\'   '|      /`  \\\\|  =\"=  `|   *\n");               
    printf("*       \"==            /|\\       /\\\\    ==\"     \"==  ==\"    `(OwO)    '-- *\n");
    printf("***************************************************************************\n");
}

void print_floaty_bois()
{
    printf("***************************************************************************\n"); 
    printf("*               (                                (                        *\n"); 
    printf("*                )           )        (                   )               *\n"); 
    printf("*              (                       )      )           .---.           *\n"); 
    printf("*          )              (     .-\"\"-.       (        (  /     \\          *\n"); 
    printf("*         ( .-\"\"-.  (      )   / _  _ \\        )      )  |() ()|          *\n"); 
    printf("*          / _  _ \\   )        |(_\\/_)|  .---.   (       (_ 0 _)          *\n"); 
    printf("*          |(_)(_)|  ( .---.   (_ /\\ _) /     \\   .-\"\"-.  |xxx|           *\n"); 
    printf("*          (_ /\\ _)   /     \\   |v==v|  |<\\ />|  / _  _ \\ '---'           *\n"); 
    printf("*           |wwww|    |(\\ /)|(  '-..-'  (_ A _)  |/_)(_\\|                 *\n"); 
    printf("*           '-..-'    (_ o _)  )  .---.  |===|   (_ /\\ _)                 *\n"); 
    printf("*                      |===|  (  /     \\ '---'    |mmmm|                  *\n"); 
    printf("*                      '---'     |{\\ /}|          '-..-'                  *\n"); 
    printf("*                                (_ V _)                  Kimberley Byrne *\n"); 
    printf("*                                 |\"\"\"|                     Steven Carino *\n"); 
    printf("*                                 '---'                Shawn Pudjowargono *\n"); 
    printf("*                                                                         *\n");
    printf("***************************************************************************\n");
}

void print_rosy()
{
    printf("***************************************************************************\n");
    printf("*                                  ______                                 *\n");                     
    printf("*                               .-\"      \"-.                              *\n");
    printf("*                              /            \\            Kimberley Byrne  *\n");
    printf("*                             |              |             Steven Carino  *\n");
    printf("*                             |,  .-.  .-.  ,|        Shawn Pudjowargono  *\n");
    printf("*                        /\\   | )(__/  \\__)( |                            *\n");
    printf("*                      _ \\/   |/     /\\     \\|                            *\n");
    printf("*                     \\_\\/    (_     ^^     _)   .-==/~\\                  *\n");
    printf("*                    ___/_,__,_\\__|IIIIII|__/__)/   /{~}}                 *\n");
    printf("*                    ---,---,---|-\\IIIIII/-|---,\\'-' {{~}                 *\n");
    printf("*                               \\          /     '-==\\}/                  *\n");
    printf("*                                `--------`                               *\n");
    printf("***************************************************************************\n"); 
}

void rip_in_peace()
{
    printf("***************************************************************************\n");
    printf("*                        _________________________                        *\n");
    printf("*                       |\\ _____________________ /|                       *\n");
    printf("*                       | |_____________________| |                       *\n");
    printf("*   R E C O R D         |/_______________________\\|       A D D E D       *\n");
    printf("*                       /=========================\\                       *\n");
    printf("*                      '==========================='                      *\n");
    printf("*                       |  ~~       _|_        ~~ |                       *\n");
    printf("*                       |            |            |                       *\n");
    printf("*                       |_________________________|                       *\n");
    printf("***************************************************************************\n");
}

//
// Design templates //
// 
void stars(int i){
	//how many stars do you need?
	switch(i){
	case 3:
	printf("************************************* *************************************\n");
	case 2:
	printf("************************************* *************************************\n");
	case 1:
	printf("************************************* *************************************\n");
	}
}

//
// MENUS
//

// ADD MENU

void addMenu(BodyPtr body_collection){
    add_body(body_collection);
}

// EDIT MENU
void editMenu(BodyPtr body_collection){
    update_body(body_collection);
}

// DELETE MENU
void deleteMenu(BodyPtr body_collection){
    delete_body(body_collection);
}

void searchMenu(BodyPtr body_collection)
{
    search_body(body_collection);
}

void displayMenu(BodyPtr body_collection)
{
    // Allocate our array with the number of records we have
    int arrSize = 0;
    arrSize = findSize(body_collection);
    // Temporary array to hold bodies without NULL bodies
    BodyPtr body_arr = (BodyPtr)calloc(arrSize, sizeof(Body));
    // At this point, body_arr contains all the bodies
    // from the main body_collection, minus any nulls
    // This array will be used in below sort functions
    body_arr = convert_to_body_array(body_collection);
    
//    for (int i = 0; i < arrSize; i++)
//    {
//        print_body_info(body_arr[i]);
//    }
    
    // variable to hold selection
    char *select = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));;
    
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
        
        switch(select[0]){
            case 'i':
                // display id ascending
                idQuickSort(body_arr, 0 , arrSize-1);
                printSorted(body_arr, arrSize);
                break;
            case 'd':
                // display id descending
                idQuickSort(body_arr, 0 , arrSize-1);
                printSortedR(body_arr, arrSize);
                break;
            case 'a':
                // display id ascending
                nameQuickSort(body_arr, 0 , arrSize-1);
                printf("\n");
                printSorted(body_arr, arrSize);
                break;
            case 'z':
                // display id descending
                nameQuickSort(body_arr, 0 , arrSize-1);
                printf("\n");
                printSortedR(body_arr, arrSize);
                break;
            case 'r':
                return;
                break;
        }      
    }
}

// QUIT MENU
void quit(BodyPtr body_collection){
    saveToFile(body_collection);    // save to file
    printf("\nExiting application, have a beautiful day!\n");
    printf("(Press enter key to exit)");
    getchar();
    exit(0);
}

// MAIN MENU
void mainMenu(){
	char *select = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
        // create body_collection
        BodyPtr body_collection = create_body_collection(MAX_MORGUE_CAPACITY);
         
        // Generate bodies from input file
        // !!! CURRENTLY BROKEN !!!
        // Having issues with body.name and body.cause_of_death
        body_collection = readFromFile(body_collection);
        
        // start creating dummy data
//        Body body_A = create_body("Shawn Pudjowargono", 'M', 27, 1991, 9, 5, 111, 222, "Elephant stampede", body_collection);
//        Body body_B = create_body("Steven Carino", 'M', 30, 1989, 11, 22, 99, 88.5, "Crushed by piano", body_collection);
//        Body body_C = create_body("Casey Byrne", 'F', 26, 1992, 33, 44, 555, 666, "Misadventure", body_collection);
//        add_to_collection(body_collection, body_A);
//        add_to_collection(body_collection, body_B);
//        add_to_collection(body_collection, body_C);
        // end create dummy data
            
	stars(2);
        printf("*                     Welcome to St.Anthony's Mortuary                    *\n");
        stars(2);
        while (1)
        {
//            print_body_collection(body_collection);
            
            printf("\n***************************************************************************\n");
            printf("*                            M A I N   M E N U                            *\n");
            stars(1);
            printf("*  Add record: a             Edit record: e             Delete record: d  *\n");
            printf("*  Search records: s         Display records: i         Quit: q           *\n");
            stars(1);
            printf("Selection: ");
           
            
            fgets(select, MAX_STRING_CAPACITY, stdin); 
            fflush(stdin);      
            select = remove_newline(select);
            
            switch(select[0]){
                case 'a':
                    addMenu(body_collection);
                    break;
                case 'e':
                    editMenu(body_collection);
                    break;
                case 'd':
                    deleteMenu(body_collection);
                    break;
                case 's':
                    searchMenu(body_collection);
                    break;
                case 'i':
                    displayMenu(body_collection);
                    break;
                case 'q':
                    quit(body_collection);
            }      
        }
}



#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MENU_DISPLAY_H */
