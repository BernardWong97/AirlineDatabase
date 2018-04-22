// FileHandling.h

#ifndef FILE_HANDLING
#define FILE_HANDLING

#include "Passenger.h"

// constants
#define LOGIN "login.txt"
#define PASSENGER "passenger.txt"
#define REPORT "report.txt"

// function prototypes
void initLinkedList(struct passenger** top, struct passenger** bottom);
void updateLinkedList(struct passenger* top);
int login();
void printReport(struct passenger* top);
void printStatistics(struct passenger* top);
#endif // FILE_HANDLING