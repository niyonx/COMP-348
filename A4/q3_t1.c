#include <stdio.h> 
#include <stdlib.h> 
#define MAX_STR_LEN 256

struct Node {
	char str[MAX_STR_LEN];  //for the very last index "\0"
	struct Node* next;
};

void insert_dictionary_order(char* s) 
{

}

void print_list(struct Node* head) 
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%s", temp->str);
		temp = temp->next;
	}
}

void push(struct Node** head_ref, char new_str) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	*new_node->str = new_str;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main()
{
	struct Node* head = NULL;

	char str[MAX_STR_LEN]= "This is a sample text. The file is terminated by a single dot: .";
	printf("enter your string: ");
	puts(str); //VS does not accept scanf, and online compilers don't accept strtok_s
	//gets(str); 
	char delimiter[] = " .,:";
	char* p_token;
	char* p_next_token;
	
	p_token = strtok_s(str, delimiter, &p_next_token);
	for (int i = 0; p_token != NULL; i++)
	{
		printf("%s  ", p_token);
		p_token = strtok_s(NULL, delimiter, &p_next_token);	
		push(&head, p_token);
	}

	print_list(head);

	system("\n PAUSE");
	return 0;
}