#include <cstring>
#include "recode.h"

void recode866to1251(char* from, char* to) {
	strcpy(to, from);
    for (char* c = to; *c != 0; ++c) {
        if (*c > -129 && *c < -80) {
            *c += 64;
		} else if (*c > -33 && *c < -16) {
            *c += 16;
		}
    }
}

void recode1251to866(char* from, char* to) {
	strcpy(to, from);
    for (char* c = to; *c != 0; ++c) {
        if ((*c - 64) > -129 && (*c - 64) < -80) {
            *c -= 64;
		} else if ((*c - 16) > -33 && (*c - 16) < -16) {
            *c -= 16;
		}
    }
}