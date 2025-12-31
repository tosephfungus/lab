#include <stdio.h>

static double cos_series(double x, int terms) {
	if (terms <= 0) {
		return 0.0;
	}
	double sum = 1.0;
	double term = 1.0;
	for (int k = 1; k < terms; ++k) {
		int a = 2 * k - 1;
		int b = 2 * k;
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

	double result = cos_series(x, n);
	printf("cos(x) approximation with %d terms: %.10f\n", n, result);
	return 0;
}
