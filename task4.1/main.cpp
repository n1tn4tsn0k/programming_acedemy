#include <cstdlib>
#include <cstdio>
#include <cmath>

int main() {
	int x = 0, y = 0;
	FILE *f = fopen("task4.1.txt", "r");
	if (f == NULL) {
		puts("File task4.1.txt must exist");
		system("pause");
		return 1;
	}
	for (int i = 0; i < 10; i++) {
		int _x, _y;
		fscanf(f, "%d %d", &_x, &_y);
		x += _x;
		y += _y;
	}
	fclose(f);
	double length = sqrt((double)x*x + y*y);
	printf("Length: %.2f\n", length);

	double angle = asin(x/length);
	printf("Angle with Oy in degrees: ~ %.2f\n", angle*180/3.14);

	f = fopen("task4.2.txt", "r");
	if (f == NULL) {
		puts("File task4.2.txt must exist");
		system("pause");
		return 1;
	}
	int x2, y2;
	fscanf(f, "%d %d", &x2, &y2);
	double length2 = sqrt((double)x2*x2 + y2*y2);
	double angle2 = acos((double)(x*x2 + y*y2)/(length*length2));
	printf("Angle between two vectors in degrees: ~ %.2f\n", angle2*180/3.14);

	system("pause");
	return 0;
}