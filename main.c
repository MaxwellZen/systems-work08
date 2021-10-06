#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mystring.h"

int main() {
	int failed = 0;
	for (int test = 0; test < 1000; test++) {
		srand(time(NULL) + test*31415926);
		char s[1000];
		char t[1000];
		for (int i = 0; i < 1000; i++) s[i]=t[i]=0;
		// random lengths
		int slen = rand()%200+200, tlen = rand()%200+200;
		// random characters from a to z
		for (int i = 0; i < slen; i++) s[i] = rand()%26 + 'a';
		for (int i = 0; i < tlen; i++) t[i] = rand()%26 + 'a';
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
	return 0;
}
