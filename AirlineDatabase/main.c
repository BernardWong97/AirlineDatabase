#include "Linkedlist.h"

// Main
void main() {
	struct passenger* headPtr = NULL;
	struct passenger* tailPtr = NULL;
	int choice;
	int position;
	int log;

	displayHeader();
	log = login();
	while (log != 1) {
		system("@cls||clear");
		displayHeader();
		printf("The Username Or Password is Incorrect.\n");
		log = login();
	}

	system("@cls||clear");
	displayHeader();
	initLinkedList(&headPtr, &tailPtr);
	Sleep(500);
	system("@cls||clear");
	displayHeader();
	choice = displayMenu();

	while (choice != -1) {
		switch (choice) {
		case 1:
			addPassenger(&headPtr, &tailPtr);
			break;
		case 2:
			if (headPtr == NULL) {
				printf("\nThe database is empty.\n");
			}
			else {
				displayList(headPtr);
			}
			break;
		case 3:
			searchPassenger(headPtr);
			break;
		case 4:
			updatePassenger(headPtr);
			break;
		case 5:
			deletePassenger(&headPtr, &tailPtr);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			// Validation
			printf("Please enter 1 to 8 only or -1 to exit.\n");
		} // switch

		choice = displayMenu();
	} // while

	updateLinkedList(headPtr);
	printf("\n==Program Terminated==");
	getch();
} // main()
