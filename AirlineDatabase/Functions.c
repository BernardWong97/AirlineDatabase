#include "Functions.h"

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
	while (emailValidate != 3) {
		printf("\nInvalid email address, must contain an '@' and '.com'\n");
		scanf("%s", emailAddress);
		validateEmail(emailAddress);
	}
	newNode->region = getRegion();
	newNode->travelClass = getTravelClass();
	newNode->tripCount = getTripCount();
	newNode->duration = getDuration();
}

int validateEmail(char email[30]) {
	int length = strlen(email);
	int valid = 0;


	for (int i = 0; i < length; i++) {
		if (email[i] == '@')
			valid++;
		if (email[i] == '.'
			&& email[i + 1] == 'c'
			&& email[i + 2] == 'o'
			&& email[i + 3] == 'm')
			valid++;
	}

	return valid;
}

int getRegion() {
	int region;
	printf("\nWhich of the following areas did you travel from (1-5):");
	printf("\t(1) UK\n");
	printf("\t(2) Rest of Europe\n");
	printf("\t(3) Asia\n");
	printf("\t(4) Americas\n");
	printf("\t(5) Australasia\n");
	printf("Please enter your region: ");
	scanf("%d", &region);

	if (region < 1 || region > 5) {
		printf("\nInvalid input, 1 to 5 only.\n");
		printf("Please enter your region: ");
		scanf("%d", &region);
	}

	return region;
}

int getTravelClass() {
	int travelClass;
	printf("\nWhich of the following travel class did you use to travel to Ireland (1-4):");
	printf("\t(1) Economy\n");
	printf("\t(2) Premium Economy\n");
	printf("\t(3) Business Class\n");
	printf("\t(4) First Class\n");
	printf("Please enter your travel class: ");
	scanf("%d", &travelClass);

	if (travelClass < 1 || travelClass > 5) {
		printf("\nInvalid input, 1 to 4 only.\n");
		printf("Please enter your travel class: ");
		scanf("%d", &travelClass);
	}

	return travelClass;
}

char getTripCount() {
	char travelClass;
	printf("\nHow many trips to Ireland do you make per year (a/b/c):");
	printf("\t(a) Less than three times per year\n");
	printf("\t(b) Less than five times per year\n");
	printf("\t(c) More than five times per year\n");
	printf("Please enter a / b / c: ");
	scanf(" %c", &travelClass);

	if (travelClass != 'a' || travelClass != 'b' || travelClass != 'c') {
		printf("\nInvalid input, a / b / c only.\n");
		printf("Please enter a / b / c: ");
		scanf(" %c", &travelClass);
	}

	return travelClass;
}

char getDuration() {
	char duration;
	printf("\nOn average how long is your duration (a/b/c/d):");
	printf("\t(a) One day\n");
	printf("\t(b) Less than 3 days\n");
	printf("\t(c) Less than 7 day\n");
	printf("\t(d) More than 7 day\n");
	printf("Please enter a / b / c / d: ");
	scanf(" %c", &duration);

	if (duration != 'a' || duration != 'b' || duration != 'c' || duration != 'd') {
		printf("\nInvalid input, a / b / c / d only.\n");
		printf("Please enter a / b / c / d: ");
		scanf(" %c", &duration);
	}

	return duration;
}
