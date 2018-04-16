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
	printf("Region: ");
	scanf("%d", &newNode->region);
	printf("Travel Class: ");
	scanf("%d", &newNode->travelClass);
	printf("Trip Count: ");
	scanf("%d", &newNode->tripCount);
	printf("Duration: ");
	scanf("%d", &newNode->duration);
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
