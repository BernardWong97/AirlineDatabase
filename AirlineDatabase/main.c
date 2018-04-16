#include "Linkedlist.h"

// Main
void main() {
	struct passenger* headPtr = NULL;
	struct passenger* tailPtr = NULL;
	int choice;
	int position;

	choice = displayMenu();

	while (choice != -1) {
		switch (choice) {
		case 1:
			// If list empty, add first element
			if (headPtr == NULL) {
				addStudentAtStart(&headPtr);
			}
			else {
				addStudentAtEnd(headPtr);
			} // if..else
			break;
		case 2:
			addStudentAtStart(&headPtr);
			break;
		case 3:
			// If list empty, output message
			if (headPtr == NULL) {
				printf("\nNo element in the list\n");
			}
			else if (headPtr->next != NULL) {
				deleteStudentAtEnd(headPtr);
			}
			else {
				deleteStudentAtStart(&headPtr);
			} // if..else
			break;
		case 4:
			// If list empty, output message
			if (headPtr == NULL) {
				printf("\nNo element in the list\n");
			}
			else {
				displayList(headPtr);
			} // if..else
			break;
		case 5:
			searchStudent(headPtr);
			break;
		case 6:
			// If list empty, output message
			if (headPtr == NULL) {
				printf("\nNo element in the list\n");
			}
			else {
				deleteStudentAtStart(&headPtr);
			} // if..else
			break;
		default:
			// Validation
			printf("Please enter 1 to 6 only or -1 to exit.\n");
		} // switch

		choice = displayMenu();
	} // while

	getch();
} // main()
