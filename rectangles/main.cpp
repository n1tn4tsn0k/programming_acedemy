#include <cstdio>
#include <cstdlib>
#include <cmath>

#define N 7

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
} rect;

int get_area(rect r);
int get_intersect_area(rect r1, rect r2);
int find_center_side(int a, int b, int c, int d);
void swap(int* a, int* b);

int main() {

	FILE* f = fopen("rectangles.txt", "r");
	if (f == NULL) {
		printf("File rectangles.txt must exist\n");
		return 0;
	}
	rect* rects = (rect*) malloc(N*sizeof(rect));
	int intersect_area = 0;
	int area = 0;
	for (int i = 0; i < N; i++) {
		fscanf(f, "%d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
		area += get_area(rects[i]);
		for (int j = 0; j < i; j++) {
			intersect_area += get_intersect_area(rects[i], rects[j]);
		}
	}
	fclose(f);

	area -= intersect_area;

	printf("%d\n", area);

	return 0;
}

int get_area(rect r) {

	return abs(r.x2 - r.x1) * abs(r.y2 - r.y1);
}

int get_intersect_area(rect r1, rect r2) {

	// check if rectangles intersect
	if (
		min(r1.x1, r1.x2) > max(r2.x1, r2.x2) ||
		min(r2.x1, r2.x2) > max(r1.x1, r1.x2) ||
		min(r1.y1, r1.y2) > max(r2.y1, r2.y2) ||
		min(r2.y1, r2.y2) > max(r1.y1, r1.y2)) {
			return 0;
	}

	// else intersect
	int w = find_center_side(r1.x1, r1.x2, r2.x1, r2.x2);
	int h = find_center_side(r1.y1, r1.y2, r2.y1, r2.y2);

	return w * h;
}

int find_center_side(int a, int b, int c, int d) {
	
	int arr[] = {a, b, c, d};
	// sort array
	int i = 0;
	while (i < 3) {
		if (arr[i] > arr[i+1]) {
			swap(arr+i, arr+i+1);
			i = 0;
			continue;
		}
		i++;
	}
	return arr[2] - arr[1];
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}