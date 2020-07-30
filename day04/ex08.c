#include <stdio.h>

int main(){
    int data1 = -1;
    printf("%d %u\n", data1, data1); // -1 unsigned_value

    char data2 = -1;
    printf("%d %u\n", data2, data2); //8bit 정수형으로 넣어도 32bit 정수형으로 나온다.

    float pi = 3.14;
    printf("%f %e\n", pi, pi);
    
    return 1;
}