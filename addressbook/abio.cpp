#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include "recode.h"

void abio_print(char* str) {
	char* str866 = (char*) malloc(strlen(str)+1);
	recode1251to866(str, str866);
	printf(str866);
	free(str866);
}

char* abio_getString() {
	char str866[256];
	scanf("%s", str866);
	char* str = (char*) malloc(strlen(str866)+1);
	recode866to1251(str866, str);
	return str;
}

char* abio_getPhone() {
	// NEED TO USE FROM NEW LINE
	char buf[128];
	buf[0] = 0;
	bool done = false;
	while (!done) {
		int len = strlen(buf);
		printf("\r");
		for (int i = 0; i < 25; ++i) {
			printf(" ");
		}
		printf("\r+");
		for (int i = 0; i < len; ++i) {
			if (i == 1) {
				printf(" (");
			} else if (i == 4) {
				printf(") ");
			} else if (i == 7) {
				printf(" ");
			}
			putch(buf[i]);
		}
		if (len == 11) {
			printf(" (Enter)");
		}
		char c = getch();
		if (c >= '0' && c <= '9' && len < 11) {
			buf[len++] = c;
			buf[len] = 0;
		} else if (c == 8) {
			buf[--len] = 0;
		} else if (c == '\r' && len == 11) {
			done = true;
		}
	}
	printf("\n");
	return strdup(buf);
}
			
