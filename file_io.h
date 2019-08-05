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
    char *string_ptr;
    
    char *name = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));
    char sex = 'X';
    int age = 0, year = 0, month = 0, day = 0;
    double weight = 0, height = 0;
    char *cause_of_death = (char*)calloc(MAX_STRING_CAPACITY, sizeof(char));

    char a[100];
    char b[200];

    if (input == NULL)
    {
        printf("ERROR: file does not exist.");
    }
    else
    {
        printf("File Found\n");
        
        while (fscanf(input, "%s", temp_string) == 1)
        {  
            
            name = strtok(temp_string, ",");
            strcpy(a, name);
            printf("Name: %s\n", name);
            fflush(stdin);

            sex = strtok(NULL , ",")[0];
            printf("Sex: %c\n", sex);
            
            age = atoi(strtok(NULL , ","));
            printf("Age: %d\n", age);
            
            year = atoi(strtok(NULL , ","));
            printf("Year: %d\n", year);
            
            month = atoi(strtok(NULL , ","));
            printf("Month: %d\n", month);
            
            day = atoi(strtok(NULL , ","));
            printf("Day: %d\n", day);
            
            weight = atof(strtok(NULL , ","));
            printf("Weight: %lf\n", weight);
            
            height = atof(strtok(NULL , ","));
            printf("Height: %lf\n", height);
                    
            cause_of_death = strtok(NULL , ",");
            strcpy(b, name);
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
            
            Body body = create_body(a, sex, age, year, month, day, weight, height, b, body_collection);
            add_to_collection(body_collection, body);
        }
    }
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

