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
	abio_print("Добро пожаловать в интерактивную электронную записную книгу AddressBook.\n");
}

void exitBook() {
	abio_print("Спасибо за использование AddressBook.\nПока-пока. ;)\n");
	exit(0);
}