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

//
// DATA VALIDATION: Functions used to validate input for setting data fields
//

/*
 * Replaces trailing newline character with '\0' and returns string
 */
char* remove_newline(char *string)
{
    for(int x = 0; x < MAX_STRING_CAPACITY; x++)
    {
        if( string[x] == '\n')
        {
            string[x] = '\0';
            break;
        }
    }
    return string;
}

/*
 * Takes in a char* and checks that consists of only numbers within a certain 
 * range
 * max  = max acceptable number
 * min  = min acceptable number
 * Returns 1 if valid number, else returns 0
 */
int is_valid_int(char *string, int min, int max)
{
    int valid_num = 1;

    // iterates through each character until finding a '\0' and checks 
    // that each character is a number, else sets valid_num to 0 and breaks
    for (int i = 0; i < MAX_STRING_CAPACITY && string[i] != '\0'; i++)
    {
        if (!isdigit(string[i]))
        {
            valid_num = 0;
            break;
        }
    }
    
    // checks for valid range of number
    if (valid_num == 1)
    {
        if (atoi(string) < min || atoi(string) > max)
        {
            valid_num = 0;
        }
    }
    
    return valid_num;
}

/*
 * Takes in a char* and checks that consists of only numbers within a certain 
 * range, takiing into account a single decimal point
 * max  = max acceptable number
 * min  = min acceptable number
 * Returns 1 if valid number, else returns 0
 */
int is_valid_decimal(char *string, float min, float max)
{
    int valid_num = 1;
    int number_of_decimals = 0;

    // iterates through each character until finding a '\0' and checks 
    // that each character is a number, else sets valid_num to 0 and breaks
    for (int i = 0; i < MAX_STRING_CAPACITY && string[i] != '\0'; i++)
    {
        if (!isdigit(string[i]))
        {
            if (string[i] != '.') 
            {
                valid_num = 0;
                break;
            }
            else
            {
                number_of_decimals++;
                if (number_of_decimals > 1)
                {
                    valid_num = 0;
                    break;
                }
            }
        }
    }
        
    // checks for valid range of number
    if (valid_num == 1)
    {
        if (atoi(string) < min || atoi(string) > max)
        {
            valid_num = 0;
        }
    }
    
    return valid_num;
}

/*
 * Checks to ensure there are no commas in a given string
 */
int is_valid_string(char *string)
{
    int valid_string = 1;

    // iterates through each character until finding a '\0' and checks 
    // that each character is not a comma, else sets valid_string to 0 and breaks
    for (int i = 0; i < MAX_STRING_CAPACITY && string[i] != '\0'; i++)
    {
        if (string[i] == ',')
        {
            valid_string = 0;
            break;
        }
    }

    return valid_string;
}

//
// DATA STRUCTURES: DATE, BODY
//

// Date Data Model
typedef struct date
{
    int year;
    int month;
    int day;
}Date, *DatePtr;

// Main Data Model
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

// Stack used for quick sort algorithm
typedef struct stack
{
int top; 
int ST[1000]; 
}StackType, *Stack;

/*
 *Hash Storing: Hash_function, quadratic_probing
 */
int generate_hash_code(BodyPtr body_collection, Body body)
{
    int hash_code = hash_function(body);
//    printf("%s Hash: %d\n", body.name, hash_code);
    hash_code = quadratic_probing(body_collection, hash_code);
    return hash_code;
}

/*
 * ASCII hash code generation
 */
int hash_function(Body body)
{
    int sum = 0;
<<<<<<< Updated upstream
    char *string = body.name;
//    printf("Hash Calculation %s Start:\n", string);
    while (*string != '\0')
=======
    strcpy(string, body.name);
    
    for (int i = 0; i < MAX_STRING_CAPACITY; i++)
>>>>>>> Stashed changes
    {
        sum += (int)*string;
//        printf("Sum: %d Char: %c Value: %d\n", sum, *string, (int)*string);
        *string++;
    }
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
    return sum % MAX_MORGUE_CAPACITY;
}

/*
 * Quadratic probing to handling collisions
 */
int quadratic_probing(BodyPtr body_collection, int hash_code)
{
    int counter = 1;
    int new_hash_code = hash_code;
<<<<<<< Updated upstream
//    printf("Checking Hash %d\n", new_hash_code);
    while(body_collection[new_hash_code].name != NULL)
=======
    while(body_collection[new_hash_code].name[0] != '\0')
>>>>>>> Stashed changes
    {
        new_hash_code = (hash_code + counter * counter) % MAX_MORGUE_CAPACITY;
        counter++;
    }
    return new_hash_code;
}

<<<<<<< Updated upstream
=======
/*
 *Hash Storing: Hash_function, quadratic_probing
 */
int generate_hash_code(BodyPtr body_collection, Body body)
{
    int hash_code = hash_function(body);
    hash_code = quadratic_probing(body_collection, hash_code);
    return hash_code;
}

>>>>>>> Stashed changes
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
Body create_body(char name[], char sex, int age, 
                 int year, int month, int day, 
                 double weight, double height, char cause_of_death[],
                 BodyPtr body_collection)
{       
    Body body;
    body.name = name;
    body.sex = sex;
    body.age = age;  
    body.date_of_death = create_date(year, month, day);  
    body.weight = weight;
    body.height = height;
    body.cause_of_death = cause_of_death;
    body.id = generate_hash_code(body_collection, body); // sets id based on hash code 
    return body;
}

/*
 * Creates and returns an empty Body
 */
Body create_body_empty()
{
    Body body;
    body.id = -1;
    body.age = 0;
    body.sex = 'X';
    body.date_of_death = create_date(0, 0, 0); 
    body.weight = 0;
    body.height = 0;
<<<<<<< Updated upstream
    body.name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    body.cause_of_death = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
=======
>>>>>>> Stashed changes
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
 * Adds body to body_collection based on id set through hash function
 */
void add_to_collection(BodyPtr body_collection, Body body)
{
    body_collection[body.id] = body;
}

/*
 * Sets value of name field in Body then returns
 */
Body set_body_name(Body body)
{
    fflush(stdin);
    char *name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_string;
    
    while(1)
    {
        valid_string = 1;
        printf("Enter name: ");
        fgets(name, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);
        name = remove_newline(name);
        valid_string = is_valid_string(name); // comma check
        
        if (valid_string == 0)
        {
            printf("Invalid entry: No commas allowed\n");
        }
        else
        {
            break;
        }

    }
    body.name = name;
    fflush(stdin);
    return body;
}

/*
 * Sets value of sex field in Body then returns
 */
Body set_body_sex(Body body)
{
    fflush(stdin);
    char *sex = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    while (1)
    {
        printf("Enter sex (m/f): ");  
        fgets(sex, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        // check for valid character
        if (sex[0] != 'm' && 
           sex[0] != 'M' && 
           sex[0] != 'f' && 
           sex[0] != 'F')
        {
            printf("Invalid entry: Please enter only (m)ale or (f)emale\n"); 
        }
        else
        {
            break;
        }
    }
    // convert to upper then set sex field
    body.sex =  toupper(sex[0]);
    return body;
}

/*
 * Sets value of age field in Body then returns
 */
Body set_body_age(Body body)
{
    fflush(stdin);
    char *age = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_entry;
    while (1)
    {
        valid_entry = 1;
        printf("Enter age: ");  
        fgets(age, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        age = remove_newline(age);
        
        valid_entry = is_valid_int(age, 1, 150);
        
        if (valid_entry == 0)
        {
            printf("Invalid entry: Please enter only integers between 1 and 150\n"); 
        }
        else
        {
            break;
        }
    }
    body.age = atoi(age);
    return body;
}

/*
 * Sets value of date_of_death field in Body then returns
 */
Body set_body_date_of_death(Body body)
{
//    fflush(stdin);
//    printf("Enter Date of Death (Format: YYYY MM DD): ");
//    int year, month, day;
//    scanf("%d %d %d", &year, &month, &day);
//    getchar();
    printf("Enter date of death:\n");
    printf("Valid Range: 1900-01-01 to 2200-12-31\n");
    int year = get_date("Year: ", 1900, 2200);
    int month = get_date("Month: ", 1, 12);
    int day = get_date("Day: ", 1, 31);
    body.date_of_death = create_date(year, month, day); 
    return body;
}

/*
 * Used to get valid year, month and day in set_body_date_of_death
 */
int get_date(char* prompt, int min, int max)
{
    fflush(stdin);
    char *date = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_entry;
    while (1)
    {
        valid_entry = 1;
        printf("%s", prompt);  
        fgets(date, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        date = remove_newline(date);
        
        valid_entry = is_valid_int(date, min, max);
        
        if (valid_entry == 0)
        {
            printf("Invalid entry: Please enter a valid date value\n"); 
        }
        else
        {
            break;
        }
    }
    return atoi(date);
}

<<<<<<< Updated upstream
=======
/*
 * Sets value of date_of_death field in Body then returns
 */
Body set_body_date_of_death(Body body)
{
    printf("Enter date of death:\n");
    printf("Valid Range: 1900-01-01 to 2200-12-31\n");
    int year = get_date("Year: ", 1900, 2200);
    int month = get_date("Month: ", 1, 12);
    int day = get_date("Day: ", 1, 31);
    body.date_of_death = create_date(year, month, day); 
    return body;
}

>>>>>>> Stashed changes
/*
 * Sets value of weight field in Body then returns
 */
Body set_body_weight(Body body)
{
    fflush(stdin);
    char *weight = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_entry;
    while (1)
    {
        valid_entry = 1;
        printf("Enter weight(KG): ");  
        fgets(weight, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        weight = remove_newline(weight);
        
        valid_entry = is_valid_decimal(weight, 1, 650);
        
        if (valid_entry == 0)
        {
            printf("Invalid entry: Please enter only decimals between 1 and 650\n"); 
        }
        else
        {
            break;
        }
    }
    body.weight = atof(weight);
    return body;
}

/*
 * Sets value of height field in Body then returns
 */
Body set_body_height(Body body)
{
fflush(stdin);
    char *height = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_entry;
    while (1)
    {
        valid_entry = 1;
        printf("Enter height(CM): ");  
        fgets(height, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);      
        height = remove_newline(height);
        
        valid_entry = is_valid_decimal(height, 1, 300);
        
        if (valid_entry == 0)
        {
            printf("Invalid entry: Please enter only decimals between 1 and 300\n"); 
        }
        else
        {
            break;
        }
    }
    body.height = atof(height);
    return body;
}

/*
 * Sets value of case_of_death field in Body then returns
 */
Body set_body_cause_of_death(Body body)
{
    fflush(stdin);
    char *cause_of_death = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    int valid_string;
    
    while(1)
    {
        valid_string = 1;
        printf("Enter cause of death: ");
        fgets(cause_of_death, MAX_STRING_CAPACITY, stdin); 
        fflush(stdin);
        cause_of_death = remove_newline(cause_of_death);
        valid_string = is_valid_string(cause_of_death); // comma check
        
        if (valid_string == 0)
        {
            printf("Invalid entry: No commas allowed\n");
        }
        else
        {
            break;
        }

    }
    body.cause_of_death = cause_of_death;
    fflush(stdin);
    return body;
}

<<<<<<< Updated upstream
/*
 * Checks if id exists in collection, if so, returns 1, else 0
 */
int validate_existing_id(BodyPtr body_collection, int id)
{
    if (body_collection[id].name != NULL)
    {
        // id already exists
//        printf("Id Exists");
        return 1;
    }
    return 0;
}

=======
>>>>>>> Stashed changes
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
    printf("************************************* *************************************\n");
    for (int i = 0; i < MAX_MORGUE_CAPACITY; i++)
    {
        if (body_collection[i].name != NULL)
        {
            print_body_info(body_collection[i]);
        }
    }
}

void printSorted(BodyPtr body_collection, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("ID: %04d | Name: %s\n", body_collection[i].id, body_collection[i].name);
    }
}

void printSortedR(BodyPtr body_collection, int size)
{
	for(int i = size-1; i >= 0; i--)
        {
            printf("ID: %04d | Name: %s\n", body_collection[i].id, body_collection[i].name);
	}
}

/*
 * Checks if id exists in collection, if so, returns 1, else 0
 */
int validate_existing_id(BodyPtr body_collection, int id)
{
    if (body_collection[id].name[0] != '\0')
    {
        // id already exists
        return 1;
    }
    return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* DATA_STRUCTURES_H */

