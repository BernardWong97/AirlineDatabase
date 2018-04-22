// Passenger.h

#ifndef PASSENGER
#define PASSENGER

// import all the library needed for the whole project
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// import all the header files of the project
#include "Linkedlist.h"
#include "Menu.h"
#include "Search.h"
#include "FileHandling.h"
#include "Statistic.h"

// function prototypes
void inputPassenger(struct passenger* newNode, struct passenger** top);
void updateDetails(struct passenger* temp);
int validatePassport(int passportNum, struct passenger** top);
int validateEmail(char email[30]);
char* getRegion(int num);
char* getTravelClass(int num);
char* getTripCount(char num);
char* getDuration(char num);
#endif // PASSENGER