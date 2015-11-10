/*
 * simple.c
 * solve a^3+b^3+c^3 = 1000^2*a + 1000*b + c
 * in brute force
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



static int doit(void) {
	int finds = 0;
	int64_t a, b, c;

	for (a=0; a<1000; a++) {
		int64_t proda = a * a * a;
		int64_t a10 = 1000000 * a;
		for (b=0; b<1000; b++) {
			int64_t prodb = b * b * b;
			int64_t b10 = 1000 * b;
			for (c=0; c<1000; c++) {
				int64_t s1 = proda + prodb + c * c * c;
				int64_t s2 = a10 + b10 + c;
				if (s1 == s2) {
					finds++;
					printf("(%3d, %3d, %3d => %9d) %3d^3 + %3d^3 + %3d^3 == 1000^2*%3d + 1000*%3d + %3d\n", 
							a, b, c, s1, 
							a , b, c, a, b, c);
				}
			}
		}
	}
		return finds;
}

int main(void) {
	int finds = 0;

	printf ("solving a^3+b^3+c^3 = 1000^2*a + 1000*b + c\n");
	printf ("trying all combinations...\n");
	finds = doit();
	printf ("there are %d solutions\n", finds);
	return EXIT_SUCCESS;
}
