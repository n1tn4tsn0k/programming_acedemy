#include <cstdlib>
#include <cstdio>
#include <cstring>
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