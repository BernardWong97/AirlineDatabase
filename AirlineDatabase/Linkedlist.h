
#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdio.h>
#include <stdlib.h>

#include "Functions.h"

// Node
struct passenger {
	int passportNum;
	char firstName[20];
	char secondName[20];
	int yearBorn;
	char email[30];
	int region;
	int travelClass;
	int tripCount;
	int duration;
	struct passenger* next;
	struct passenger* previous;
};

// Function prototypes
int displayMenu();
void addPassengerAtStart(struct passenger** top);
void addPassengerAtEnd(struct passenger* top);
void displayList(struct passenger* top);
int listLength(struct passenger* top);
void deleteStudentAtEnd(struct passenger* top);
void searchStudent(struct passenger* top);
void deleteStudentAtStart(struct passenger** top);

#endif // !LINKEDLIST