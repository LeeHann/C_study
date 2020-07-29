//분기문을 활용한 계산
#include <stdio.h>

int main(){
    char _operation;
    int _a, _b;

    printf("input a operation b : ");
    scanf("%d %c %d", &_a, &_operation, &_b);

    if(_operation == '+'){
        // 덧셈
        printf("%d + %d = %d \n", _a, _b, _a+_b);
    }
    else if(_operation == '-'){
        //뺄셈
        printf("%d - %d = %d \n", _a, _b, _a-_b);
    }
    else if(_operation == '*'){
        //곱셉
        printf("%d * %d = %d \n", _a, _b, _a*_b);
    }
    else if(_operation == '/'){
        //나눗셈
        printf("%d / %d = %d \n", _a, _b, _a/_b);
    }
    else if(_operation == '%'){
        //나머지
        printf("%d %c %d = %d \n", _a, '%',_b, _a%_b);
    }
    else{
        printf("operation error \n");
    }

    return 0;
}