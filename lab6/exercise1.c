#include <math.h>
#include <stdio.h>
#include <ctype.h>

static double series_a(int n) {
	double sum = 0.0;
	for (int k = 1; k <= n; ++k) {
		sum += 1.0 / (k * k * k);
	}
	return sum;
}

static double series_b(int n) {
	double sum = 0.0;
	for (int k = 1; k <= n; ++k) {
		int sign = (k % 2 == 0) ? 1 : -1;
		sum += sign * (double)(k * k);
	}
	return sum;
}

static double series_c(int n) {
	double sum = 0.0;
	double fact = 1.0;
	for (int k = 1; k <= n; ++k) {
		fact *= k;
		sum += fact;
	}
	return sum;
}

static double series_d(int n) {
	double sum = 0.0;
	double fact = 1.0;
	for (int k = 1; k <= n; ++k) {
		fact *= k;
		sum += k / fact;
	}
	return sum;
}

static double series_e(int n, double x) {
	double sum = 1.0;
	double term = 1.0;
	for (int k = 1; k <= n; ++k) {
		term *= x / k;
		sum += term;
	}
	return sum;
}

static double series_f(int n, double x) {
	if (n <= 0) {
		return 0.0;
	}
	double sum = x;
	double term = x;
	for (int i = 2; i <= n; ++i) {
		int a = 2 * i - 2;
		int b = 2 * i - 1;
		term *= (x * x) / (a * b);
		sum += term;
	}
	return sum;
}

static double series_g(int n, double x) {
	double sum = 1.0;
	double term = 1.0; 
	for (int i = 1; i <= n; ++i) {
		int a = 2 * i - 1;
		int b = 2 * i;
		term *= (x * x) / (a * b);
		sum += term;
	}
	return sum;
}

static double series_h(int n, double x) {

    return series_e(n, x);
}

static int read_n(void) {
	int n;
	printf("Enter n: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n. Must be a positive integer.\n");
		return -1;
	}
	return n;
}

static int read_n_and_x(double *x_out) {
	int n = read_n();
	if (n <= 0) {
		return -1;
	}
	printf("Enter x: ");
	if (scanf("%lf", x_out) != 1) {
		printf("Invalid x.\n");
		return -1;
	}
	return n;
}

int main(void) {
	char choice;
	printf("Select series to evaluate:\n");
	printf("a) 1 + 1/8 + 1/27 + ... + 1/n^3\n");
	printf("b) -1 + 4 - 9 + 16 ... + (-1)^n n^2\n");
	printf("c) 1! + 2! + ... + n!\n");
	printf("d) 1 + 2/2! + 3/3! + ... + n/n!\n");
	printf("e) 1 + x/1! + x^2/2! + ... + x^n/n!\n");
	printf("f) x + x^3/3! + ... + x^(2n-1)/(2n-1)!\n");
	printf("g) 1 + x^2/2! + ... + x^(2n)/(2n)!\n");
	printf("h) 1 + x + x^2/2! + ... + x^n/n!\n");
	printf("Enter choice (a-h): ");

	if (scanf(" %c", &choice) != 1) {
		printf("Failed to read choice.\n");
		return 1;
	}

	choice = (char)tolower((unsigned char)choice);
	int n;
	double x;
	double result;

	switch (choice) {
	case 'a':
		n = read_n();
		if (n > 0) {
			result = series_a(n);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'b':
		n = read_n();
		if (n > 0) {
			result = series_b(n);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'c':
		n = read_n();
		if (n > 0) {
			result = series_c(n);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'd':
		n = read_n();
		if (n > 0) {
			result = series_d(n);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'e':
		n = read_n_and_x(&x);
		if (n > 0) {
			result = series_e(n, x);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'f':
		n = read_n_and_x(&x);
		if (n > 0) {
			result = series_f(n, x);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'g':
		n = read_n_and_x(&x);
		if (n > 0) {
			result = series_g(n, x);
			printf("Result: %.10f\n", result);
		}
		break;
	case 'h':
		n = read_n_and_x(&x);
		if (n > 0) {
			result = series_h(n, x);
			printf("Result: %.10f\n", result);
		}
		break;
	default:
		printf("Invalid choice. Please select between a and h.\n");
		break;
	}

	return 0;
}
