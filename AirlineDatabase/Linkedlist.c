#include "Linkedlist.h"

int displayMenu() {
	int choice;

	printf("1. Add a passenger.\n");
	printf("2. Display all passenger.\n");
	printf("3. Display passenger details.\n");
	printf("4. Update a passenger statistic.\n");
	printf("5. Delete a passenger.\n");
	printf("6. Generate statistics.\n");
	printf("7. Print all passenger details into a report file.\n");
	printf("8. List all the passenger from UK in order of year born.\n");
	printf("-1. Exit.\n");
	printf("\nPlease enter one of the following options: ");
	scanf("%d", &choice);

	return choice;
}

void addPassengerAtStart(struct passenger** top, struct node** bottom) {
	struct passenger* newNode;
	struct passenger* temp;

	newNode = (struct passenger*)malloc(sizeof(struct passenger));

	addPassenger(newNode);

	temp = *top;

	if (*top == NULL) {
		newNode->next = NULL;
		newNode->previous = NULL;
		*top = newNode;
		*bottom = newNode;
	}
	else {
		newNode->previous = NULL;
		newNode->next = temp;
		temp->previous = newNode;
		*top = newNode;
	}

	printf("Passenger Successfully Added.\n");
} // addPassengerAtStart()

void addPassengerAtEnd(struct passenger** top, struct passenger** bottom) {
	struct passenger* newNode;
	struct passenger* temp;

	newNode = (struct passenger*)malloc(sizeof(struct passenger));

	inputPassenger(newNode);

	temp = *bottom;

	if (*bottom == NULL) {
		addElementAtStart(top, bottom);
	}
	else {
		newNode->next = NULL;
		newNode->previous = temp;
		temp->next = newNode;
		*bottom = newNode;
	}
	printf("Passenger Successfully Added.\n");
} // addPassengerAtEnd()

//void displayList(struct passenger* top) {
//	struct passenger* temp;
//
//	temp = top;
//
//	printf("\nStudent Database:\n");
//
//	while (temp != NULL) {
//		printf("Name: %s\n", temp->name);
//		printf("Age: %d\n", temp->age);
//		printf("ID: %s\n", temp->id);
//		printf("Average Grade: %f\n", temp->averageGrade);
//		printf("Email: %s\n", temp->email);
//		printf("Mobile: %s\n", temp->mobile);
//		temp = temp->next;
//	} // while
//
//	printf("\n");
//} // displayList()
//
//int listLength(struct passenger* top) {
//	struct passenger* temp;
//	int count = 0;
//
//	temp = top;
//
//	while (temp != NULL) {
//		count++;
//		temp = temp->next;
//	} // while
//
//	return count;
//} // displayListLength()
//
//
//void deleteStudentAtEnd(struct passenger* top) {
//	struct passenger* temp;
//	struct passenger* prev;
//
//	temp = top;
//
//	while (temp->next != NULL) {
//		prev = temp;
//		temp = temp->next;
//	} // while
//
//	printf("\Student ID [%d] Successfully Deleted.\n", temp->id);
//
//	prev->next = NULL;
//	free(temp);
//} // deleteElementAtEnd()
//
//void searchStudent(struct passenger* top) {
//	struct passenger* temp;
//	int id;
//	int found = 0;
//	int count = 1;
//
//	temp = top;
//
//	printf("\nPlease enter the ID of the student: ");
//	scanf("%d", &id);
//
//	for (int i = 0; i < listLength(top); i++) {
//		if (temp->id == id) {
//			found = 1;
//			i = listLength(top);
//		}
//		else {
//			temp = temp->next;
//			count++;
//		} // if..else
//	} // for
//
//	if (found == 1) {
//		printf("Student ID [%d] is at index %d of the list.\n", id, count);
//	}
//	else {
//		printf("Student ID [%d] is not in the list.\n", id);
//	} // if..else
//} // searchElement()
//
//void deleteStudentAtStart(struct passenger** top) {
//	struct passenger* temp;
//
//	temp = *top;
//
//	*top = temp->next;
//
//	printf("\nStudent ID [%d] Successfully Deleted.\n", temp->id);
//	free(temp);
//} // deleteElementAtStart()