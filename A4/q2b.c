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

union ufloat {
	float f;
	unsigned char bytes[sizeof(float)];
};

union udouble {
	double d;
	unsigned char bytes[sizeof(double)];
};

int main() {
	char chr;
	printf("[F]loat or [D]ouble? ");
	scanf_s("%c", &chr);
	printf("Enter the number: ");
	if (chr == 'D')
	{
		union udouble u1;
		u1.d = 0;

		scanf_s("%lf", &u1.d);

		for (int i = sizeof(double) - 1; i >= 0; i--) {
			unsigned char b = u1.bytes[i];
			print_bits(b); putchar(' ');
		}
	}
	else if (chr == 'F')
	{
		union ufloat u1;
		u1.f = 0;
		
		scanf_s("%f", &u1.f);
		
		for (int i = sizeof(float) - 1; i >= 0; i--) {
			unsigned char b = u1.bytes[i];
			print_bits(b); putchar(' ');
		}
	}
	return 0;
}
