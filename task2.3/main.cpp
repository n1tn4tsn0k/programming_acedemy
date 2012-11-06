#include <cstdio>
#include <cstdlib>

int main() {

	char name[256];
	printf("Your name: ");
	scanf("%s", name);
	FILE *f = fopen("name.txt", "w");
	fprintf(f, "My name is %s", name);
	fclose(f);

	char name2[256];
	f = fopen("name.txt", "r");
	fscanf(f, "My name is %s", name2);
	puts(name2);

	system("pause");

	return 0;
}
