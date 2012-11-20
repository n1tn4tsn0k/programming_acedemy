#include <cstdlib>
#include "main.h"
#include "abio.h"
#include "profile.h"

int main() {
	printGreetings();

	Profile* profile = requestProfile();
	if (profile == NULL) {
		exitBook();
	}

	return 0;
}

void printGreetings() {
	abio_print("����� ���������� � ������������� ����������� �������� ����� AddressBook.\n");
}

void exitBook() {
	abio_print("������� �� ������������� AddressBook.\n����-����. ;)\n");
	exit(0);
}