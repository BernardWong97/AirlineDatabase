#ifndef STATISTICS
#define STATISTICS

#include "Passenger.h"

void generateStatistics(struct passenger* top);
void calculateStatistics(int criteria, struct passenger* top);
void travelStatistics(int criteria,  struct passenger* top);
void bornBeforeStatistics(struct passenger* top);
int fromUK(int ukCount, struct passenger* temp);
int fromRoE(int RoECount, struct passenger* temp);
int fromAsia(int asiaCount, struct passenger* temp);
int fromAmericas(int americasCount, struct passenger* temp);
int fromAustralasia(int ausCount, struct passenger* temp);
int avgOneDay(int oneDay, struct passenger* temp);
int avgThreeDays(int threeDays, struct passenger* temp);
int avgSevenDays(int sevenDays, struct passenger* temp);
int avgOverSeven(int overSevenDays, struct passenger* temp);
void displayStatistics(int i, int count, int total);
#endif