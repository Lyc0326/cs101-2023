#include <stdio.h> //檔案開啟和關閉的標頭檔
#include <stdlib.h> //最初的一些設定
#include <time.h> //時間函數
#include <string.h> //strlen-求字串長度

int number[7] = {0};
static int counter = 0;
FILE* count;
FILE* lotto;

void print_number(int i) {
    int special;//最後會有一個special number
    for(int j=0; j<6; j++) {
        number[j] = rand()%69+1;//前面代表共69個數，後面代表從1開始
        for(int k=0; k<j; k++) {
            if(number[j]==number[k]) {
                j -=1;
                break;
            } 
        }
    }
    for(int a=0; a<5; a++) {
        for(int b=a+1; b<6; b++) {
            if(number[a]>number[b]) {
                int temp;
                temp = number[a];
                number[a] = number[b];
                number[b] = temp;
                
            }
        }
    }
    number[6] = rand()%10+1;//這個是最後的special number
    fprintf(lotto, "[%d]：", i);
    for(int a=0; a<7; a++) {
        fprintf(lotto, "%02d ", number[a]);
    }
    fprintf(lotto, "\n");
}

void print_nothing(int i) {
    fprintf(lotto, "[%d]：", i);
    for(int j=1; j<=7; j++) {
        fprintf(lotto, "-- ");
    }
    fprintf(lotto, "\n");
}

void count_sell() { //數到底賣出了幾張
    int arr_write[1]; //為什麼要加{0}，不加為什麼不可以
    int arr_read[1];
    if((count = fopen("count.bin", "r")) == NULL) {
        count = fopen("count.bin", "wb+");
        arr_write[0] = 1;
        fwrite(arr_write, sizeof(int), 1, count);
    } else {
        count = fopen("count.bin", "rb+");
        fseek(count, 0, SEEK_SET);
        fread(arr_read, sizeof(int), 1, count);
        fclose(count);
        arr_write[0] = arr_read[0]+1;
        count = fopen("count.bin", "wb+");
        fwrite(arr_write, sizeof(int), 1, count);
    } 
    fclose(count);
    counter = arr_write[0];
}

int main() {
    int n;
    char lotto_name[100];
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    while(n > 0) {
        if(n>5) {
            printf("請重新輸入(1~5張)：");
            scanf("%d", &n);
        } else break;
    }
    count_sell(count);
    sprintf(lotto_name, "lotto[%05d].txt", counter);
    lotto = fopen(lotto_name, "w+");
    //lotto = fopen("lotto.txt", "w+");
    fprintf(lotto, "========= lotto649 =========\n");
    fprintf(lotto, "========+ No.%05d +========\n", counter);
    time_t curtime;
    time(&curtime); //因為time後面有\n, 因此需要先計算字串長度，在減掉
    char* tmstr = ctime(&curtime); //變動記憶體，計算
    size_t length = strlen(tmstr);
    tmstr[length-1] = '\0';//把\n改成\0
    fprintf(lotto, "= %s =\n", tmstr);
    srand((unsigned) time(NULL));
    for (int i=1; i<=5; i++) {
        if (i<=n) {
            print_number(i);
        } else {
            print_nothing(i);
        }
    }
    fprintf(lotto, "========= csie@CGU =========");
    fclose(lotto);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto[%05d].txt\n", n, counter);
  
    return 0;
}


