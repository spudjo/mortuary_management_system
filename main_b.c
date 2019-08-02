/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Shawn
 *
 * Created on July 31, 2019, 10:42 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <time.h>

const int MAX_MORGUE_CAPACITY = 1000;
const int MAX_STRING_CAPACITY = 100;

char* remove_newline(char *string)
{
    int x;
    for(x = 0; x < MAX_STRING_CAPACITY; x++)
    {
        if( string[x] == '\n')
        {
            string[x] = '\0';
            break;
        }
    }
    return string;
}

typedef struct date
{
    int year;
    int month;
    int day;
}Date, *DatePtr;

typedef struct body
{
    int id;
    char* name;
    char sex;
    int age;
    DatePtr date_of_death;
    double weight;
    double height;
    char* cause_of_death; 
}Body, *BodyPtr;

/*
 * Create and return DatePtr
 */
DatePtr create_date(int year, int month, int day)
{
    DatePtr date = (DatePtr)malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

/*
 * Create and return BodyPtr
 */
Body create_body(int id, char name[], char sex, int age, 
                 int year, int month, int day, 
                 double weight, double height, char cause_of_death[])
{       
    Body body;
    body.id = id;
    strcpy(body.name, name);
    body.sex = sex;
    body.age = age;  
    body.date_of_death = create_date(year, month, day);  
    body.weight = weight;
    body.height = height;
    strcpy(body.cause_of_death, cause_of_death);
    return body;
}

Body create_body_empty(int id)
{
    Body body;
    body.id = id;
    body.name = calloc(MAX_STRING_CAPACITY, sizeof(char));
    body.cause_of_death = calloc(MAX_STRING_CAPACITY, sizeof(char));
    return body;
}


/*
 * Prints of DatePtr contents in YYYY-MM-DD format
 * Called from print_body_info
 */
void print_date(DatePtr date)
{
    printf("        | Date of Death: %d-%02d-%02d | ", date->year, date->month, date->day);
}

/*
 * Prints of BodyPtr contents
 */
void print_body_info(Body body)
{
    printf("ID: %05d | Name: %s\n", body.id, body.name);
    printf("        | Sex: %c | Age: %02d | Weight: %03.2lf KG | Height: %03.2lf CM\n", 
            body.sex, body.age, body.weight, body.height);
    print_date(body.date_of_death);
    printf("Cause of Death: %s\n", body.cause_of_death); 
}

/*
 * Print info on all bodies in collection
 */
void print_body_collection(BodyPtr body_collection)
{
    printf("\n=================================================================\n");
    printf("=                 B O D Y - C O L L E C T I O N                 =");
    printf("\n=================================================================\n");
    for (int i = 0; i < MAX_MORGUE_CAPACITY; i++)
    {
        if (body_collection[i].name != NULL)
        {
            print_body_info(body_collection[i]);
        }
    }
    printf("=================================================================\n");
}

/*
 * Allocate space in heap for body_collection
 */
BodyPtr create_body_collection(int size)
{
    BodyPtr body_collection = (BodyPtr*)calloc(size, sizeof(Body));
    return body_collection;
}

/*
 * Hash Function
 */
void add_to_collection(BodyPtr body_collection, Body body)
{
    body_collection[body.id] = body;
}

void set_body_name(BodyPtr body_collection, int id)
{
    printf("Enter Name: ");
    char *name;
    fgets(name, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    name = remove_newline(name);
//    printf("Variable: \n%s\n", name);
//    body_collection[id].name = name;
    strcpy(body_collection[id].name, name);
//    printf("Name: \n%s\n", body_collection[id].name);
//    printf("CoD: \n%s\n", body_collection[id].cause_of_death);
}

void set_body_sex(BodyPtr body_collection, int id)
{
    printf("Enter Sex: ");
    char sex = getchar();
    getchar();
    body_collection[id].sex = sex;
}

void set_body_age(BodyPtr body_collection, int id)
{
    printf("Enter Age: ");   
    int age;
    scanf("%d", &age);
    getchar();
    body_collection[id].age = age;
}

void set_body_date_of_death(BodyPtr body_collection, int id)
{
    printf("Enter Date of Death (Format: YYYY MM DD): ");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    getchar();
    body_collection[id].date_of_death = create_date(year, month, day);   
}

void set_body_weight(BodyPtr body_collection, int id)
{
    printf("Enter Weight: ");
    double weight;
    scanf("%lf", &weight);
    getchar();
    body_collection[id].weight = weight;
}

void set_body_height(BodyPtr body_collection, int id)
{
    printf("Enter Height: ");
    double height;
    scanf("%lf", &height);
    getchar(); 
    body_collection[id].height = height;
}

void set_body_cause_of_death(BodyPtr body_collection, int id)
{
    printf("Enter Cause of Death: ");
    char *cause_of_death;
    fgets(cause_of_death, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    cause_of_death = remove_newline(cause_of_death);
//    printf("Variable: \n%s\n", cause_of_death);
//    body_collection[id].cause_of_death = cause_of_death;
    strcpy(body_collection[id].cause_of_death, cause_of_death);
//    printf("Name: \n%s\n", body_collection[id].name);
//    printf("CoD: \n%s\n", body_collection[id].cause_of_death);
}

void update_body(BodyPtr body_collection)
{
    printf("\n=================================================================\n");
    printf("=                     E D I T - R E C O R D                     =");
    printf("\n=================================================================\n");
    printf("Enter ID of body to update: ");
    int id;
    scanf("%d", &id);
    getchar();
    
    // checks if ID exists in collection
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 0)
    {
        printf("ID not found!\n");
        return;
    }
    
    char select;
    while (select != 'q')
    {
        printf("Editing Record ID %d\n\n", id);
        printf("Select a value:\n");
        printf("Name: n   |   Sex: s   |   Age: a   |   Weight: w   |   Height: h\n");
        printf("Date of death: d   |   Cause of death: c\n");
        printf("Quit: q\n\n");
        printf("Selection: ");
 
        select = getchar();
        getchar();
        printf("\n");
        
        switch(select){
            case 'n':
                set_body_name(body_collection, id);
                break;
            case 's':
                set_body_sex(body_collection, id);
                break;
            case 'a':
                set_body_age(body_collection, id);
                break;
            case 'd':
                set_body_date_of_death(body_collection, id);
                break;
            case 'w':
                set_body_weight(body_collection, id);
                break;
            case 'h':
                set_body_height(body_collection, id);
                break;
            case 'c':
                set_body_cause_of_death(body_collection, id);
                break;		
	}
        printf("\n");
        print_body_info(body_collection[id]);
        printf("\n");
    }  
}

void add_body(BodyPtr body_collection)
{
    printf("\n=================================================================\n");
    printf("=                      A D D - R E C O R D                      =");
    printf("\n=================================================================\n");
    printf("Enter ID of new body: ");
    int id;
    scanf("%d", &id);
    getchar();
    
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 1)
    {
        printf("ID is currently being used");
        return;
    }
    
    Body body = create_body_empty(id);
    add_to_collection(body_collection, body);
    set_body_name(body_collection, id);
    set_body_sex(body_collection, id);
    set_body_age(body_collection, id);
    set_body_weight(body_collection, id);
    set_body_height(body_collection, id);
    set_body_date_of_death(body_collection, id);
    set_body_cause_of_death(body_collection, id);	  
}

/*
 * Checks if an ID is currently being used 
 * If so, return true, else return false indicating the ID is available
 */
int validate_existing_id(BodyPtr body_collection, int id)
{
    if (body_collection[id].name != NULL)
    {
        return 1;
    }
    return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    // array of Body structs
    BodyPtr body_collection = create_body_collection(MAX_MORGUE_CAPACITY);
    add_body(body_collection);
    print_body_collection(body_collection);
    add_body(body_collection);
    print_body_collection(body_collection);
    add_body(body_collection);
    print_body_collection(body_collection);
    update_body(body_collection);
    print_body_collection(body_collection);
    update_body(body_collection);
    print_body_collection(body_collection);
    update_body(body_collection);
    print_body_collection(body_collection);
    return (EXIT_SUCCESS);
}
