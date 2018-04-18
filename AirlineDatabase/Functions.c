#include "Functions.h"

int displayMenu() {
	int choice;

	printf("\n---------------------------------------------------------------\n");
	printf("|1. Add a passenger                                           |\n");
	printf("|2. Display all passenger                                     |\n");
	printf("|3. Display passenger details                                 |\n");
	printf("|4. Update a passenger statistic                              |\n");
	printf("|5. Delete a passenger                                        |\n");
	printf("|6. Generate statistics                                       |\n");
	printf("|7. Print all passenger details into a report file            |\n");
	printf("|8. List all the passenger from UK in order of year born      |\n");
	printf("|-1. Exit                                                     |\n");
	printf("---------------------------------------------------------------");
	printf("\nPlease enter one of the following options: ");
	scanf("%d", &choice);

	return choice;
}

void inputPassenger(struct passenger* newNode) {
	char emailAddress[30];
	int emailValidate;

	printf("\nPlease enter the following:\n");
	printf("Passport Number: ");
	scanf("%d", &newNode->passportNum);
	printf("First Name: ");
	scanf("%s", newNode->firstName);
	printf("Second Name: ");
	scanf("%s", newNode->secondName);
	printf("Year Born: ");
	scanf("%d", &newNode->yearBorn);
	printf("Email Address: ");
	scanf("%s", emailAddress);
	emailValidate = validateEmail(emailAddress);
	while (emailValidate != 5) {
		printf("Invalid email address, must contain an '@' and '.com'\n");
		printf("Email Address: ");
		scanf("%s", emailAddress);
		emailValidate = validateEmail(emailAddress);
	}
	strcpy(newNode->email, emailAddress);
	newNode->region = regionMenu();
	newNode->travelClass = travelClassMenu();
	newNode->tripCount = tripCountMenu();
	newNode->duration = durationMenu();
}

int validateEmail(char email[30]) {
	int length = strlen(email);
	int valid = 0;


	for (int i = 0; i < length; i++) {
		if (email[i] == '@') {
			valid++;
			break;
		}
	}

	if (email[length - 4] == '.')
		valid++;

	if (email[length - 3] == 'c')
		valid++;

	if (email[length - 2] == 'o')
		valid++;

	if (email[length - 1] == 'm')
		valid++;

	return valid;
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

char* getRegion(int num) {
	char region[15];

	switch (num) {
		case 1:
			strcpy(region, "UK");
			break;
		case 2:
			strcpy(region, "Rest of Europe");
			break;
		case 3:
			strcpy(region, "Asia");
			break;
		case 4:
			strcpy(region, "Americas");
			break;
		case 5:
			strcpy(region, "Australasia");
			break;
		default:
			strcpy(region, "Others");
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

char* getTravelClass(int num) {
	char travelClass[16];

	switch (num) {
	case 1:
		strcpy(travelClass, "Economy");
		break;
	case 2:
		strcpy(travelClass, "Premium Economy");
		break;
	case 3:
		strcpy(travelClass, "Business Class");
		break;
	case 4:
		strcpy(travelClass, "First Class");
		break;
	default:
		strcpy(travelClass, "Others");
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

char* getTripCount(int num) {
	char tripCount[32];

	switch (num) {
	case 'a':
		strcpy(tripCount, "Less than three times per year");
		break;
	case 'b':
		strcpy(tripCount, "Less than five times per year");
		break;
	case 'c':
		strcpy(tripCount, "More than five times per year");
		break;
	default:
		strcpy(tripCount, "Others");
	}

	return tripCount;
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

char* getDuration(int num) {
	char duration[18];

	switch (num) {
	case 'a':
		strcpy(duration, "One day");
		break;
	case 'b':
		strcpy(duration, "Less than 3 days");
		break;
	case 'c':
		strcpy(duration, "Less than 7 days");
		break;
	case 'd':
		strcpy(duration, "More than 7 days");
		break;
	default:
		strcpy(duration, "Others");
	}

	return duration;
}
