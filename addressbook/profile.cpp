#include <cstdlib>
#include <conio.h>
#include "profile.h"
#include "abio.h"

Profile* requestProfile() {
	abio_print(
		"��� ������ ������ ���������� ������� ��� ��������� �������.\n"
		"�������� ���� �� ���������, ����� ����� �� ����������:\n"
		"(1) ������� �������\n"
		"(2) ��������� �������\n"
		"(0) ������\n");
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
			abio_print("[!] ������������ ����\n");
		}
	}
}
