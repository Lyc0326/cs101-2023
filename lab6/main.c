/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int multi(int i, int j) {
    if (i > 9) {
        return 0;
    }
    printf("%d*%d=%d ", i, j, i*j);
    if (!(j %= 9)) {
        i++;
        printf("\n");
    }
    return multi(i, j+1);
}

int main() {
    multi(1,1);
    return 0;
}
