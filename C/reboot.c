/* 
 * File:   reboot.c
 * Author: marcel
 *
 * see section reboot in doc/doc.pdf
 * 
 * Created on 10 novembre 2015, 16:25
 */

#include <stdio.h>
#include <stdlib.h>

static int doitAll(void) {
    int a, b;
    int finds = 0;

    for (a = 0; a < 100; a++) {
        int a2 = a * a;
        int centa = 100 * a;
        for (b = 0; b < 100; b++) {
            int s1 = a2 + b*b;
            int s2 = centa + b;
            if (s1 == s2) {
                finds++;
                printf("(%3d, %3d => %9d) %3d^2 + %3d^2 == 100*%3d + %3d\n",
                        a, b, s1,
                        a, b, a, b);
            }
        }
    }
	return finds;
}

static int doitNice(void) {
    int a, b;
	int alpha, gamma;
    int finds = 0;

    for (alpha = 0; alpha < 50; alpha++) {
        int s2 = alpha * (50 - alpha);
        for (gamma = 0; gamma < 25; gamma++) {
            int s1 = gamma * (4 * gamma - 1);
        
            if (s1 == s2) {
                finds++;
				a = 2*alpha;
				b = 4*gamma;
                printf("(%3d, %3d => %9d) %3d^2 + %3d^2 == 100*%3d + %3d\n",
                        a, b, s1,
                        a, b, a, b);
            }
        }
    }
    for (alpha = 0; alpha < 50; alpha++) {
        int s2 = 2 * alpha * (50 - alpha);
        for (gamma = 0; gamma < 25; gamma++) {
            int s1 = gamma * (2 * gamma + 1);
        
            if (s1 == s2) {
				int r;

                finds++;
				a = 2*alpha;
				b = 2*gamma + 1;
				r = 100 * a + b;
                printf("(%3d, %3d => %9d) %3d^2 + %3d^2 == 100*%3d + %3d\n",
                        a, b, r,
                        a, b, a, b);
            }
        }
    }
	return finds;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int finds = 0;

    printf("solving a^2+b^2 = 100^2*a + b\n");
    printf("trying all combinations...\n");
    finds = doitAll();
    printf("there are %d solutions\n", finds);
    printf("trying some combinations...\n");
    finds = doitNice();
    printf("there are %d solutions\n", finds);

    return (EXIT_SUCCESS);
}

