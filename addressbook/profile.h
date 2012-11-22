
#pragma once

enum RecordType { ADDRESS, MOBILE_PHONE, HOME_PHONE, OFFICE_PHONE, FAX, EMAIL, HOMEPAGE };

typedef struct {
	RecordType type;
	char* label;
	char* value;
} Record;

typedef struct {
	char* name;
	int recordCount;
	Record* records;
} User;

typedef struct {
	char* name;
	int userCount;
	User* users;
} Profile;

Profile* requestProfile();
