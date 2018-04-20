#ifndef MENU
#define MENU

#include "Menu.h"

int displayMenu();
void displayHeader();
void inputPassenger(struct passenger* newNode, struct passenger** top);
void updateDetails(struct passenger* temp);
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