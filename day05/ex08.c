#include <stdio.h>

int main(){
    int data = 1;

    //if(data = 3){ // must be "true" value in rewrite 3
    //if(data == 3); { // 무조건 실행
    if(3 == data){ // use constant first -> reduce errors
        printf("data equal to 3 \n");
    }

    printf("completed %d \n", data);

    return 1;
}