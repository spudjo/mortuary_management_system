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

const int MAX_CAPACITY = 100;

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
Body create_body(int id, char name[50], char sex, int age, int year, int month, int day, double weight, double height, char cause_of_death[50])
{       
    Body body;
    body.id = id;
    body.name = (char*)calloc(strlen(name), sizeof(char));
    strcpy (body.name, name);
    body.sex = sex;
    body.age = age;  
    body.date_of_death = create_date(year, month, day);  
    body.weight = weight;
    body.height = height;
    body.cause_of_death = (char*)calloc(strlen(cause_of_death), sizeof(char));
    strcpy (body.cause_of_death, cause_of_death);
    return body;
}

/*
 * Prints of DatePtr contents in YYYY-MM-DD format
 * Called from print_body_info
 */
void print_date(DatePtr date)
{
    printf("%d-%02d-%02d", date->year, date->month, date->day);
}

/*
 * Prints of BodyPtr contents
 */
void print_body_info(Body body)
{
    printf("%d | ", body.id);
    
    for (int i = 0; i < strlen(body.name); i++)
    {
        printf("%c", body.name[i]);
    }
    
    printf(" | %c | %d | ", body.sex, body.age);  
    
    print_date(body.date_of_death);
    
    printf(" | %.2lf kg | %.2lf cm| ", body.weight, body.height); 
    
    for (int i = 0; i < strlen(body.cause_of_death); i++)
    {
        printf("%c", body.cause_of_death[i]);
    }
    printf("\n");
}

void print_body_collection(BodyPtr body_collection)
{
    for (int i = 0; i < MAX_CAPACITY; i++)
    {
        if (body_collection[i].name != NULL)
        {
            printf("Body found at %d : ID = ", i);
            print_body_info(body_collection[i]);
        }
    }
}

BodyPtr create_body_collect(int size)
{
    BodyPtr body_collection = (BodyPtr*)malloc(size * sizeof(Body));
    return body_collection;
}

/*
 * Hash Function
 */
BodyPtr add_to_collection(BodyPtr body_collection, Body body)
{
    body_collection[body.id] = body;
}

/*
    int id;
    char* name;
    char sex;
    int age;
    DatePtr date_of_death;
    double weight;
    double height;
    char* cause_of_death; 
 
 */

/* Functions to updating Body fields*/
//
//void update_body_id(BodyPtr body_collection, int id, int new_int)
//{
//    body_collection[id].id = new_int;
//}

void update_body_name(BodyPtr body_collection, int id)
{
    printf("Enter Name: ");
    char* new_name[50];
    scanf("%s", new_name);
    fflush(stdin);
    strcpy(body_collection[id].name, new_name);    
}

void update_body_sex(BodyPtr body_collection, int id)
{
    printf("Enter Sex: ");
    char new_sex;
    scanf("%s", &new_sex);
    fflush(stdin);
    body_collection[id].sex = new_sex;
}

void update_body_age(BodyPtr body_collection, int id)
{
    printf("Enter Age: ");
    int new_age;
    scanf("%d", &new_age);
    fflush(stdin);
    body_collection[id].age = new_age;
}

void update_body_date_of_death(BodyPtr body_collection, int id)
{
    printf("Enter Date of Death (Format: YYYY MM DD): ");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    fflush(stdin);
    body_collection[id].date_of_death = create_date(year, month, day);   
}

void update_body_weight(BodyPtr body_collection, int id)
{
    printf("Enter Weight: ");
    int new_weight;
    scanf("%d", &new_weight);
    fflush(stdin); 
    body_collection[id].weight = new_weight;
}

void update_body_height(BodyPtr body_collection, int id)
{
    printf("Enter Height: ");
    int new_height;
    scanf("%d", &new_height);
    fflush(stdin); 
    body_collection[id].height = new_height;
}

void update_body_cause_of_death(BodyPtr body_collection, int id)
{
    printf("Enter Cause of Death: ");
    char* new_cause_of_death[50];
    scanf("%s", new_cause_of_death);
    fflush(stdin);  
    strcpy(body_collection[id].cause_of_death, new_cause_of_death);  
}

void update_body(BodyPtr body_collection)
{
    printf("Enter ID of body to update: ");
    int id;
    scanf("%d", &id);
    fflush(stdin);
    
    int id_exists = validate_existing_id(body_collection);
    
    if (id_exists == 0)
    {
        printf("No body exists with that ID");
        return;
    }
    printf("Editing Body %d\n", id);
    printf("Which value to edit?\n");
    printf("0: Name | 1: Sex | 2: Age | 3: Date of death | 4: Weight | 5: Height | 6: Cause of death\n");
    
    int change_value;
    scanf("%d", &change_value);
    fflush(stdin);
    
    switch(change_value){
		case 0:
                    update_body_name(body_collection, id);
                    break;
		case 1:
                    update_body_sex(body_collection, id);
                    break;
		case 2:
                    update_body_age(body_collection, id);
                    break;
		case 3:
                    update_body_date_of_death(body_collection, id);
                    break;
		case 4:
                    update_body_weight(body_collection, id);
                    break;
                case 5:
                    update_body_height(body_collection, id);
                    break;
                case 6:
                    update_body_cause_of_death(body_collection, id);
                    break;		
	}
}

void add_body(BodyPtr body_collection)
{
    printf("Enter ID of new body: ");
    int id;
    scanf("%d", &id);
    fflush(stdin);
    
    int id_exists = validate_existing_id(body_collection);
    
    if (id_exists == 1)
    {
        printf("ID is currently being used");
        return;
    }
    
    Body body;
    body.id = id;
    update_body_name(body_collection, id);
    update_body_sex(body_collection, id);
    update_body_age(body_collection, id);
    update_body_date_of_death(body_collection, id);
    update_body_weight(body_collection, id);
    update_body_height(body_collection, id);
    update_body_cause_of_death(body_collection, id);	  
}

/*
 * Checks if an ID is currently being used 
 * If so, return true, else return false indicating the ID is available
 */
int validate_existing_id(BodyPtr body_collection)
{
    for (int i = 0; i < MAX_CAPACITY; i++)
    {
        if (body_collection[i].name != NULL)
        {
            return 1;
        }
    }
    return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    // array of Body structs
    BodyPtr body_collection = create_body_collect(MAX_CAPACITY);
//    Body body_A = create_body(5, "Casey Byrne", 'M', 27, 2019, 8, 01, 56.5, 176.5, "Autoerotic Asphyxiation");
//    add_to_collection(body_collection, body_A);  
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
    return (EXIT_SUCCESS);
}