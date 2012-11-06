#include <cstdlib>
#include <cstdio>

int main() {
	FILE *f = fopen("math.txt", "r");
	if (f == NULL) {
		puts("File math.txt must exist");
		system("pause");
		return 1;
	}

	int a, b;
	char op;
	fscanf(f, "%d %c %d", &a, &op, &b);

	int r;

	if (op == '+') {
		r = a + b;
	} else if (op == '-') {
		r = a - b;
	} else if (op == '*') {
		r = a * b;
	} else if (op == '/') {
		if (b == 0) {
			if (a >= 0) {
				puts("+inf");
			} else {
				puts("-inf");
			}
			system("pause");
			return 0;
		} else {
			r = a / b;
		}
	}

	printf("%d\n", r);

	fclose(f);
	system("pause");
	return 0;
}