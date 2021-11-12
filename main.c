#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isUsed(int, int);
int faul(int, int);

int main(){
    FILE* fp;
    char* name = "field.csv";

    int cnt = 0;//文字数
    int charcnt = 0;
    int turn = 1;
    char* field = "";
    char buf[1000];


    int player = 1;
    srand((unsigned int)time(NULL));

    //ファイルがあるか確認
    fp = fopen(name, "r");
    if(fp == NULL){
        printf("no file");
    }

    //====================================
    //碁石を置く座標
    int x = rand()%15;
    int y = rand()%15;

    //ファイルの長さを取得
    while(1){	
        charcnt = fgetc(fp) ;
        if (charcnt == EOF){
            break ;
        }
        cnt ++ ;
    }

    //プログラム番号を設定
    if((cnt/6) % 2 != 0){
        player = 2; //1,1:1:1 → 7文字なので 6で割ったら奇数
    }else{
        player = 1; //2,1:1:1,2:2:2 → 13文字なので6で割ったら偶数
    }

    //碁石があるかの確認
    isUsed(x, y);

    //禁手確認
    if(player == 1) faul(x, y);


    //====================================


    //ターン数の設定
    if(cnt != 0){
        fseek(fp, 0, SEEK_SET);
        turn = fgetc(fp) - '0' + 1;
        printf("%d/n", turn);
        //現在の盤面を保存
        fseek(fp, 1, SEEK_SET);
        field = fgets(buf, 1000, fp);
    }

    //ターン数の書き込み
    fp = fopen(name, "w");
    fprintf(fp, "%d", turn);
    fclose(fp);
    
    //配置場所の書き込み
    fp = fopen(name, "a");
    fprintf(fp, "%s", field);
    fprintf(fp, ",%d:%d:%d", player, y, x); // (プログラム番号:縦:横)
    fclose(fp);

    return 0;
}

//石が置いてあるかどうか
int isUsed(int x, int y){
    return 0;
}

//禁手判定
int faul(int x, int y){
    return 0;
}