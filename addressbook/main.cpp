#include <cstdlib>
#include <cstdio>
#include "main.h"
#include "abio.h"
#include "profile.h"

int main() {
	printGreetings();

	//free(phone);
	/*
	Profile* profile = requestProfile();
	if (profile == NULL) {
		exitBook();
	}
	*/

	return 0;
}

void printGreetings() {
	abio_printf("����� ���������� � ������������� ����������� �������� ����� AddressBook.\n");
}

void exitBook() {
	abio_printf("������� �� ������������� AddressBook.\n����-����. ;)\n");
	exit(0);
}