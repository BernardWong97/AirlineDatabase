#ifndef FILE_HANDLING
#define FILE_HANDLING

#include "Passenger.h"

#define LOGIN "login.txt"
#define PASSENGER "passenger.txt"
#define REPORT "report.txt"

void initLinkedList(struct passenger** top, struct passenger** bottom);
void updateLinkedList(struct passenger* top);
int login();
#endif