#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdarg>
#include "recode.h"

int abio_printf(char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	char* str866 = (char*) malloc(strlen(fmt)+1);
	recode1251to866(fmt, str866);
	int retval = vprintf(str866, ap);
	free(str866);
	va_end(ap);
	return retval;
}

int abio_getString(char* str) {
	char str866[256];
	scanf("%s", str866);
	return recode866to1251(str866, str);
}

int abio_getMobilePhone(char* str) {
	// NEED TO USE FROM A NEW LINE
	int len = 0;
	bool done = false;
	while (!done) {
		printf("\r");
		for (int i = 0; i < 25; ++i) {
			printf(" ");
		}
		printf("\r+7 (");
		for (int i = 0; i < len; ++i) {
			putch(str[i]);
			if (i == 2) {
				printf(") ");
			} else if (i == 5) {
				printf(" ");
			} else if (i == 9) {
				printf(" (Enter)");
			}
		}
		char c = getch();
		if (c >= '0' && c <= '9' && len < 10) {
			str[len++] = c;
		} else if (c == 8 && len > 0) {
			--len;
		} else if (c == '\r' && len == 10) {
			done = true;
		}
	}
	printf("\n");
	str[len] = 0;
	return len;
}

int abio_getPhone(char* str) {
	int len = 0;
	bool done = false;
	while (!done) {
		printf("\r");
		if (len > 0) {
			for (int i = 0; i < 12; i++) {
				printf(" ");
			}
			printf(" (Enter)");
		} else {
			for (int i = 0; i < 20; i++) {
				printf(" ");
			}
		}
		str[len] = 0;
		printf("\r%s", str);
		char c = getch();
		if (c >= '0' && c <= '9' && len < 12) {
			str[len++] = c;
		} else if (c == 8 && len > 0) {
			--len;
		} else if (c == '\r' && len > 0) {
			done = true;
		}
	}
	printf("\n");
	str[len] = 0;
	return len;
}