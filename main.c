#include <stdio.h>

int main(){
    FILE* fp;
    char *fname = "field.csv";

    int player = 1;

    fp = fopen(fname, "r");
    if(fp == NULL){
        fclose(fp);
        fp = fopen(fname, "w");
    }










    fclose(fp);



    return 0;
}