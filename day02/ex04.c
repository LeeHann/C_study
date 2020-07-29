//char형 변수 출력
#include <stdio.h>

int main(){
    char _c; // 1byte, ascii

    //_c = 'A';
    printf("input character : ");
    scanf("%c", &_c);
    printf("result : %c \n", _c);
    
    return 0;
}