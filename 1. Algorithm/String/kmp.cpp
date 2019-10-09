// kmp
#include <stdio.h>

#define STR_MAX 100
char str[] = "ccccccabcdabcdabcefab";
char key[] = "abcdabcef";
int failure[STR_MAX];
int keyLen, strLen;


int my_strlen(char* str) {
	int len = 0;
	while (*str++) {
		len++;
	}
	return len;
}

void createTable() {
	int len = keyLen - 1;
	for (int i = 1, j = 0; i<len; i++) {

		if (j > 0 && key[i] != key[j]) {

			j = 0;
		}

		if (key[i] == key[j]) {
			failure[i + 1] = ++j;
		}
	}

}
int kmp_match() {
	int i = 0, j = 0;

	while (i<strLen && j<keyLen) {
		if (str[i] == key[j])
			i++, j++;
		else if (j == 0)
			i++;
		else
			j = failure[j];
	}

	return ((j == keyLen) ? (i - keyLen) : -1);
}


int main() {
	int i;
	keyLen = my_strlen(key);
	strLen = my_strlen(str);
	createTable();
	printf("kmp table [");

	for (i = 0; i < keyLen; i++)
		printf("%d ", failure[i]);
	puts("]");

	printf("%d\n", kmp_match());

	return 0;
}