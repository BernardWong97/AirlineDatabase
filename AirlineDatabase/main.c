#include "Header.h"

// Main
void main() {
	struct passenger* headPtr = NULL;
	int choice;
	int position;

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

		printf("1. Add a student to the end of the list.\n");
		printf("2. Add a student to the top of the list.\n");
		printf("3. Delete a student from the end of the list.\n");
		printf("4. Display all of the students in the list.\n");
		printf("5. Search the list for a student's specified ID.\n");
		printf("6. Delete a student from the start of the list.\n");
		printf("-1. Exit.\n");
		printf("Please enter one of the following options: ");
		scanf("%d", &choice);
	} // while

	getch();
} // main()
