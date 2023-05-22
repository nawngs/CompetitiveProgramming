#include <stdio.h>

int input(char *s,int length);

int main(void) {
	freopen("ahihi.inp", "r", stdin);
	freopen("ahihi.out", "w", stdout);
 	char buffer[32];
    char *b = buffer;
    size_t bufsize = 32;
    size_t characters;
    characters = getline(&b,&bufsize,stdin);
    printf("%zu characters were read.\n",characters);
}