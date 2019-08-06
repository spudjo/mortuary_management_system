/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   file_io.h
 * Author: Shawn
 *
 * Created on August 4, 2019, 11:08 PM
 */

#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "data_structures.h"

const char *INPUT_FILE = "bodies.txt";
const char *OUTPUT_FILE = "output.txt";

BodyPtr readFromFile(BodyPtr body_collection)
{
    Body body = {};
    FILE *input = fopen(INPUT_FILE, "r");
    
    char temp_string[3 * MAX_STRING_CAPACITY];
    char *first_name;
//    char first_name[MAX_STRING_CAPACITY];
    char *last_name;
    char *full_name;
    char sex;
    int age, year, month, day;
    double weight, height;
    char *cause_of_death;
//    char cause_of_death[MAX_STRING_CAPACITY];
    

    // file not found
    if (input == NULL)
    {
        printf("ERROR: file does not exist.");
    }
    else
    {
//        printf("File Found\n");
        
        while (fgets(temp_string, "%s", input) != NULL)
        {    
            puts(temp_string);
            
            first_name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
            last_name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
            full_name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
            sex = 'X';
            
            age = year = month = day = 0;
            weight = height = 0;
            cause_of_death = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
            

            first_name = strtok(temp_string, ",");
//            fflush(stdin);
            sex = strtok(NULL , ",")[0];
            age = atoi(strtok(NULL , ","));
            year = atoi(strtok(NULL , ","));  
            month = atoi(strtok(NULL , ","));
            day = atoi(strtok(NULL , ","));
            weight = atof(strtok(NULL , ","));
            height = atof(strtok(NULL , ","));    
            cause_of_death = strtok(NULL , ",");

            printf("First Name: %s\n", first_name);
            printf("Last Name: %s\n", last_name);
            printf("Full Name: %s\n", full_name);
            printf("Sex: %c\n", sex);
            printf("Age: %d\n", age);
            printf("Year: %d\n", year);
            printf("Month: %d\n", month);
            printf("Day: %d\n", day);
            printf("Weight: %lf\n", weight);
            printf("Height: %lf\n", height);
            printf("COC: %s\n\n", cause_of_death); 
            fflush(stdin);
            
//            body = create_body_empty();
//            body.name = "hello";
//            body.sex = sex;
//            body.age = age;
//            body.date_of_death->year = year;
//            body.date_of_death->month = month;
//            body.date_of_death->day = day;
//            body.weight = weight;
//            body.height = height;
//            body.cause_of_death = "good bye";
//            body.id = generate_hash_code(body_collection, body);
            
            body = body = create_body_empty();
            body = create_body(first_name, sex, age, year, month, day, weight, height, cause_of_death, body_collection);
            print_body_info(body);
            add_to_collection(body_collection, body);
            print_body_collection(body_collection);
        }
    }
    print_body_collection(body_collection);
    return body_collection;
}

/*
 * Save contents of body_collection to output.txt
 */
void saveToFile(BodyPtr bodiesArray){
    FILE * output;
    output = fopen(OUTPUT_FILE, "w");
    for (int i = 0; i < MAX_MORGUE_CAPACITY; i++)
    {
        if (bodiesArray[i].name != NULL)
        {
//            print_body_info(bodiesArray[i]);
            fprintf(output, "%s,", bodiesArray[i].name);
            fprintf(output, "%c,", bodiesArray[i].sex);
            fprintf(output, "%d,", bodiesArray[i].age);
            fprintf(output, "%d,", bodiesArray[i].date_of_death->year);
            fprintf(output, "%d,", bodiesArray[i].date_of_death->month);
            fprintf(output, "%d,", bodiesArray[i].date_of_death->day);
            fprintf(output, "%.2lf,", bodiesArray[i].weight);
            fprintf(output, "%.2lf,", bodiesArray[i].height);
            fprintf(output, "%s\n", bodiesArray[i].cause_of_death);
        }
    }
    fclose(output);
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* FILE_IO_H */

