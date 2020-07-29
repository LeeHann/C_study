//c언어 진번 출력 10진수, 16진수, 8진수
#include <stdio.h>

int main(){
    printf("input number : ");
    
    int num;
    scanf("%d", &num);
    printf("10 : %d,  16 : %x, 8 : %o\n", num, num, num); //10진수, 16진수, 8진수

    return 0;
}