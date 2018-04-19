#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Functions.h"
#include "Search.h"
#include "FileHandling.h"

// Node
struct passenger {
	int passportNum;
	char firstName[20];
	char secondName[20];
	int yearBorn;
	char email[30];
	int region;
	int travelClass;
	char tripCount;
	char duration;
	struct passenger* next;
	struct passenger* previous;
};

// Function prototypes
void addPassengerAtStart(struct passenger** top, struct passenger** bottom, struct passenger* newNode);
void addPassenger(struct passenger** top, struct passenger** bottom);
void displayList(struct passenger* top);
void displayIndexPassenger(struct passenger* top, int index);
int listLength(struct passenger* top);
void updatePassenger(struct passenger* top);
void deletePassenger(struct passenger** top, struct passenger** bottom);

#endif // !LINKEDLIST