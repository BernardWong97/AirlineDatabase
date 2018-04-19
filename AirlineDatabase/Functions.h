#ifndef FUNCTIONS
#define FUNCTIONS
	
#include <stdio.h>
#include <stdlib.h>

#include "Linkedlist.h"

int displayMenu();
void inputPassenger(struct passenger* newNode, struct passenger** top);
int validatePassport(int passportNum, struct passenger** top);
int validateEmail(char email[30]);
int regionMenu();
char* getRegion(int num);
int travelClassMenu();
char* getTravelClass(int num);
char tripCountMenu();
char* getTripCount(int num);
char durationMenu();
char* getDuration(int num);
#endif