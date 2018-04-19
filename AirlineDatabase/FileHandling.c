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
	}
	else {
		printf("Loading Data From Database");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
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

			if ((c = fgetc(fileptr)) == EOF)
				break;
			ungetc(c, fileptr);
		}

		printf("Loading Complete.");
		fclose(fileptr);
	}
}