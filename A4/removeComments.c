#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
	if (argc == 3) {
		int arg = atoi(argv[2]);
		if (arg == 1)
		{
			printf("\nNested format on.\n");
			printf("");
			char ch;
			bool single = false;
			bool quote = false;
			int multCount = 0;
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
					if (single == false && multCount == 0) {
						if (ch == '"') {
							quote = !quote;
						}
						else if (single == false && multCount == 0 && quote == true) {
							printf("%c", ch);
							ch = fgetc(fptr);
							continue;
						}
					}
					if (ch == '\n') {
						//printf("%c", 'n');
						single = false;
					}
					else if (ch == '/') {
						ch = fgetc(fptr);
						if (ch == '*') {
							multCount++;
							//printf("%d",multCount);
						}
						else if (ch == '/')
						{
							//printf("%c", ch);
							single = true;
						}
					}
					else if (ch == '*') {
						ch = fgetc(fptr);
						if (ch == '"') {
							printf("%c", ch);
							quote = !quote;
						}
						if (ch == '/') {
							multCount--;
							//printf("%d", multCount);
							ch = fgetc(fptr);
						}
					}



					/*printf("%c", ch);*/
					//printf("%d", single);
					if (multCount == 0 && single == false || quote == true) {
						printf("%c", ch);
					}
					ch = fgetc(fptr);
				}

				fclose(fptr);
			}
		}
	}
	else if (argc == 2) {
		//printf("The argument supplied is %s\n", argv[1]);
		printf("");
		char ch;
		bool single = false;
		bool quote = false;
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
				if (single == false && mult == false) {
					if (ch == '"') {
						quote = !quote;
					}
					else if (single == false && mult == false && quote == true) {
						printf("%c", ch);
						ch = fgetc(fptr);
						continue;
					}
				}
				if (ch == '/') {
					ch = fgetc(fptr);
					if (ch == '"') {
						printf("%c", ch);
						quote = !quote;
					}
					else if (ch == '*') {
						mult = true;
					}
					else if (ch == '/')
					{
						single = true;
					}
				}
				else if (ch == '\n') {
					single = false;
				}
				else if (ch == '*') {
					ch = fgetc(fptr);
					if (ch == '"') {
						printf("%c", ch);
						quote = !quote;
					}
					else if (ch == '/') {
						if (mult == false)
						{
							printf("%c",'*');
							printf("%c", ch);
						}
						mult = false;
						ch = fgetc(fptr);
					}
				}
				else if (single == false && mult == false && quote == true) {
					printf("%c", ch);
					ch = fgetc(fptr);
					continue;
				}
				if (single == false && mult == false || quote == true) {
					printf("%c", ch);
				}
				ch = fgetc(fptr);
			}

			fclose(fptr);
		}
	}
	else {
		printf("One argument expected.\n");
	}
	return 0;

}
