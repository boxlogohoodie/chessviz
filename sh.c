    #include <stdio.h>
    #include <string.h>

    int main() {
    int i;
    char a[9][9];
    char gl[]={'r','n','b','q','k','b','n','r'};
    char p='p';
    memset(a, ' ', sizeof(a));

    //цыфры
    for (i=0; i<8; i++) {
    a[i][0]=56-i;
    }
    // буквы
    for (i=1; i<9; i++){
    a[8][i]=96 + i;
    }

    for (i= 1;i<9; i++) {
    a[0][i] = gl[i-1];
    a[7][i] = gl[i-1];
    a[1][i] = p;
    a[6][i] = p-32;
    }
    for (i=0;i<9;i++) {
    for (int g=0;g<9; g++){
    printf("%c", a[i][g]);
    }
    printf("\n");
    }
    return 0;
    }


