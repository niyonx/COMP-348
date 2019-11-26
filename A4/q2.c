#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h>
#include <limits.h> 

void print_bits(unsigned char x)
{
	int i;
	for (i = 8 * sizeof(x) - 1; i >= 0; i--) {
		if (i == 3)
		{
			putchar(' ');
		}
		(x & (1 << i)) ? putchar('X') : putchar('0');
	}
}

int main() {
	char chr;
	printf("[F]loat or [D]ouble? ");
	scanf_s("%c", &chr);
	printf("Enter the number: ");
	if (chr == 'D')
	{
		double d;
		d = 0;

		scanf_s("%lf", &d);
		unsigned char* bytes = (unsigned char*)(void*)& d;


		for (int i = sizeof(double) - 1; i >= 0; i--) {
			unsigned char b = bytes[i];
			print_bits(b); putchar(' ');
		}
	}
	else if (chr == 'F')
	{
		float f;
		f = 0;

		scanf_s("%f", &f);
		unsigned char* bytes = (unsigned char*)(void*)& f;


		for (int i = sizeof(float) - 1; i >= 0; i--) {
			unsigned char b = bytes[i];
			print_bits(b); putchar(' ');
		}
	}
	return 0;
}
