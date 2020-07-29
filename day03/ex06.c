//진수 표현, 지수 표현
#include <stdio.h>

int main(){
    //지수형 표현
    float a = 1.52e-5;
    int _b = 0xFA;
    int _c = 012;
    //C99이후 2진수 표현
    int _d = 0b1011000;
    char *strMsg = "hello world";

    printf("%f %d %d %d \n", a, _b, _c, _d);
    printf("%s\n", strMsg);
    
    return 0;
}