#include <stdio.h>

int main (int argc, char **argv) {
	int i = 0, j; 
	float num;
	char c;
	while (scanf ("%c", &c) != EOF) {
		if (c == '\n')
			i++;
		if (i == 1)
			break;
	}
	for (j = 0; j < 22; j++)
		scanf ("%c", &c);
	
	scanf ("%f", &num);
	printf ("%f\n", num);
}
