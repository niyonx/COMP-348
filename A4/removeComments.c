#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
	if (argc == 2) {
		//printf("The argument supplied is %s\n", argv[1]);
		printf("");
		char ch;
		bool single = false;
		bool mult = false;
		FILE* fptr;
		fptr = fopen(argv[1], "r");

		if (fptr == NULL)
		{
			printf("Error!");
			exit(1);
		}
		else
		{
			// check if file does not exist
			if (fptr == NULL)
			{
				printf("Cannot open file \n");
				exit(0);
			}

			// Read contents from file 
			ch = fgetc(fptr);
			while (ch != EOF)
			{
				if (ch == '/') {
					ch = fgetc(fptr);
					if (ch == '*') {
						mult = true;
					}
					else
					{
						single = true;
					}
				}
				else if (ch == "/n") {
					single = false;
				}
				else if (ch == '*') {
					ch = fgetc(fptr);
					if (ch == '/') {
						mult = false;
						ch = fgetc(fptr);
					}
				}

				if (single == false && mult == false){
					printf("%c", ch);
				}
				ch = fgetc(fptr);
			}

			fclose(fptr);
			return 0;
			/*while (ch != EOF) {
				ch = fgetc(fptr);
				printf(ch);
				if (ch == '/') {
					ch = fgetc(fptr);
					if (ch == '*') {
						printf(" ");
					}
				}
				else if (ch == '*') {
					ch = fgetc(fptr);
					if (ch == '/') {
						printf(" ");
					}
				}
				else {
					printf("%c",ch);
				}
			}*/
		}
	}
	else if (argc > 2) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("One argument expected.\n");
	}

	

	return 0;
}