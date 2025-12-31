#include <stdio.h>

static double sin_series(double x, int terms) {
	if (terms <= 0) {
		return 0.0;
	}
	
	double sum = x;
	double term = x;
	for (int i = 1; i < terms; ++i) {
		int a = 2 * i;
		int b = 2 * i + 1;
		term *= -(x * x) / (a * b);
		sum += term;
	}
	return sum;
}

int main(void) {
	double x;
	int n;
	printf("Enter x (in radians): ");
	if (scanf("%lf", &x) != 1) {
		printf("Invalid x.\n");
		return 1;
	}
	printf("Enter number of terms (positive integer): ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid term count.\n");
		return 1;
	}

	double result = sin_series(x, n);
	printf("sin(x) approximation with %d terms: %.10f\n", n, result);
	return 0;
}
