#include "Statistic.h"

void generateStatistics(struct passenger* top) {
	int criteria;
	char s[18];
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
		printf("Error outputting criteria.\n");
	}

	printf("\n==========Statistics From Criteria \"%s\"==========\n", s);
	calculateStatistics(criteria, top);
}

void calculateStatistics(int criteria, struct passenger* top) {
	if (criteria >= 1 && criteria <= 4)
		travelStatistics(criteria, top);
	else
		bornBeforeStatistics(top);
}

void travelStatistics(int criteria,  struct passenger* top) {
	struct passenger* temp;
	int total = 0;
	int count;
	int ukCount = 0, RoECount = 0, asiaCount = 0, americasCount = 0, ausCount = 0;
	int oneDay = 0, threeDays = 0, sevenDays = 0, overSevenDays = 0;

	temp = top;

	for (int i = 0; i < listLength(top); i++) {
		if (temp->travelClass == criteria) {
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
		}

		temp = temp->next;
	} // for

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
			printf("Error in calculating statistics.\n");
		}

		displayStatistics(i, count, total);
	}
}

void bornBeforeStatistics(struct passenger* top) {
	struct passenger* temp;
	int total = 0;
	int count;
	int ukCount = 0, RoECount = 0, asiaCount = 0, americasCount = 0, ausCount = 0;
	int oneDay = 0, threeDays = 0, sevenDays = 0, overSevenDays = 0;

	temp = top;

	for (int i = 0; i < listLength(top); i++) {
		if (temp->yearBorn < 1980) {
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
		}

		temp = temp->next;
	} // for

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
			printf("Error in calculating statistics.\n");
		}

		displayStatistics(i, count, total);
	}
}

int fromUK(int ukCount, struct passenger* temp) {
	if (temp->region == 1) {
		return ++ukCount;
	}
	return ukCount;
}

int fromRoE(int RoECount, struct passenger* temp) {
	if (temp->region == 2) {
		return ++RoECount;
	}
	return RoECount;
}

int fromAsia(int asiaCount, struct passenger* temp) {
	if (temp->region == 3) {
		return ++asiaCount;
	}
	return asiaCount;
}

int fromAmericas(int americasCount, struct passenger* temp) {
	if (temp->region == 4) {
		return ++americasCount;
	}
	return americasCount;
}

int fromAustralasia(int ausCount, struct passenger* temp) {
	if (temp->region == 5) {
		return ++ausCount;
	}
	return ausCount;
}

int avgOneDay(int oneDay, struct passenger* temp) {
	if (temp->duration == 'a') {
		return ++oneDay;
	}
	return oneDay;
}

int avgThreeDays(int threeDays, struct passenger* temp) {
	if (temp->duration == 'b') {
		return ++threeDays;
	}
	return threeDays;
}

int avgSevenDays(int sevenDays, struct passenger* temp) {
	if (temp->duration == 'c') {
		return ++sevenDays;
	}
	return sevenDays;
}

int avgOverSeven(int overSevenDays, struct passenger* temp) {
	if (temp->duration == 'd') {
		return ++overSevenDays;
	}
	return overSevenDays;
}

void displayStatistics(int i, int count, int total) {
	char s[45];
	float percentage;

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
		printf("Error in outputting statistics.\n");
	}

	printf("Percentage of passengers who %s : %.2f%%\n", s, percentage);
}