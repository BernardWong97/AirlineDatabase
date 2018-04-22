// Search.c

#include "Search.h"

// search the passenger using either passport number of full name (return the index of the passenger found in the list or -1 if not found)
int searchPassenger(struct passenger* top) {
	int choice;
	int index;

	printf("\nWhich do you wish to search by:\n");
	printf("(1) Passport Number\n");
	printf("(2) Full Name\n");
	printf("Please enter your choice: ");
	scanf("%d", &choice);

	while (!(choice == 1 || choice == 2)) {
		printf("Invalid input, 1 or 2 only.\n");
		printf("Please enter your choice: ");
		scanf(" %d", &choice);
	} // while validation

	if (choice == 1) {
		index = passportSearch(top);
	}
	else {
		index = nameSearch(top);
	} // if determine using passport number or name for searching

	return index;
} // searchPassenger()

// search passenger by passport number (return the index if found and -1 if not found)
int passportSearch(struct passenger* top) {
	struct passenger* temp;
	int passportNum;
	int found = 0;
	int count = 0;

	temp = top;

	printf("\nPlease enter passport number: ");
	scanf("%d", &passportNum);

	for (int i = 0; i < listLength(top); i++) {
		if (temp->passportNum == passportNum) {
			// stop the loop
			i = listLength(top);
			found = 1;
		}
		else {
			// continue the iteration
			temp = temp->next;
			count++;
		} // if passport number matches
	} // for iterate through the list

	if (found == 1) {
		displayIndexPassenger(top, count);
		return count;
	}
	else {
		printf("The passenger does not exist in the database.\n");
	} // if found passenger

	return -1;
} // passportSearch()

// search passenger by first and second name (return the index if found and -1 if not found)
int nameSearch(struct passenger* top) {
	struct passenger* temp;
	char sFirstName[20];
	char sSecondName[20];
	char sFullName[40];
	char firstName[20];
	char secondName[20];
	char fullName[40];
	int found = 0;
	int count = 0;

	temp = top;

	printf("\nPlease enter first name: ");
	scanf("%s", sFirstName);
	printf("Please enter second name: ");
	scanf("%s", sSecondName);
	strcpy(sFullName, strcat(sFirstName, sSecondName));

	for (int i = 0; i < listLength(top); i++) {
		strcpy(firstName, temp->firstName);
		strcpy(secondName, temp->secondName);
		strcpy(fullName, strcat(firstName, secondName));

		if (strcmp(fullName, sFullName) == 0) {
			// stop the loop
			found = 1;
			i = listLength(top);
		}
		else {
			// continue the iteration
			temp = temp->next;
			count++;
		} // if full name match
	} // for iterate through the list

	if (found == 1) {
		displayIndexPassenger(top, count);
		return count;
	}
	else {
		printf("The passenger does not exist in the database.\n");
	} // if passenger found

	return -1;
} // nameSearch()