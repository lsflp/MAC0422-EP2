#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int N = atoi (argv[1]);
	float *todos = malloc (N * sizeof(float));
	int i;
	int numero;
	for (i = 0; i < N; i++) {
		scanf ("%f", &todos[i]);
	}
	printf ("tempo <- c(");
	for (i = 0; i < N; i++) {
		printf ("%f", todos[i]);
		if (i < N-1) 
			printf(", ");
	}
	printf(")");
	free (todos);
	return 0;
}