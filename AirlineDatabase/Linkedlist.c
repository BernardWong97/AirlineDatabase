// Linkedlist.c

#include "Linkedlist.h"

// add the new passenger node to the start of the linked list
void addPassengerAtStart(struct passenger** top, struct passenger** bottom, struct passenger* newNode) {
	newNode->next = NULL;
	newNode->previous = NULL;
	*top = newNode;
	*bottom = newNode;
} // addPassengerAtStart()

// add the passenger by comparing the passport number so the linked list is in order
void addPassenger(struct passenger** top, struct passenger** bottom) {
	struct passenger* newNode;
	struct passenger* temp;
	struct passenger* temp2;

	newNode = (struct passenger*)malloc(sizeof(struct passenger));

	inputPassenger(newNode, top);

	if (*top == NULL) {
		addPassengerAtStart(top, bottom, newNode);
	}
	else {
		temp = *top;

		while (newNode->passportNum > temp->passportNum) {
			temp2 = temp;
			temp = temp->next;

			if (temp == NULL)
				break;
		} // while new passenger's passport number is bigger than current pointing passenger
			
		if (temp == NULL) {
			// add to the end of the linked list
			newNode->next = NULL;
			newNode->previous = temp2;
			temp2->next = newNode;
			*bottom = newNode;
		}
		else {
			// add before the current pointing passenger
			newNode->next = temp;
			newNode->previous = temp->previous;
			temp2 = temp->previous;

			if (temp2 == NULL) {
				*top = newNode;
			}
			else {
				temp2->next = newNode;
			} // if the previous of the current pointing passenger is NULL

			temp->previous = newNode;
		} // if current pointing passenger is NULL
		
		printf("Passenger Successfully Added.\n");
	} // if head pointer is NULL
} // addPassenger()

// iterate through database and display every passenger's details to the console
void displayList(struct passenger* top) {
	struct passenger* temp;
	int passengerCount = 1;
	char region[15];
	char travelClass[16];
	char tripCount[32];
	char duration[18];

	temp = top;

	printf("\nPassenger Database:");

	while (temp != NULL) {
		// output every details
		printf("\n==Passenger %d==\n", passengerCount);
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
	} // while current pointing passenger is not NULL
} // displayList()

// display the passenger details that is at the provided index
void displayIndexPassenger(struct passenger* top, int index) {
	struct passenger* temp;
	int count = 0;
	char region[15];
	char travelClass[16];
	char tripCount[32];
	char duration[18];

	temp = top;

	while (count != index) {
		count++;
		temp = temp->next;
	} // while counter is not equals to index

	// output every details
	printf("\n==Passenger %d==\n", index + 1);
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
} // displayIndexPassenger()

// return the length of the linked list
int listLength(struct passenger* top) {
	struct passenger* temp;
	int count = 0;

	temp = top;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	} // while current pointing counter is not NULL

	return count;
} // listLength

// search and update the passenger
void updatePassenger(struct passenger* top) {
	struct passenger* temp;
	int count = 0;
	int index;

	index = searchPassenger(top);
	temp = top;

	// search fail do nothing
	if (index != -1) {
		while (count != index) {
			temp = temp->next;
			count++;
		} // while count not equals index

		updateDetails(temp);
	} // if index not equals -1
} // updatePassenger()

// search and delete the passenger
void deletePassenger(struct passenger** top, struct passenger** bottom) {
	struct passenger* temp;
	struct passenger* temp2;
	int count = 0;
	int index;
	char choice;

	index = searchPassenger(*top);

	temp = *top;

	// search fail do nothing
	if (index != -1) {
		printf("\nAre you sure you want to delete this passenger? (y/n): ");
		scanf(" %c", &choice);

		while (!(choice == 'y' || choice == 'n')) {
			printf("Invalid input, y or n only.\n");
			printf("Please enter your choice: ");
			scanf(" %c", &choice);
		}

		if (choice == 'y') {
			while (count != index) {
				temp = temp->next;
				count++;
			}
			
			if ((*top)->next == NULL) {
				// if only one passenger in the list, clear list
				*top = NULL;
				*bottom = NULL;
			}
			else if (index == 0) {
				// delete first passenger of the list
				*top = temp->next;
				(*top)->previous = NULL;
			}
			else if (index == listLength(*top) - 1) {
				// if last passenger of the list
				*bottom = temp->previous;
				(*bottom)->next = NULL;
			}
			else {
				// if neither first nor last passenger, shift and delete
				temp2 = temp->previous;
				temp2->next = temp->next;
				temp2 = temp->next;
				temp2->previous = temp->previous;
			} // if/else if

			free(temp); // free memory
			printf("\nPassenger Successfully Deleted.\n");
		}
		else {
			printf("\nDeletion Canceled.\n");
		} // if choice is y
	} // if index not equals -1
} // deletePassenger()

// create new linked list and add all uk passenger into the new list sorted by year born
void sortedUKPassenger(struct passenger* top) {
	struct passenger* tempHead = NULL;
	struct passenger* newNode;
	struct passenger* temp;
	struct passenger* temp2;
	struct passenger* temp3;
	
	temp = top;

	for (int i = 0; i < listLength(top); i++) {
		newNode = (struct passenger*)malloc(sizeof(struct passenger));
		temp2 = tempHead;

		if (temp->region == 1) {
			// deep copy the passenger into a new passenger node
			newNode->passportNum = temp->passportNum;
			strcpy(newNode->firstName, temp->firstName);
			strcpy(newNode->secondName, temp->secondName);
			newNode->yearBorn = temp->yearBorn;
			strcpy(newNode->email, temp->email);
			newNode->region = temp->region;
			newNode->travelClass = temp->travelClass;
			newNode->tripCount = temp->tripCount;
			newNode->duration = temp->duration;
			newNode->previous = NULL;

			if (tempHead == NULL) {
				// if new list is empty
				tempHead = newNode;
				newNode->next = NULL;
			}
			else {
				if (newNode->yearBorn >= temp2->yearBorn) {
					while (temp2->next != NULL && newNode->yearBorn >= temp2->yearBorn) {
						// point to the biggest year born (youngest) passenger
						temp2 = temp2->next;
					} // while current passenger's year born is bigger (younger) than or equals current pointing passenger (next pointer must not be NULL)

					if (newNode->yearBorn < temp2->yearBorn) {
						// if the current passenger's year born is smaller (older) than the youngest passenger, add before the youngest passenger
						newNode->next = temp2;
						temp3 = temp2->previous;
						temp2->previous = newNode;
						newNode->previous = temp3;
						temp3->next = newNode;
					}
					else {
						// if the current passenger's year born is bigger (younger) than the youngest passenger, add to the end of the list
						newNode->next = temp2->next;
						newNode->previous = temp2;
						temp2->next = newNode;
					} // if current passenger's year born is smaller (older) than current pointing passenger
				}
				else {
					newNode->next = temp2;
					tempHead = newNode;
				} // if current passenger's year born is bigger (younger) than or equals current pointing passenger
			} // if current pointing passenger is NULL (new list)
		} // if region is UK

		temp = temp->next;
	} // for i
	
	displayList(tempHead); // display the new list
} // sortedUKPassenger()