#include <stdio.h> 
#include <stdlib.h> 

struct Node {
	char str;  //for the very last index "\0"
	struct Node* next;
};

void printStr(char str[]) {
	printf("String is : %s", str);
}

void push(struct Node** head_ref, char new_str) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->str = new_str;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main()
{
	struct Node* head = NULL;

	char str[]= "This is a sample text. The file is terminated by a single dot: .";
	//char str[256]="";
	printf("enter your string: ");
	puts(str);
	char delimiter[] = " .,:";
	char* p_token;
	char* p_next_token;
	
	p_token = strtok_s(str, delimiter, &p_next_token);
	for (int i = 0; p_token != NULL; i++)
	{
		printf("%s \n", p_token);
		p_token = strtok_s(NULL, delimiter, &p_next_token);	
		push(&head, p_token);
	}



	system("PAUSE");
	return 0;
}