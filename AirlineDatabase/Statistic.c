// Statistic.c

#include "Statistic.h"

// generate statistic and either output to console or print into "report.txt"
void generateStatistics(struct passenger* top, int report) {
	int criteria;
	char s[18];

	if (report == 0) {
		FILE* fileptr = NULL;

		criteria = statisticMenu();

		switch (criteria) {
		case 1:
			strcpy(s, "Economy");
			break;
		case 2:
			strcpy(s, "Premium Economy");
			break;
		case 3:
			strcpy(s, "Business Class");
			break;
		case 4:
			strcpy(s, "First Class");
			break;
		case 5:
			strcpy(s, "Born Before 1980");
			break;
		default:
			printf("Error outputting criteria.\n"); // debug purpose
		} // switch criteria

		printf("\n==========Statistics From Criteria \"%s\"==========\n", s);
		calculateStatistics(criteria, top, report, fileptr);
	}
	else {
		printStatistics(top);
	} // if determine print to report or console
} // generateStatistics()

// calculate statistics base on criteria
void calculateStatistics(int criteria, struct passenger* top, int report, FILE* fileptr) {
	// if criteria is 5, criteria is "born beofer 1980"
	if (criteria >= 1 && criteria <= 4)
		travelStatistics(criteria, top, report, fileptr);
	else
		bornBeforeStatistics(top, report, fileptr);
} // calculateStatistics()

// calculate travel class statistics
void travelStatistics(int criteria,  struct passenger* top, int report, FILE* fileptr) {
	struct passenger* temp;
	int total = 0;
	int count;
	int ukCount = 0, RoECount = 0, asiaCount = 0, americasCount = 0, ausCount = 0;
	int oneDay = 0, threeDays = 0, sevenDays = 0, overSevenDays = 0;

	temp = top;

	for (int i = 0; i < listLength(top); i++) {
		if (temp->travelClass == criteria) {
			// count the passenger count needed for the statistics
			ukCount = fromUK(ukCount, temp);
			RoECount = fromRoE(RoECount, temp);
			asiaCount = fromAsia(asiaCount, temp);
			americasCount = fromAmericas(americasCount, temp);
			ausCount = fromAustralasia(ausCount, temp);
			oneDay = avgOneDay(oneDay, temp);
			threeDays = avgThreeDays(threeDays, temp);
			sevenDays = avgSevenDays(sevenDays, temp);
			overSevenDays = avgOverSeven(overSevenDays, temp);
			total++;
		} // if criteria has same integer as travel class

		temp = temp->next;
	} // for loop through the list

	for (int i = 0; i < 9; i++) {
		switch (i) {
		case 0:
			count = ukCount;
			break;
		case 1:
			count = RoECount;
			break;
		case 2:
			count = asiaCount;
			break;
		case 3:
			count = americasCount;
			break;
		case 4:
			count = ausCount;
			break;
		case 5:
			count = oneDay;
			break;
		case 6:
			count = threeDays;
			break;
		case 7:
			count = sevenDays;
			break;
		case 8:
			count = overSevenDays;
			break;
		default:
			printf("Error in calculating statistics.\n"); // debug purpose
		} // switch i for rows

		displayStatistics(i, count, total, report, fileptr);
	} // for loop 9 rows of statistics
} // travelStatistics()

void bornBeforeStatistics(struct passenger* top, int report, FILE* fileptr) {
	struct passenger* temp;
	int total = 0;
	int count;
	int ukCount = 0, RoECount = 0, asiaCount = 0, americasCount = 0, ausCount = 0;
	int oneDay = 0, threeDays = 0, sevenDays = 0, overSevenDays = 0;

	temp = top;

	for (int i = 0; i < listLength(top); i++) {
		if (temp->yearBorn < 1980) {
			// count the passenger count needed for the statistics
			ukCount = fromUK(ukCount, temp);
			RoECount = fromRoE(RoECount, temp);
			asiaCount = fromAsia(asiaCount, temp);
			americasCount = fromAmericas(americasCount, temp);
			ausCount = fromAustralasia(ausCount, temp);
			oneDay = avgOneDay(oneDay, temp);
			threeDays = avgThreeDays(threeDays, temp);
			sevenDays = avgSevenDays(sevenDays, temp);
			overSevenDays = avgOverSeven(overSevenDays, temp);
			total++;
		} // if passenger born before 1980

		temp = temp->next;
	} // for loop through the list

	for (int i = 0; i < 9; i++) {
		switch (i) {
		case 0:
			count = ukCount;
			break;
		case 1:
			count = RoECount;
			break;
		case 2:
			count = asiaCount;
			break;
		case 3:
			count = americasCount;
			break;
		case 4:
			count = ausCount;
			break;
		case 5:
			count = oneDay;
			break;
		case 6:
			count = threeDays;
			break;
		case 7:
			count = sevenDays;
			break;
		case 8:
			count = overSevenDays;
			break;
		default:
			printf("Error in calculating statistics.\n"); // debug purpose
		} // switch i for rows

		displayStatistics(i, count, total, report, fileptr);
	} // for loop 9 rows of statistics
} // bornBeforeStatistics()

// if passenger is from UK, return incremented counter or just return the counter if is not
int fromUK(int ukCount, struct passenger* temp) {
	if (temp->region == 1) {
		return ++ukCount;
	} // if
	return ukCount;
} // fromUK()

// if passenger is from Rest of Europe, return incremented counter or just return the counter if is not
int fromRoE(int RoECount, struct passenger* temp) {
	if (temp->region == 2) {
		return ++RoECount;
	} // if
	return RoECount;
} // fromRoE()

// if passenger is from Asia, return incremented counter or just return the counter if is not
int fromAsia(int asiaCount, struct passenger* temp) {
	if (temp->region == 3) {
		return ++asiaCount;
	} // if
	return asiaCount;
}  // fromAsia()

// if passenger is from Americas, return incremented counter or just return the counter if is not
int fromAmericas(int americasCount, struct passenger* temp) {
	if (temp->region == 4) {
		return ++americasCount;
	} // if
	return americasCount;
} // fromAmericas()

// if passenger is from UK, return incremented counter or just return the counter if is not
int fromAustralasia(int ausCount, struct passenger* temp) {
	if (temp->region == 5) {
		return ++ausCount;
	} // if
	return ausCount;
} // fromAustralasia()

// if passenger is staying one day, return incremented counter or just return the counter if is not
int avgOneDay(int oneDay, struct passenger* temp) {
	if (temp->duration == 'a') {
		return ++oneDay;
	} // if
	return oneDay;
} // avgOneDay()

// if passenger is staying average 3 days, return incremented counter or just return the counter if is not
int avgThreeDays(int threeDays, struct passenger* temp) {
	if (temp->duration == 'b') {
		return ++threeDays;
	} // if
	return threeDays;
} // avgThreeDays()

// if passenger is staying average 7 days, return incremented counter or just return the counter if is not
int avgSevenDays(int sevenDays, struct passenger* temp) {
	if (temp->duration == 'c') {
		return ++sevenDays;
	} // if
	return sevenDays;
} // avgSevenDays()

// if passenger is staying over 7 days, return incremented counter or just return the counter if is not
int avgOverSeven(int overSevenDays, struct passenger* temp) {
	if (temp->duration == 'd') {
		return ++overSevenDays;
	} // if
	return overSevenDays;
} // avgOverSeven()

// actual calculation and display the statistics
void displayStatistics(int i, int count, int total, int report, FILE* fileptr) {
	char s[45];
	float percentage;

	// percentage calculation
	percentage = (float)count / total * 100;

	switch (i) {
	case 0:
		strcpy(s, "travel from the UK");
		break;
	case 1:
		strcpy(s, "travel from the Rest of Europe");
		break;
	case 2:
		strcpy(s, "travel from the Asia");
		break;
	case 3:
		strcpy(s, "travel from the Americas");
		break;
	case 4:
		strcpy(s, "travel from the Australasia");
		break;
	case 5:
		strcpy(s, "spent on average one day in Ireland");
		break;
	case 6:
		strcpy(s, "spent on average less than 3 days in Ireland");
		break;
	case 7:
		strcpy(s, "spent on average less than 7 days in Ireland");
		break;
	case 8:
		strcpy(s, "spent on average more than 7 days in Ireland");
		break;
	default:
		printf("Error in outputting statistics.\n"); // debug purpose
	} // switch i for rows

	if (report == 1) {
		if (fileptr == NULL)
		{
			// output error
			printf("!- Warning -!\n");
			printf("!- The File \"report.txt\" Does Not Exist -!\n");
			printf("!- Warning -!\n");
		}
		else {
			fprintf(fileptr, "Percentage of passengers who %s : %.2f%%\n", s, percentage);
		} // if file pointer is NULL
	}
	else {
		printf("Percentage of passengers who %s : %.2f%%\n", s, percentage);
	} // if determine print to report file or console
} // displayStatistics()