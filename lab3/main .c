/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
typedef struct person {
    int id;
    char first_name[32];
    char last_name[32];
} person_t;

int main() {
    FILE* fp;
    fp = fopen("person.bin", "w+");
    person_t p[5] = { {1, "IU", "Lee"},
                      {2, "IUU", "Lee"},
                      {3, "IUUU", "Lee"},
                      {4, "IUUUU", "Lee"},
                      {5, "IUUUUU", "Lee"},
    };
    for (int i=0; i<5; i++) {
        fwrite(p+i, sizeof(person_t), 1, fp);
        // fwrite(p[i], sizeof(person_t), 1, fp);
    }
    fseek(fp, 0, SEEK_SET);
    person_t tmp;
    int i=0;
    while (fread(&tmp, sizeof(person_t), 1, fp)) {
        printf("[%d] %d: %s %s\n", i,
                tmp.id,
                tmp.first_name,
                tmp.last_name);
        i++;
    }
    fclose(fp);
                                                  
    return 0;
}
