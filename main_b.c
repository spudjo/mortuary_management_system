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
    for(x = 0; x <= MAX_STRING_CAPACITY; x++)
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
//    strcpy(body.name, name);
    body.name = name;
    body.sex = sex;
    body.age = age;  
    body.date_of_death = create_date(year, month, day);  
    body.weight = weight;
    body.height = height;
    body.cause_of_death = cause_of_death;
//    strcpy(body.cause_of_death, cause_of_death);
    return body;
}

Body create_body_empty(int id)
{
    Body body;
    body.id = id;
    body.age = 0;
    body.sex = 'X';
    body.date_of_death = create_date(1111, 11, 11); 
    body.weight = 0;
    body.height = 0;
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
    printf("         | Date of Death: %d-%02d-%02d | ", date->year, date->month, date->day);
}

/*
 * Prints of BodyPtr contents
 */
void print_body_info(Body body)
{
    printf("ID: %04d | Name: %s\n", body.id, body.name);
    printf("         | Sex: %c | Age: %02d | Weight: %03.2lf KG | Height: %03.2lf CM\n", 
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

Body set_body_name(Body body)
{
    fflush(stdin);
    printf("Enter Name: ");
    char *name = calloc(MAX_STRING_CAPACITY, sizeof(char));
    fgets(name, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    name = remove_newline(name);
    body.name = name;
//    strcpy(body.name, name);
    fflush(stdin);
    return body;
}

Body set_body_sex(Body body)
{
    fflush(stdin);
    printf("Enter Sex: ");
    char sex = getchar();
    getchar();
    body.sex = sex;
    return body;
}

Body set_body_age(Body body)
{
    fflush(stdin);
    printf("Enter Age: ");   
    int age;
    scanf("%d", &age);
    getchar();
    body.age = age;
    return body;
}

Body set_body_date_of_death(Body body)
{
    fflush(stdin);
    printf("Enter Date of Death (Format: YYYY MM DD): ");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    getchar();
    body.date_of_death = create_date(year, month, day); 
    return body;
}

Body set_body_weight(Body body)
{
    fflush(stdin);
    printf("Enter Weight: ");
    double weight;
    scanf("%lf", &weight);
    getchar();
    body.weight = weight;
    return body;
}

Body set_body_height(Body body)
{
    fflush(stdin);
    printf("Enter Height: ");
    double height;
    scanf("%lf", &height);
    getchar(); 
    body.height = height;
    return body;
}

Body set_body_cause_of_death(Body body)
{
    fflush(stdin);
    printf("Enter Cause of Death: ");
    char *cause_of_death = calloc(MAX_STRING_CAPACITY, sizeof(char));
    fgets(cause_of_death, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    cause_of_death = remove_newline(cause_of_death);
    body.cause_of_death = cause_of_death;

//    body_collection[id].cause_of_death = cause_of_death;
    //strcpy(body.cause_of_death, cause_of_death);
    fflush(stdin);
    return body;
}

void delete_body(BodyPtr body_collection)
{
    printf("\n=================================================================\n");
    printf("=                   D E L E T E - R E C O R D                   =");
    printf("\n=================================================================\n");
    printf("Enter ID of body to delete: ");
    int id;
    Body temp_body;
    char select;
    scanf("%d", &id);
    getchar();
    
    int id_exists = validate_existing_id(body_collection, id);
    if (id_exists == 0)
    {
        printf("No record with ID of %04d", id);
        return;
    }
    
    printf("Delete the following record?\n");
    print_body_info(body_collection[id]);
    printf("\nOptions: Y / N");
    
    select = getchar();
    getchar();
    
    if (select == 'Y' || select == 'y')
    {
        body_collection[id] = create_body_empty(id);
    }
}

void update_body(BodyPtr body_collection)
{
    printf("\n=================================================================\n");
    printf("=                     E D I T - R E C O R D                     =");
    printf("\n=================================================================\n");
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
        printf("ID not found!\n");
        return;
    }
    
    temp_body = body_collection[id];
    
    while (select != 'q' && select != 'x')
    {      
        printf("Editing the following record:\n");        
        printf("");
        print_body_info(temp_body);
        
        
        
        printf("\n");
        printf("Select a value:\n");
        printf("Name: n   |   Sex: s   |   Age: a   |   Weight: w   |   Height: h\n");
        printf("Date of death: d   |   Cause of death: c\n");
        printf("Quit and Save : q   |   Quit without Saving: x\n\n");
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
        printf("\n");
    }  
    
    if (select == 'q')
    {
       body_collection[id] = temp_body; 
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
//    print_body_info(body);
    body = set_body_name(body);
//    print_body_info(body);
    body = set_body_sex(body);
//    print_body_info(body);
    body = set_body_age(body);
//    print_body_info(body);
    body = set_body_weight(body);
//    print_body_info(body);
    body = set_body_height(body);
//    print_body_info(body);
    body = set_body_date_of_death(body);
//    print_body_info(body);
    body = set_body_cause_of_death(body);
//    print_body_info(body);
    add_to_collection(body_collection, body);
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
    
    Body body_A = create_body(5, "Shawn Pudjowargono", 'M', 27, 1991, 9, 5, 111, 222, "Elephant stampeed");
    Body body_B = create_body(8, "Casey Byrne", 'F', 30, 1989, 11, 22, 99, 88.5, "Suicide by toaster");
    Body body_C = create_body(4, "Steve Carino", 'M', 26, 1992, 33, 44, 555, 666, "Suicide by toaster");
    
    add_to_collection(body_collection, body_A);
    add_to_collection(body_collection, body_B);
    add_to_collection(body_collection, body_C);
    print_body_collection(body_collection);
    
//    delete_body(body_collection);
    
    add_body(body_collection);
    print_body_collection(body_collection);
    
    update_body(body_collection);
    print_body_collection(body_collection);
    
    add_body(body_collection);
    print_body_collection(body_collection);
    
    update_body(body_collection);
    print_body_collection(body_collection);
    
    update_body(body_collection);
    print_body_collection(body_collection);
    
    
    
    return (EXIT_SUCCESS);
}