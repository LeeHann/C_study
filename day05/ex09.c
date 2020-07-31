#include <Stdio.h>

int main(){
    int data;

    puts("input data  : ");
    scanf("%d", &data);

    if(data == 10){
        data = 0;
    }
    //if(data != 10){
    else{
        data++;
    }

    printf("%d \n", data);

    return 1;
}