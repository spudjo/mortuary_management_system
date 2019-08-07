Usage:

	Execute the following executable:
	mortuary_management_system\dist\Debug\Cygwin-Windows\mortuary_management_system.exe

Source files:

	main.c
		Contains main method which starts program

Header Files:

	data_structures.h
		Contains code related to data structures and models (Body and Date)	

	file_io.h
		Contains code related to file i/o functionality

	fsearch.h
		Contains code related to search functionality

	fsort.h
		Contains code related to sort functionality

	menu_display.h
		Contains code related to the main menu
		
	menu_functions.h
		Contains code related to menu functionality (Add, Edit, Delete, Search, Display, Quit)
		
Other Files:

	bodies.txt
		Contains information for Body Data Model (CSV)
		
Data Structures:
	
	Arrays
	Stacks
	Trees
	Hash Tables
	
Data Models:

	typedef struct body
	{
		int id;
		char name[1000];
		char sex;
		int age;
		DatePtr date_of_death;
		double weight;
		double height;
		char cause_of_death[1000]; 
	}Body, *BodyPtr;
		
	typedef struct date
	{
		int year;
		int month;
		int day;
	}Date, *DatePtr;
		
Main Functionality:

	> File Input
	---
	> Add record
	> Edit record
	> Delete record
	> Search records
		> Search by ID
		> Search by name
	> Display records
		> Display by ID
			> Ascending
			> Descending
		> Display by name
			> Ascending
			> Descending
	> Quit
	---
	> File Output
	
Menu Flow:
	
	// Every menu is contained in a while(true) loop that will loop forever until
	// certain conditions are met with a switch case, either returning or 
	// jumping to other menus
	while(1)
	{
		// Get input string using fgets and check the first character 
		// for menu options in switch case
		switch(string[0]){
			case 'a':
				addMenu();
				break;
			case 'e':
				editMenu();
				break;
			case 'd':
				deleteMenu();
				break;
			case 's':
				searchMenu();
				break;
			case 'i':
				displayMenu();
				break;
			case 'q':
				quit(body_collection);
		}
	}

Easter Eggs:

	main_display.h > void print_random_image()
		This function generates a random number between 0 and 2 and, using a 
		switch case, prints out one of there ASCII art images upon program
		execution