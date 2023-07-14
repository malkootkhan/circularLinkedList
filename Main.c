
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* circular linked list implementation in C */
/*
circularLinkedList Implementation in C
File: Main.c
Author: Malkoot Khan
Date: 14/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Node {
	int item;
	struct Node* next;
};
struct Node* createNode(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->item = data;
	temp->next = temp;
	return temp;
}
void insertAtStart(struct Node** start, int data) {
	struct Node* newNode = createNode(data);
	if (*start == NULL) {
		*start = newNode;
		return;
	}
	struct Node* s = *start;
	while (s->next != *start)
		s = s->next;
	newNode->next = *start;
	*start = newNode;
	s->next = *start;
}
void insertAtEnd(struct Node** start, int data) {
	struct Node* newNode = createNode(data);
	if (*start == NULL) {
		*start = newNode;
		return;
	}
	struct Node* s = *start;
	while (s->next != *start) 
		s = s->next;
	
	s->next = newNode;
	newNode->next = *start;
}
void insertAtPos(struct Node** start, int data, int pos) {
	struct Node* newNode = createNode(data);
	if (pos == 0) {
		insertAtStart(start,data);
		return;
	}
	int count = 1;
	struct Node* s = *start;
	while(s->next != *start){
		if (count == pos) {
			newNode->next = s->next;
			s->next = newNode;
			return;
		}
		s = s->next;
		count++;
	}
	if (count == pos)
	{
		insertAtEnd(start, data);
		return;
	}
	printf("Invalid Position!\n");
}
void search(struct Node** start, int data) {
	if (*start == NULL) {
		printf("The list is emppty!\n");
		return;
	}
	struct Node* s = *start;
	do
	 {
		if (data == s->item) {
			printf("Item found in the list!\n");
			return;
		}
		s = s->next;
	}while (s != *start);
	printf("Item not found!\n");
}
void deleteFirst(struct Node** start) {
	if (*start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct Node* s = *start;
	
	while (s->next != *start)
		s = s->next;
	struct Node* t = *start;
	*start = (*start)->next;
	s->next = *start;
	free(t);

}
void deleteLast(struct Node** start) {
	if (*start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	if ((*start)->next == *start) {
		free(*start);
		*start = NULL;
		return;
	}
	struct Node* s = *start;
	struct Node* t = s;
	do {
		t = s;
		s = s->next;
	} while (s->next != *start);
	t->next = *start;
	free(s);


}
void deleteAtPos(struct Node** start, int pos) {
	if (pos == 0) {
		deleteFirst(start);
		return;
	}
	struct Node* t = *start;
	struct Node* s = (*start)->next;
	int count = 1;
	 do{
		 if (count == pos) {
			 t->next = s->next;
			 free(s);
			 return;
		 }
		 t = s;
		 s = s->next;
		 count++;

		}while (s->next != *start);
		if (count == pos)
			deleteLast(start);
	printf("Invalid Position!\n");
}
void display(struct Node* start) {
	if (start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct Node* s = start;
	do {
		printf("%d ", s->item);
		s = s->next;
	} while (s != start);
	printf("\n");
}
int main() {
	
	struct Node* start = NULL;
	insertAtStart(&start, 10);
	insertAtStart(&start, 20);
	insertAtStart(&start, 30);
	insertAtStart(&start, 40);
	display(start);
	deleteAtPos(&start,5);
	display(start);
	deleteAtPos(&start, 3);
	display(start);
	deleteAtPos(&start, 1);
	display(start);
	return 0;
}

