#ifndef PASSENGER
#define PASSENGER
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "Linkedlist.h"
#include "Menu.h"
#include "Search.h"
#include "FileHandling.h"
#include "Statistic.h"

void inputPassenger(struct passenger* newNode, struct passenger** top);
void updateDetails(struct passenger* temp);
int validatePassport(int passportNum, struct passenger** top);
int validateEmail(char email[30]);
char* getRegion(int num);
char* getTravelClass(int num);
char* getTripCount(int num);
char* getDuration(int num);
#endif // !LINKEDLIST