#include "FileHandling.h"

void initLinkedList(struct passenger** top, struct passenger** bottom) {
	FILE* fileptr;
	struct passenger* newNode;
	struct passenger* temp;
	fileptr = fopen(PASSENGER, "r");
	char c;

	if (fileptr == NULL) {
		printf("!- Warning -!\n");
		printf("!- The File \"passenger.txt\" Does Not Exist -!\n");
		printf("!- Warning -!\n");
	}
	else {
		printf("Loading Data From Database");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf("\n");

		while (!feof(fileptr)) {
			newNode = (struct passenger*)malloc(sizeof(struct passenger));

			fscanf(fileptr, "%d", &newNode->passportNum);
			fscanf(fileptr, "%s", newNode->firstName);
			fscanf(fileptr, "%s", newNode->secondName);
			fscanf(fileptr, "%d", &newNode->yearBorn);
			fscanf(fileptr, "%s", newNode->email);
			fscanf(fileptr, "%d", &newNode->region);
			fscanf(fileptr, "%d", &newNode->travelClass);
			fscanf(fileptr, " %c", &newNode->tripCount);
			fscanf(fileptr, " %c", &newNode->duration);

			temp = *bottom;

			if (*top == NULL) {
				newNode->next = NULL;
				newNode->previous = NULL;
				*top = newNode;
				*bottom = newNode;
			}
			else {
				newNode->next = NULL;
				newNode->previous = temp;
				temp->next = newNode;
				*bottom = newNode;
			}
			
			if ((c = fgetc(fileptr)) == EOF || (c = fgetc(fileptr)) == '\n')
				break;
			ungetc(c, fileptr);
		}

		printf("Loading Complete.");
		fclose(fileptr);
	}
}

void updateLinkedList(struct passenger* top) {
	FILE* fileptr;
	struct passenger* temp;
	fileptr = fopen(PASSENGER, "w");
	temp = top;

	if (fileptr == NULL) {
		printf("!- Warning -!\n");
		printf("!- The File \"passenger.txt\" Does Not Exist -!\n");
		printf("!- Warning -!\n");
	}
	else {
		while (temp != NULL) {
			fprintf(fileptr, "%d\n", temp->passportNum);
			fprintf(fileptr, "%s\n", temp->firstName);
			fprintf(fileptr, "%s\n", temp->secondName);
			fprintf(fileptr, "%d\n", temp->yearBorn);
			fprintf(fileptr, "%s\n", temp->email);
			fprintf(fileptr, "%d\n", temp->region);
			fprintf(fileptr, "%d\n", temp->travelClass);
			fprintf(fileptr, "%c\n", temp->tripCount);
			fprintf(fileptr, "%c\n", temp->duration);
			temp = temp->next;
		} // while

		fclose(fileptr);
	}
}

int login() {
	FILE* fileptr;
	char username[7];
	char inputName[30];
	char password[7];
	char inputPass[30];
	int i = 0;
	char c;

	printf("Username: ");
	scanf("%s", inputName);
	printf("Password: ");

	do {
		c = getch();
		if (c != '\r') {
			if (c != '\b') {
				inputPass[i] = c;
				printf("*");
				i++;
			}
			else {
				i--;
				if (i < 0)
					i++;
				else
					printf("\b \b");
			}
		}
	} while (c != '\r');

	inputPass[i] = '\0';

	fileptr = fopen(LOGIN, "r");

	if (fileptr == NULL) {
		printf("!- Warning -!\n");
		printf("!- The File \"passenger.txt\" Does Not Exist -!\n");
		printf("!- Warning -!\n");
	}
	else {
		while (!feof(fileptr))
		{
			fscanf(fileptr, "Username: %s\n", username);
			fscanf(fileptr, "Password: %s\n", password);

			if (strcmp(inputName, username) == 0 && strcmp(inputPass, password) == 0) {
				printf("\nLogin in");
				Sleep(250);
				printf(".");
				Sleep(250);
				printf(".");
				Sleep(250);
				printf(".");
				Sleep(250);
				printf("\n");
				fclose(fileptr);
				return 1;
			}
		}

		fclose(fileptr);
		return 0;
	}
}

void printReport(struct passenger* top) {
	FILE* fileptr;
	int finish;
	struct passenger* temp;
	int passengerCount = 1;
	char region[15];
	char travelClass[16];
	char tripCount[32];
	char duration[18];

	fileptr = fopen(REPORT, "w");

	if (fileptr == NULL) {
		printf("!- Warning -!\n");
		printf("!- The File \"report.txt\" Does Not Exist -!\n");
		printf("!- Warning -!\n");
	} 
	else {
		temp = top;

		fprintf(fileptr, "===================Passenger Database===================");

		while (temp != NULL) {
			fprintf(fileptr, "\n==Passenger %d==\n", passengerCount);
			fprintf(fileptr, "Passport Number: %d\n", temp->passportNum);
			fprintf(fileptr, "First Name: %s\n", temp->firstName);
			fprintf(fileptr, "Second Name: %s\n", temp->secondName);
			fprintf(fileptr, "Year Born: %d\n", temp->yearBorn);
			fprintf(fileptr, "Email Address: %s\n", temp->email);
			strcpy(region, getRegion(temp->region));
			strcpy(travelClass, getTravelClass(temp->travelClass));
			strcpy(tripCount, getTripCount(temp->tripCount));
			strcpy(duration, getDuration(temp->duration));
			fprintf(fileptr, "Region: %s\n", region);
			fprintf(fileptr, "Travel Class: %s\n", travelClass);
			fprintf(fileptr, "Trip Count to Ireland: %s\n", tripCount);
			fprintf(fileptr, "Stay Duration: %s\n", duration);
			fprintf(fileptr, "================\n");
			temp = temp->next;
			passengerCount++;
		} // while

		fclose(fileptr);

		printStatistics(top);

		printf("\nFile Writing Complete.\n");
	}
}

void printStatistics(struct passenger* top) {
	FILE* fileptr;

	fileptr = fopen(REPORT, "a");

	if (fileptr == NULL) {
		printf("!- Warning -!\n");
		printf("!- The File \"report.txt\" Does Not Exist -!\n");
		printf("!- Warning -!\n");
	}
	else {
		fprintf(fileptr, "\n==========Statistics From Criteria \"Economy\"==========\n");
		calculateStatistics(1, top, 1, fileptr);
		fprintf(fileptr, "\n==========Statistics From Criteria \"Premium Economy\"==========\n");
		calculateStatistics(2, top, 1, fileptr);
		fprintf(fileptr, "\n==========Statistics From Criteria \"Business Class\"==========\n");
		calculateStatistics(3, top, 1, fileptr);
		fprintf(fileptr, "\n==========Statistics From Criteria \"First Class\"==========\n");
		calculateStatistics(4, top, 1, fileptr);
		fprintf(fileptr, "\n==========Statistics From Criteria \"Born Before 1980\"==========\n");
		calculateStatistics(5, top, 1, fileptr);
	}

	fclose(fileptr);
}