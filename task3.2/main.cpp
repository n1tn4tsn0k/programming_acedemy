#include <cstdio>
#include <cstdlib>

bool digit(char c) {
	return (c >= '0' || c <= '9');
}

int main() {
	FILE *f = fopen("math.txt", "r");
	if (f == NULL) {
		puts("File math.txt must exist");
		system("pause");
		return 1;
	}

	char exp[256];
	fscanf(f, "%s", exp);
