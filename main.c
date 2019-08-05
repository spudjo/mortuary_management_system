#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "data_structures.h"
#include "menu_functions.h"
#include "menu_display.h"
#include "fsort.h"

// Mortuary Management System //
// Shawn, Steve Carino, Casey Byrne
// Roles:
// Steven: Search, Menu Structure, View Details
// Casey: File I/O, Delete
// Shawn: Data Structure, Add, Update, Display All Records

void main(int argc,int argv){
        print_random_image();
        Sleep(3000);
        print_introduction();
	mainMenu();
        return (EXIT_SUCCESS);
        
}