#include "Passenger.h"

int displayMenu() {
	int choice;

	printf("\n+-------------------------------------------------------------+\n");
	printf("|1. Add a passenger                                           |\n");
	printf("|2. Display all passenger                                     |\n");
	printf("|3. Display passenger details                                 |\n");
	printf("|4. Update a passenger statistic                              |\n");
	printf("|5. Delete a passenger                                        |\n");
	printf("|6. Generate statistics                                       |\n");
	printf("|7. Print all passenger details into a report file            |\n");
	printf("|8. List all the passenger from UK in order of year born      |\n");
	printf("|-1. Exit                                                     |\n");
	printf("+-------------------------------------------------------------+");
	printf("\nPlease enter one of the following options: ");
	scanf("%d", &choice);

	return choice;
}

void displayHeader() {
	printf("+============================================================+\n");
	printf("*                                                            *\n");
	printf("*     Welcome to XYZ Airport Passenger Statistic System      *\n");
	printf("*                                                            *\n");
	printf("+============================================================+\n");
}

int regionMenu() {
	int region;
	printf("Which of the following areas did you travel from (1-5):\n");
	printf("\t(1) UK\n");
	printf("\t(2) Rest of Europe\n");
	printf("\t(3) Asia\n");
	printf("\t(4) Americas\n");
	printf("\t(5) Australasia\n");
	printf("Please enter your region: ");
	scanf("%d", &region);

	while(region < 1 || region > 5) {
		printf("\nInvalid input, 1 to 5 only.\n");
		printf("Please enter your region: ");
		scanf("%d", &region);
	}

	return region;
}

int travelClassMenu() {
	int travelClass;
	printf("Which of the following travel class did you use to travel to Ireland (1-4):\n");
	printf("\t(1) Economy\n");
	printf("\t(2) Premium Economy\n");
	printf("\t(3) Business Class\n");
	printf("\t(4) First Class\n");
	printf("Please enter your travel class: ");
	scanf("%d", &travelClass);

	while(travelClass < 1 || travelClass > 4) {
		printf("\nInvalid input, 1 to 4 only.\n");
		printf("Please enter your travel class: ");
		scanf("%d", &travelClass);
	}

	return travelClass;
}

char tripCountMenu() {
	char travelClass;
	printf("How many trips to Ireland do you make per year (a/b/c):\n");
	printf("\t(a) Less than three times per year\n");
	printf("\t(b) Less than five times per year\n");
	printf("\t(c) More than five times per year\n");
	printf("Please enter a / b / c: ");
	scanf(" %c", &travelClass);

	while(!(travelClass == 'a' || travelClass == 'b' || travelClass == 'c')) {
		printf("\nInvalid input, a / b / c only.\n");
		printf("Please enter a / b / c: ");
		scanf(" %c", &travelClass);
	}

	return travelClass;
}

char durationMenu() {
	char duration;
	printf("On average how long is your duration (a/b/c/d):\n");
	printf("\t(a) One day\n");
	printf("\t(b) Less than 3 days\n");
	printf("\t(c) Less than 7 day\n");
	printf("\t(d) More than 7 day\n");
	printf("Please enter a / b / c / d: ");
	scanf(" %c", &duration);

	while(!(duration == 'a' || duration == 'b' || duration == 'c' || duration == 'd')) {
		printf("\nInvalid input, a / b / c / d only.\n");
		printf("Please enter a / b / c / d: ");
		scanf(" %c", &duration);
	}

	return duration;
}

int statisticMenu() {
	int criteria;
	printf("\nWhich of the following criteria do you wish to generate statistics from (1-2): \n");
	printf("\t(1) Travel Class\n");
	printf("\t(2) Born Before 1980\n");
	printf("Please enter criteria: ");
	scanf("%d", &criteria);

	while (!(criteria == 1 || criteria == 2)) {
		printf("\nInvalid input, 1 and 2 only.\n");
		printf("Please enter criteria: ");
		scanf("%d", &criteria);
	}

	if (criteria == 1)
		criteria = classCriteriaMenu();
	else
		criteria = 5;

	return criteria;
}

int classCriteriaMenu() {
	int classCriteria;
	printf("\nWhich travel class do you wish to generate statistics from (1-4):\n");
	printf("\t(1) Economy\n");
	printf("\t(2) Premium Economy\n");
	printf("\t(3) Business Class\n");
	printf("\t(4) First Class\n");
	printf("Please enter travel class criteria: ");
	scanf("%d", &classCriteria);

	while (classCriteria < 1 || classCriteria > 4) {
		printf("\nInvalid input, 1 to 4 only.\n");
		printf("Please enter criteria: ");
		scanf("%d", &classCriteria);
	}

	return classCriteria;
}