#include "Linkedlist.h"

void addPassengerAtStart(struct passenger** top, struct passenger** bottom) {
	struct passenger* newNode;
	struct passenger* temp;

	newNode = (struct passenger*)malloc(sizeof(struct passenger));

	inputPassenger(newNode);

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

void addPassenger(struct passenger** top, struct passenger** bottom) {
	if (*bottom == NULL) {
		addPassengerAtStart(top, bottom);
	}
	else {
		struct passenger* newNode;
		struct passenger* temp;

		newNode = (struct passenger*)malloc(sizeof(struct passenger));

		temp = *bottom;
		inputPassenger(newNode);
		newNode->next = NULL;
		newNode->previous = temp;
		temp->next = newNode;
		*bottom = newNode;
		printf("Passenger Successfully Added.\n");
	}
} // addPassengerAtEnd()

void displayList(struct passenger* top) {
	struct passenger* temp;
	int passengerCount = 0;
	char region[15];
	char travelClass[16];
	char tripCount[32];
	char duration[18];

	temp = top;

	printf("\nPassenger Database:\n");

	while (temp != NULL) {
		printf("==Passenger %d==\n", passengerCount);
		printf("Passport Number: %d\n", temp->passportNum);
		printf("First Name: %s\n", temp->firstName);
		printf("Second Name: %s\n", temp->secondName);
		printf("Year Born: %d\n", temp->yearBorn);
		printf("Email Address: %s\n", temp->email);
		strcpy(region, getRegion(temp->region));
		strcpy(travelClass, getTravelClass(temp->travelClass));
		strcpy(tripCount, getTripCount(temp->tripCount));
		strcpy(duration, getDuration(temp->duration));
		printf("Region: %s\n", region);
		printf("Travel Class: %s\n", travelClass);
		printf("Trip Count to Ireland: %s\n", tripCount);
		printf("Stay Duration: %s\n", duration);
		printf("================\n");
		temp = temp->next;
		passengerCount++;
	} // while
} // displayList()

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