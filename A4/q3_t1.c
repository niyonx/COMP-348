#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 

#define MAX_STR_LEN 256

struct Node {
	char str[MAX_STR_LEN];  //for the very last index "\0"
	struct Node* next;
};

void insert_dictionary_order(struct Node** head_ref, char* new_str) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp2 = *head_ref;
	struct Node* prev = NULL;

	strcpy(temp->str, new_str);
	temp->next = NULL;
	if (temp2 == NULL) {
		*head_ref = temp;
		return;
	}
	while (temp2) {
		if (strcasecmp(temp2->str, temp->str) > 0) {
			temp->next = temp2;
			if (prev == NULL) {
				*head_ref = temp;
			}
			else {
				prev->next = temp;
			}
			return;
		}
		if (temp2->next == NULL) {
			temp2->next = temp;
			return;
		}
		prev = temp2;
		temp2 = temp2->next;
	}
}

void print_list(struct Node* head)
{
	struct Node* temp = head;

	while (temp != NULL)
	{
		printf("%s ", temp->str);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;
	char str[MAX_STR_LEN] = "This is a sample text. The file is terminated by a single dot: . \n";
	char delimiter[] = " .,:\t\n";
	char* p_token;

	printf("enter your string: ");
	puts(str); //gets(str);

	p_token = strtok(str, delimiter);

	while (p_token)
	{
		insert_dictionary_order(&head, p_token);

		p_token = strtok(NULL, delimiter);

	}

	print_list(head);

	//system("PAUSE");

	return 0;
}