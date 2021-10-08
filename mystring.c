#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mystrlen( char *s ) {
	int ans = 0;
	while (*s++) ans++;
	return ans;
}

char * mystrcpy( char *dest, char *source ) {
	char *copy = dest;
	while (*source) {
		*dest = *source;
		source++; dest++;
	}
	*dest=0;
	return copy;
}

char * mystrncpy( char *dest, char *source, int n) {
	char *copy = dest;
	int i, zero=0;
	for (i = 0; i < n; i++) {
		if (zero) *dest=0;
		else {
			*dest = *source;
			if (*source==0) zero=1;
		}
		dest++; source++;
	}
	return copy;
}

char * mystrcat( char *dest, char *source ) {
	char *copy = dest;
	while (*dest) dest++;
	while (*source) {
		*dest = *source;
		dest++; source++;
	}
	*dest = 0;
	return copy;
}

char * mystrncat( char *dest, char *source, int n) {
	char *copy = dest;
	while (*dest) dest++;
	int i;
	for (i=0; i < n; i++) {
		if (*source==0) break;
		*dest = *source;
		dest++; source++;
	}
	*dest = 0;
	return copy;
}

int mystrcmp( char *s1, char *s2 ) {
	unsigned char *p1 = s1, *p2 = s2;
	while (*p1>0 || *p2>0) {
		if (*p1>*p2) return 1;
		if (*p1<*p2) return -1;
		p1++; p2++;
	}
	return 0;
}

char * mystrchr( char *s, char c ) {
	while (*s != c && *s != 0) s++;
	if (*s==c) return s;
	return 0;
}

char * mystrstr( char *s1, char * s2 ) {
	while (*s1) {
		char *c1 = s1, *c2 = s2;
		int match = 1;
		while (*c2) {
			if (*c1 != *c2) {
				match = 0;
				break;
			}
			c1++; c2++;
		}
		if (match) return s1;
		s1++;
	}
	return 0;
}

char * mysplit(char *s, char d) {
	char *copy = s;
	while (*s) {
		if (*s==d) *s=0;
		s++;
	}
	// return value wasn't specified, sorry in advance if this is wrong
	return copy;
}
