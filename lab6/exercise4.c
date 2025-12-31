#include <stdio.h>

static void pattern_a(void) {
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d", j);
		}
		printf("\n");
	}
}

static void pattern_b(void) {
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d", i);
		}
		printf("\n");
	}
}

static void pattern_c(void) {
	for (int i = 0; i < 5; ++i) {
		for (int v = 5; v >= 5 - i; --v) {
			printf("%d", v);
		}
		printf("\n");
	}
}

static void pattern_d(void) {
	for (int i = 0; i < 5; ++i) {
		int val = 5 - i;
		for (int j = 0; j <= i; ++j) {
			printf("%d", val);
		}
		printf("\n");
	}
}

static void pattern_e(void) {
	int num = 1;
	for (int row = 1; row <= 5; ++row) {
		for (int col = 1; col <= row; ++col) {
			printf("%d", num++);
			if (col < row) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

static void pattern_f(void) {
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}
}

static void pattern_g(void) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%c", 'A' + j);
		}
		printf("\n");
	}
}

static void pattern_h(void) {
	for (int i = 0; i < 5; ++i) {
		for (int v = 5; v >= i + 1; --v) {
			printf("%d", v);
		}
		printf("\n");
	}
}

static void pattern_i(void) {
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("2");
		}
		printf("\n");
	}
}

static void pattern_j(void) {
	int num = 10;
	for (int row = 1; row <= 5; ++row) {
		for (int col = 1; col <= row; ++col) {
			printf("%d", num);
			num += 10;
			if (col < row) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void) {
	printf("a.\n");
	pattern_a();
	printf("\nb.\n");
	pattern_b();
	printf("\nc.\n");
	pattern_c();
	printf("\nd.\n");
	pattern_d();
	printf("\ne.\n");
	pattern_e();
	printf("\nf.\n");
	pattern_f();
	printf("\ng.\n");
	pattern_g();
	printf("\nh.\n");
	pattern_h();
	printf("\ni.\n");
	pattern_i();
	printf("\nj.\n");
	pattern_j();
	return 0;
}
