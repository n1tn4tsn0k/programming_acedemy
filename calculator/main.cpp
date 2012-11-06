#include <cstdio>
#include <cstdlib>
#include <cstring>

int evalute(char*);
int evalute(char*, int);
int calculate(char*);
int calculate(char*, int);

bool digit(char);

int main() {

	printf("Enter arithmetic expression: ");
	char exp[256];
	scanf("%s", exp);
	int result = evalute(exp);
	printf("Result: %d\n", result);

	system("pause");

	return 0;
}

int evalute(char* exp) {

	return evalute(exp, strlen(exp));
}

int evalute(char* exp, int len) {

	char* _exp = strdup(exp); // DON'T FORGET TO FREE

	// Find and calculate subexpressions with
	// decreasing priority
	for (int i = 0; i < len; i++) {
		if (_exp[i] == '*' || _exp[i] == '/') {
			// Find sides of subexpression
			int beg, end;
			for (beg = i-1; digit(_exp[beg]); --beg); ++beg;
			for (end = i+1; digit(_exp[end]) || _exp[end] == '*' || _exp[end] == '/'; ++end);

			// Calculate it
			int res = calculate(_exp+beg, end-beg);
			char res_s[256];
			sprintf(res_s, "%d", res);

			// Put inside the source expression
			// instead of calculated subexpression
			char tmp[256];
			strcpy(tmp, _exp+end);
			strcpy(_exp+beg, res_s);
			int res_end = beg + strlen(res_s);
			strcpy(_exp+res_end, tmp);
			i = res_end;
		}
	}

	int res = calculate(_exp, len);
	free(_exp);

	return res;
}

int calculate(char* exp) {

	return calculate(exp, strlen(exp));
}


int calculate(char* exp, int len) {

	int res = 0;
	int i = 0;
	while (digit(exp[i])) {
		res *= 10;
		res += exp[i]-'0';
		++i;
	}
	while (i < len) {
		char op = exp[i];
		int v = 0;
		++i;
		while (digit(exp[i])) {
			v *= 10;
			v += exp[i]-'0';
			++i;
		}
		if (op == '+') {
			res += v;
		} else if (op == '-') {
			res -= v;
		} else if (op == '*') {
			res *= v;
		} else if (op == '/') {
			if (v == 0) {
				puts("Error! Division by zero was found in the expression!");
				system("pause");
				exit(1);
			}
			res /= v;
		}
	}

	return res;
}

bool digit(char n) {
	return (n >= '0' && n <= '9');
}
