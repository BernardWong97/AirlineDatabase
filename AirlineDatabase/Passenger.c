// Passenger.c

#include "Passenger.h"

// prompt user input every details of the new passenger
void inputPassenger(struct passenger* newNode, struct passenger** top) {
	int passportNum;
	int passportValidate = 1;
	char emailAddress[30];
	int emailValidate = 0;

	printf("\nPlease enter the following:\n");
	printf("Passport Number: ");
	scanf("%d", &passportNum);

	// if headpointer is not NULL
	if (*top != NULL)
		passportValidate = validatePassport(passportNum, top);

	while (passportValidate != 1) {
		printf("Passport number already exists in the database, please try again.\n");
		printf("Passport Number: ");
		scanf("%d", &passportNum);
		passportValidate = validatePassport(passportNum, top);
	} // while passport validation

	newNode->passportNum = passportNum;
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
	} // while email validation

	strcpy(newNode->email, emailAddress);
	newNode->region = regionMenu();
	newNode->travelClass = travelClassMenu();
	newNode->tripCount = tripCountMenu();
	newNode->duration = durationMenu();
} // inputPassenger()

// prompt user update the details of the passenger
void updateDetails(struct passenger* temp) {
	char emailAddress[30];
	int emailValidate = 0;

	printf("\nPlease enter the following:\n");
	printf("Email Address: ");
	scanf("%s", emailAddress);
	emailValidate = validateEmail(emailAddress);

	while (emailValidate != 5) {
		printf("Invalid email address, must contain an '@' and '.com'\n");
		printf("Email Address: ");
		scanf("%s", emailAddress);
		emailValidate = validateEmail(emailAddress);
	} // while email validation

	strcpy(temp->email, emailAddress);
	temp->region = regionMenu();
	temp->travelClass = travelClassMenu();
	temp->tripCount = tripCountMenu();
	temp->duration = durationMenu();
} //updateDetails()

// check if the passport number is already exists in the database (return 1 if did not exists or 1 if exists)
int validatePassport(int passportNum, struct passenger** top) {
	struct passenger* temp;

	temp = *top;

	while (temp != NULL) {
		// return 0 if the passport number already exists
		if (passportNum == temp->passportNum)
			return 0;

		temp = temp->next;
	} // while iterate through linked list

	return 1;
} // validatePassport()

// check if the input contains the symbol '@' and ends with ".com" (return 5 if the email is good)
int validateEmail(char email[30]) {
	int length = strlen(email);
	int valid = 0;

	for (int i = 0; i < length; i++) {
		if (email[i] == '@') {
			valid++;
			break;
		} // if one of the character is '@' symbol
	} // for i

	// if ends with ".com"
	if (email[length - 4] == '.')
		valid++;

	if (email[length - 3] == 'c')
		valid++;

	if (email[length - 2] == 'o')
		valid++;

	if (email[length - 1] == 'm')
		valid++;

	// valid counter should increment to 5 if each condition is met, else the email cannot be use
	return valid;
} // validateEmail()

// return the string of the region (it is an integer in the database)
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
		strcpy(region, "Others"); // debug purpose
	} // switch num

	return region;
} // getRegion()

// return the string of the travel class (it is an integer in the database)
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
		strcpy(travelClass, "Others"); // debug purpose
	}

	return travelClass;
} // getTravelClass()

// return the string of the trip count (it is a character in the database)
char* getTripCount(char num) {
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
		strcpy(tripCount, "Others"); // debug purpose
	} // switch num

	return tripCount;
} // getTripCount()

// return the string of the duration (it is a character in the database)
char* getDuration(char num) {
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
		strcpy(duration, "Others"); // debug purpose
	} // switch num

	return duration;
} // getDuration()

