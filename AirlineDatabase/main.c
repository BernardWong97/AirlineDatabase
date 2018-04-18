#include "Linkedlist.h"

// Main
void main() {
	struct passenger* headPtr = NULL;
	struct passenger* tailPtr = NULL;
	int choice;
	int position;

	printf("========= XYZ Airport Passenger Statistic Application =========\n");
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
			break;
		case 4:
			break;
		case 5:
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

	getch();
} // main()
