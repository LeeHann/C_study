//int형 변수의 출력
#include <stdio.h>

int main(){
    int _a, _b;

    //_a = 1;
    //_b = 2;
    printf("input two num : ");
    scanf("%d %d", &_a, &_b);
    printf("result : %d \n", _a + _b);

    return 0;
}