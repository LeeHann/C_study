#include <stdio.h>

int Sum(int value1, int value2);
int Mul(int value1, int value2);

int main(){
    int rest = Sum(2, 3);
    int rest2 = Mul(2, 3);
    printf("result is %d \n", rest);
    printf("result is %d \n", rest2);
    
    return 1;
}