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

// QUIT MENU
void quit(){
	printf("\nExiting application, have a beautiful day!\n");
        printf("(Press enter key to exit)");
        getchar();
        
	exit(0);
}

// MAIN MENU
void mainMenu(){
        print_introduction();
	char select = 'a';
        
        // create body_collection
        BodyPtr body_collection = create_body_collection(MAX_MORGUE_CAPACITY);
        // after this, program will read from a file and create bodies
        
        // start creating dummy data
        Body body_A = create_body("Shawn Pudjowargono", 'M', 27, 1991, 9, 5, 111, 222, "Elephant stampede", body_collection);
        Body body_B = create_body("Steven Carino", 'M', 30, 1989, 11, 22, 99, 88.5, "Crushed by piano", body_collection);
        Body body_C = create_body("Casey Byrne", 'F', 26, 1992, 33, 44, 555, 666, "Misadventure", body_collection);
        add_to_collection(body_collection, body_A);
        add_to_collection(body_collection, body_B);
        add_to_collection(body_collection, body_C);
        // end create dummy data
	
	stars(1);
//	printf("Welcome to St.Anthony's Mortuary\n");
        while (1)
        {
            printf("\n***************************************************************************\n");
            printf("*                            M A I N   M E N U                            *");
            printf("\n***************************************************************************\n");
            stars(1);
            printf("Options:\n");
            printf("Add record: a  Edit record: e  Delete record: d  Search records: s  Quit: q\n");
            printf("Selection: ");
            select = getchar();
            getchar();
            
            switch(select){
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
                        //search, right now it just displays all bodies
                    print_body_collection(body_collection);
                    break;
                case 'q':
                    quit();
                    return;
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
