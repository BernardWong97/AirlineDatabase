#include "Linkedlist.h"

void addPassengerAtStart(struct passenger** top, struct passenger** bottom, struct passenger* newNode) {
	newNode->next = NULL;
	newNode->previous = NULL;
	*top = newNode;
	*bottom = newNode;
} // addPassengerAtStart()

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
		}
			
		if (temp == NULL) {
			newNode->next = NULL;
			newNode->previous = temp2;
			temp2->next = newNode;
			*bottom = newNode;
		}
		else {
			newNode->next = temp;
			newNode->previous = temp->previous;
			temp2 = temp->previous;
			if (temp2 == NULL) {
				*top = newNode;
			}
			else {
				temp2->next = newNode;
			}
			temp->previous = newNode;
		}
		
		printf("Passenger Successfully Added.\n");
	}

} // addPassengerAtEnd()

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
	} // while
} // displayList()

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
	} // while

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
}

int listLength(struct passenger* top) {
	struct passenger* temp;
	int count = 0;

	temp = top;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	} // while

	return count;
} // listLength()

void updatePassenger(struct passenger* top) {
	struct passenger* temp;
	int count = 0;
	int index;

	index = searchPassenger(top);
	temp = top;

	if (index != -1) {
		while (count != index) {
			temp = temp->next;
			count++;
		}

		updateDetails(temp);
	}
	
}

void deletePassenger(struct passenger** top, struct passenger** bottom) {
	struct passenger* temp;
	struct passenger* temp2;
	int count = 0;
	int index;
	char choice;

	index = searchPassenger(*top);

	temp = *top;

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
				*top = NULL;
				*bottom = NULL;
			}
			else if (index == 0) {
				*top = temp->next;
				(*top)->previous = NULL;
			}
			else if (index == listLength(*top) - 1) {
				*bottom = temp->previous;
				(*bottom)->next = NULL;
			}
			else {
				temp2 = temp->previous;
				temp2->next = temp->next;
				temp2 = temp->next;
				temp2->previous = temp->previous;
			}

			free(temp);
			printf("\nPassenger Successfully Deleted.\n");
		}
		else {
			printf("\nDeletion Canceled.\n");
		}
	}
}


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
				tempHead = newNode;
				newNode->next = NULL;
			}
			else {
				if (newNode->yearBorn >= temp2->yearBorn) {
					while (temp2->next != NULL && newNode->yearBorn >= temp2->yearBorn) {
						temp2 = temp2->next;
					}

					if (newNode->yearBorn < temp2->yearBorn) {
						newNode->next = temp2;
						temp3 = temp2->previous;
						temp2->previous = newNode;
						newNode->previous = temp3;
						temp3->next = newNode;
					}
					else {
						newNode->next = temp2->next;
						newNode->previous = temp2;
						temp2->next = newNode;
					}
				}
				else {
					newNode->next = temp2;
					tempHead = newNode;
				}
			}
		}

		temp = temp->next;
	}
	
	displayList(tempHead);
}