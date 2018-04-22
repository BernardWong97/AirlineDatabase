// Main.c

#include "Passenger.h"

void main() {
	struct passenger* headPtr = NULL;
	struct passenger* tailPtr = NULL;
	int choice;
	int position;
	int log;

	// login
	displayHeader();
	log = login();
	while (log != 1) {
		system("@cls||clear");
		displayHeader();
		printf("The Username Or Password is Incorrect.\n");
		log = login();
	} // while invalid login

	system("@cls||clear");
	displayHeader();
	initLinkedList(&headPtr, &tailPtr); // Load linked list from file
	Sleep(500);
	system("@cls||clear");

	// main menu
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
			} // if linkedlist is empty
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
			generateStatistics(headPtr, 0);
			break;
		case 7:
			printReport(headPtr);
			break;
		case 8:
			if (headPtr == NULL) {
				printf("\nThe database is empty.\n");
			}
			else {
				sortedUKPassenger(headPtr);
			} // if linkedlist is empty
			break;
		default:
			printf("Please enter 1 to 8 only or -1 to exit.\n"); // validation
		} // switch main menu user input choice

		choice = displayMenu();
	} // while -1 sentinel control

	updateLinkedList(headPtr); // update linked list when program terminated
	printf("\n==Program Terminated==\n");
	getch();
} // main()
