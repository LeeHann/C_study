//정수형, 실수형 자료형 출력
#include <stdio.h>

int main(){
    int num1, num2;
    float real_1;

    scanf("%d%d%f", &num1, &num2, &real_1);
    printf("integer : %d %d \n", num1, num2);
    printf("float : %f \n", real_1);
    
    return 0;
}