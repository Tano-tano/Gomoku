#include <stdio.h>

int main(){
    FILE* fp;
    char *fname = "field.csv";
    

    fp = fopen(fname, "w");
    fclose(fp);

    return 0;
}