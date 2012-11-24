#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include "profile.h"
#include "abio.h"

Profile* requestProfile() {
	abio_printf(
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
			// load existing profile names
			int profileCount = loadProfileCount();
			char** profiles = (char**) malloc(sizeof(char*) * profileCount);
			for (int i = 0; i < profileCount; ++i) {
				profiles[i] = (char*) malloc(256);
			}
			loadProfileNames(profiles);
			abio_printf("������� �������� ��� ������� ��� �������(�����) ��� ������: ");
			char profileName[256];
			bool ok = false;
			while (!ok) {
				abio_getString(profileName);
				if (strcmp(profileName, "-") == 0) {
					break;
				}
				// check on existance of entered name in the list
				bool exists = false;
				for (int i = 0; i < profileCount; ++i) {
					if (strcmp(profileName, profiles[i]) == 0) {
						exists = true;
						break;
					}
				}
				if (exists) {
					abio_printf("���, ������� � ����� ������ ��� ����������. ���������� �����: ");
				} else {
					ok = true;
				}
			}
			if (ok) {
				return createProfile(profileName);
			} else {
				return NULL;
			}

		case '2':
			return NULL;

		case '0':
			return NULL;

		default:
			abio_printf("[!] ������������ ����\n");
		}
	}
}

int loadProfileCount() {
	FILE* f = fopen("profiles.abl", "r");
	if (f == NULL) {
		return -1;
	}
	int n;
	int res = fscanf(f, "%d", &n);
	fclose(f);
	if (res == EOF) {
		return -1;
	} else {
		return n;
	}
}

void loadProfileNames(char** profileNames) {
	FILE* f = fopen("profiles.abl", "r");
	int n;
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", profileNames[i]);
	}
	fclose(f);
}
