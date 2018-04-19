#include "Search.h"

void searchPassenger(struct passenger* top) {
	int choice;

	printf("\nWhich do you wish to search by:\n");
	printf("(1) Passport Number\n");
	printf("(2) First Name\n");
	printf("Please enter your choice: ");
	scanf("%d", &choice);

	while (!(choice == 1 || choice == 2)) {
		printf("Invalid input, 1 and 2 only.\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);
	}

	if (choice == 1) {
		passportSearch(top);
	}
	else {
		nameSearch(top);
	}
}

void passportSearch(struct passenger* top) {
	struct passenger* temp;
	int passportNum;
	int found = 0;
	int count = 0;

	temp = top;

	printf("\nPlease enter passport number: ");
	scanf("%d", &passportNum);

	for (int i = 0; i < listLength(top); i++) {
		if (temp->passportNum == passportNum) {
			found = 1;
			i = listLength(top);
		}
		else {
			temp = temp->next;
			count++;
		} // if..else
	} // for

	if (found == 1) {
		displayIndexPassenger(top, count);
	}
	else {
		printf("The passenger does not exist in the database.\n");
	}
}

void nameSearch(struct passenger* top) {
	struct passenger* temp;
	char name[20];
	char firstName[20];
	int found = 0;
	int count = 0;

	temp = top;

	printf("\nPlease enter first name: ");
	scanf("%s", name);

	while (count != listLength(top)) {
		strcpy(firstName, temp->firstName);
		if (strcmp(firstName, name) == 0) {
			found = 1;
			displayIndexPassenger(top, count);
		}
		temp = temp->next;
		count++;
	}

	if (found != 1) {
		printf("The passenger does not exist in the database.\n");
	}
}