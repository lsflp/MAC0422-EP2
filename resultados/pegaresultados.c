#include <stdio.h>

int main (int argc, char **argv) {
	int i = 0, j, num;
	char c;
	while (scanf ("%c", &c) != EOF) {
		if (c == '\n')
			i++;
		if (i == 9)
			break;
	}
	for (j = 0; j < 37; j++)
		scanf ("%c", &c);
	
	scanf ("%d", &num);
	printf ("%d\n", num);
}
