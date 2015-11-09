/*
 * simple.c
 * solve a^3+b^3+c^3 = 1000^2*a + 1000*b + c
 * in brute force
 */

#include <stdio.h>
#include <stdlib.h>

static int finds = 0;

static void doit(void) {
	int a, b, c;

	for (a=0; a<1000; a++) {
		int proda = a * a * a;
		int a10 = 1000000 * a;
		for (b=0; b<1000; b++) {
			int prodb = b * b * b;
			int b10 = 1000 * b;
			for (c=0; c<1000; c++) {
				int s1 = proda + prodb + c * c * c;
				int s2 = a10 + b10 + c;
				if (s1 == s2) {
					finds++;
					printf("(%3d, %3d, %3d => %9d) %3d^3 + %3d^3 + %3d^3 == 1000^2*%3d + 1000*%3d + %3d\n", 
							a, b, c, s1, 
							a , b, c, a, b, c);
				}
			}
		}
	}
}

int main(void) {
	printf ("solving a^3+b^3+c^3 = 1000^2*a + 1000*b + c\n");
	printf("trying al combinations...\n");
	doit();
	return EXIT_SUCCESS;
}
