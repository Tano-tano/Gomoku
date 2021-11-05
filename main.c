#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isOn(int, int);

int main(){
    FILE* fp;
    char* name = "field.csv";

    int cnt = 0;
    int charcnt = 0;
    int turn = 0;
    char field[256];

    int player = 1;
    srand((unsigned int)time(NULL));
    int x = rand()%15;
    int y = rand()%15;

    //ファイルがあるか確認
    fp = fopen(name, "w");
    if(fp == NULL){
        fprintf(fp, "%d", 0);
    }
    fclose(fp);


    fp = fopen(name, "r");
    //手番の更新
    rewind(fp);
    turn = fgetc(fp);
    fseek(fp, 0L, SEEK_END);

    //ファイルの長さから手番を確認
    while(1){	
        charcnt = fgetc(fp) ;
        if (charcnt == EOF){
            break ;
        }
        cnt ++ ;
    }
    fclose(fp);

    //これまでの結果をバッファに記録
    fp = fopen(name, "r");
    fseek(fp, 1L, SEEK_SET);
    fgets(field, 256, fp);
    fclose(fp);

    //プログラム番号を設定(ごり押し)
    if((cnt/6) % 2 != 0){
        player = 2; //1,1:1:1 → 7文字なので 6で割ったら奇数
    }else{
        player = 1; //2,1:1:1,2:2:2 → 13文字なので6で割ったら偶数
    }

    fp = fopen(name, "w");
    fprintf(fp, "%d", turn);
    fclose(fp);

    fp = fopen(name, "a");
    fprintf(fp, "%s", field);

    fprintf(fp, "%d:%d:%d", player, y, x); // (プログラム番号:縦:横)

    return 0;
}

//石が置いてあるかどうか
int isOn(int x, int y){
    return 0;
}