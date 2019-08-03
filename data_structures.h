/* 
 * File:   data_structures.h
 * Author: Shawn
 *
 * Created on August 3, 2019, 11:59 AM
 */
 
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_MORGUE_CAPACITY = 1000;
const int MAX_STRING_CAPACITY = 100;

/*
 * Replaces trailing newline character with '\0' and returns string
 */
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

//
// DATA STRUCTURES: DATE, BODY
//

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

//
// Hash Storing: Hash_function, quadratic_probing
//

/*
 * ASCII hash code generation
 */
int hash_function(Body body)
{
    int sum;
    char *string = body.name;
    while (*string != '\0')
    {
        sum += (int)*string;
        *string++;
    }
    return sum % MAX_MORGUE_CAPACITY;
}

/*
 * Quadratic probing to handling collisions
 */
int quadratic_probing(BodyPtr body_collection, int hash_code)
{
    int counter = 1;
    int new_hash_code = hash_code;
    while(body_collection[new_hash_code].name != NULL)
    {
//        printf("Space taken, probing...\n");
        new_hash_code = (hash_code + counter * counter) % MAX_MORGUE_CAPACITY;
        counter++;
    }
    return new_hash_code;
}

//
// Body Functions
//

/*
 * Creates and returns DatePtr
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
 * Creates and returns Body based on parameters passed
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

/*
 * Creates and returns an empty Body with only ID set
 */
Body create_body_empty(int id)
{
    Body body;
    body.id = id;
    body.age = 0;
    body.sex = 'X';
    body.date_of_death = create_date(1234, 56, 78); 
    body.weight = 0;
    body.height = 0;
    body.name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    body.cause_of_death = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    return body;
}

/*
 * Allocate space in heap for body_collection and returns BodyPtr
 */
BodyPtr create_body_collection(int size)
{
    BodyPtr body_collection = (BodyPtr)calloc(size, sizeof(Body));
    return body_collection;
}

/*
 * Hash function
 * Generates a hash code with polynomial hash generation
 * Collisions are handled via Quadratic probing
 */
void add_to_collection(BodyPtr body_collection, Body body)
{
    int hash_code = hash_function(body);
//    printf("Hash Code: %d\n", hash_code);
    hash_code = quadratic_probing(body_collection, hash_code);
//    printf("Final Hash Code: %d\n", hash_code);
    body_collection[hash_code] = body;
}

/*
 * Sets value of name field in Body then returns
 * TODO:
 * Exception handling
 */
Body set_body_name(Body body)
{
    fflush(stdin);
    printf("Enter Name: ");
    char *name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    fgets(name, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    name = remove_newline(name);
    body.name = name;
//    strcpy(body.name, name);
    fflush(stdin);
    return body;
}

/*
 * Sets value of sex field in Body then returns
 * TODO:
 * Exception handling
 */
Body set_body_sex(Body body)
{
    fflush(stdin);
    printf("Enter Sex: ");
    char sex = getchar();
    getchar();
    body.sex = sex;
    return body;
}

/*
 * Sets value of age field in Body then returns
 * TODO:
 * Exception handling
 */
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

/*
 * Sets value of date_of_death field in Body then returns
 * TODO:
 * Exception handling
 */
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

/*
 * Sets value of weight field in Body then returns
 * TODO:
 * Exception handling
 */
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

/*
 * Sets value of height field in Body then returns
 * TODO:
 * Exception handling
 */
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

/*
 * Sets value of case_of_death field in Body then returns
 * TODO:
 * Exception handling
 */
Body set_body_cause_of_death(Body body)
{
    fflush(stdin);
    printf("Enter Cause of Death: ");
    char *cause_of_death = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    fgets(cause_of_death, MAX_STRING_CAPACITY, stdin); 
    fflush(stdin);
    cause_of_death = remove_newline(cause_of_death);
    body.cause_of_death = cause_of_death;

//    body_collection[id].cause_of_death = cause_of_death;
    //strcpy(body.cause_of_death, cause_of_death);
    fflush(stdin);
    return body;
}

/*
 * Checks if id exists in collection, if so, returns 1, else 0
 * Essential a linear seach function
 * TODO:
 * Linear is too simple, needs to change to be more complex
 */
int validate_existing_id(BodyPtr body_collection, int id)
{
    for (int i = 0; i < MAX_MORGUE_CAPACITY; i++)
    {
        if (body_collection[i].id == id)
        {
//            printf("\nFound\n");
//            printf("Returning...");
            return 1; // id exists
        }
    }
    return 0; // id does not exist
}

//
// Print functions
//


/*
 * Prints Date field values to standard output
 */
void print_date(DatePtr date)
{
    printf("         | Date of Death: %d-%02d-%02d\n", date->year, date->month, date->day);
}

/*
 * Prints Body field values to standard output
 */
void print_body_info(Body body)
{
    printf("ID: %04d | Name: %s\n", body.id, body.name);
    printf("         | Sex: %c | Age: %02d | Weight: %03.2lf KG | Height: %03.2lf CM\n", 
            body.sex, body.age, body.weight, body.height);
    print_date(body.date_of_death);
    printf("         | Cause of Death: %s\n", body.cause_of_death); 
}

/*
 * Print information on all bodies in collection to standard output
 * TODO:
 * The condition for printing, body.name == NULL, may need to be changed
 */
void print_body_collection(BodyPtr body_collection)
{
    printf("\n***************************************************************************\n");
    printf("*                      B O D Y   C O L L E C T I O N                      *");
    printf("\n***************************************************************************\n");
    for (int i = 0; i < MAX_MORGUE_CAPACITY; i++)
    {
        if (body_collection[i].name != NULL)
        {
            print_body_info(body_collection[i]);
        }
    }
}


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DATA_STRUCTURES_H */

