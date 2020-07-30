#include <stdio.h>

//void Test(char *strMsg);
void Test(char *);

void main(){
    Test("Hi ~ ");
}

void Test(char *strMsg){
    printf("test call 1 %s \n", strMsg);
}