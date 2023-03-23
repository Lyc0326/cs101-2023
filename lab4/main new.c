/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void replace_all(char* str, char oldChar, char newChar) {
    while (*str != '\0') {
       *str == oldChar ? *str = newChar : 0;
       str++;
    }
}

int main() {
    char str[100], oldChar = 'a', newChar='A';
    printf("Enter any string: ");
    scanf("%s", str);

    printf("\nString before replacing: \n%s", str);
    replace_all(str, oldChar, newChar);
    printf("\n\nString after replacing %c with %c : \n%s\n", oldChar, newChar, str);

    return 0;
}
