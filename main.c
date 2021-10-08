#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mystring.h"

int main() {

	printf("DW's tester's verdict:\n");
	char s1[100];
	char s2[100] = "hello";
	char s3[100] = "goodbye";

	printf("start strings:\n");
	printf("s1: [%s]\n", s1);
	printf("s2: [%s]\n", s2);
	printf("s3: [%s]\n", s3);

	printf("\nTesting strlen(s2):\n");
	printf("[standard]:\t%lu\n", strlen(s2) );
	printf("[mine]:\t\t%d\n", mystrlen(s2) );

	printf("\nTesting strcpy(s1, s2):\n");
	printf("[standard]:\t[%s]\n", strcpy(s1, s2) );
	printf("[mine]:\t\t[%s]\n", mystrcpy(s1, s2) );

	printf("\nTesting strncpy(s1, s3, 3):\n");
	printf("[standard]:\t[%s]\n", strncpy(s1, s3, 3) );
	printf("[mine]:\t\t[%s]\n", mystrncpy(s1, s3, 3) );

	printf("\nTesting strcat(s1, s3):\n");
	printf("[standard]:\t[%s]\n", strcat(s1, s3) );
	s1[5] = 0;
	printf("[mine]:\t\t[%s]\n", mystrcat(s1, s3) );

	printf("\nTesting strncat(s1, s2, 3):\n");
	printf("[standard]:\t[%s]\n", strncat(s1, s2, 3) );
	s1[12] = 0;
	printf("[mine]:\t\t[%s]\n", mystrncat(s1, s2, 3) );

	printf("\nTesting strchr(s1, 'l'):\n");
	printf("[standard]:\t[%p]\n", strchr(s1, 'l') );
	printf("[mine]:\t\t[%p]\n", mystrchr(s1, 'l') );

	printf("\nTesting strchr(s1, 0):\n");
	printf("[standard]:\t[%p]\n", strchr(s1, 0) );
	printf("[mine]:\t\t[%p]\n", mystrchr(s1, 0) );

	printf("\nTesting strchr(s1, 'z'):\n");
	printf("[standard]:\t[%p]\n", strchr(s1, 'z') );
	printf("[mine]:\t\t[%p]\n", mystrchr(s1, 'z') );

	printf("\nTesting strcmp\n");
	printf("\tComparting ab to abc:\n");
	printf("\t\t[standard]:\t[%d]\n", strcmp("ab", "abc") );
	printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("ab", "abc") );
	printf("\tComparting abc to ab:\n");
	printf("\t\t[standard]:\t[%d]\n", strcmp("abc", "ab") );
	printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("abc", "ab") );
	printf("\tComparting abc to abc:\n");
	printf("\t\t[standard]:\t[%d]\n", strcmp("abc", "abc") );
	printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("abc", "abc") );

	printf("\nMy stress tester verdict (len, cat, ncpy, cmp, chr):\n");
	int failed = 0;
	for (int test = 0; test < 1000; test++) {
		srand(time(NULL) + test*31415926);
		char s[1000];
		char t[1000];
		// random lengths
		int slen = rand()%200+200, tlen = rand()%200+200;
		// random characters from a to z
		for (int i = 0; i < slen; i++) s[i] = rand()%26 + 'a';
		for (int i = 0; i < tlen; i++) t[i] = rand()%26 + 'a';
		s[slen]=t[tlen]=0;
		// mystrlen test
		if (strlen(s) != mystrlen(s)) failed=1;
		if (strlen(t) != mystrlen(t)) failed=1;
		char copy1[1000], copy2[1000];
		for (int i = 0; i < 1000; i++) copy1[i]=copy2[i]=0;
		// mystrncpy test
		int copylen = rand()%slen;
		strncpy(s, copy1, copylen);
		mystrncpy(s, copy2, copylen);
		if (strcmp(copy1, copy2)!=0) failed=1;
		// mystrcmp test
		int res1 = strcmp(s, t), res2 = mystrcmp(s, t);
		if ((res1<0) != (res2<0)) failed=1;
		if ((res1==0) != (res2==0)) failed=1;
		if ((res1>0) != (res2>0)) failed=1;
		// mystrcat test
		strcat(copy1, t);
		mystrcat(copy2, t);
		if (strcmp(copy1, copy2) != 0) failed=1;
		// mystrchr test
		for (char c = 'a'; c <= 'z'; c++) {
			if (strchr(copy1, c) != mystrchr(copy1, c)) failed=1;
		}
		if (failed) break;
	}
	if (failed) printf("u suck :P\n");
	else printf("ur cool B)\n");

	printf("\nRandom tests (str, split):\n");
	char s[100] = "congratsyoufoundit\0";
	char t[100] = "fou\0";
	printf("\nTesting strstr:\nMine:     [%p]\nStandard: [%p]\n", mystrstr(s, t), strstr(s, t));
	printf("\nTesting Split:\n");
	strcpy(s, "word,word,word\0");
	printf("Before split: [%s]\n", s);
	printf("Comma split:  [%s]\n", mysplit(s, ','));

	return 0;
}
