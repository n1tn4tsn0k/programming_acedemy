#include <cstdlib>
#include <conio.h>
#include "profile.h"
#include "abio.h"

Profile* requestProfile() {
	abio_print(
		"Для начала работы необходимо создать или загрузить профиль.\n"
		"Выберите один из вариантов, нажав цифру на клавиатуре:\n"
		"(1) Создать профиль\n"
		"(2) Загрузить профиль\n"
		"(0) Отмена\n");
	char op;
	for (;;) {
		op = getch();
		switch (op) {
		case '1':
			//return createProfile();
			return NULL;

		case '2':
			return NULL;

		case '0':
			return NULL;

		default:
			abio_print("[!] Некорректный ввод\n");
		}
	}
}
