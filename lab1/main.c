/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1, 2, 3};
    int a_read[sizeof(a)/sizeof(a[0])];
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    FILE* fp;

    if ((fp = fopen("a.bin", "wb+")) == NULL) {
        printf("Cannot open the file...\n");
        exit(1);
    }

    if (fwrite(a, sizeof(a), 1, fp) != 1) {
        printf("File write error...\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);

    if(fread(a_read, sizeof(a_read), 1, fp) != 1) {
        printf("File read error...\n");
        exit(1);
    }

    for (int i=0; i<sizeof(a_read)/sizeof(a_read[0]); i++) {
        printf("%d ", a_read[i]);
    }
    printf("\n");
    return 0;
}
