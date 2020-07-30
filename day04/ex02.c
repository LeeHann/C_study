#include <stdio.h>

int Sum(int value1, int value2){ // _Sum, _hn_sum
    int result = value1 + value2;
    return result;
}

void Test(){
    printf("test call 1 \n");
    return ;
    printf("test call 2 \n");
}

void main(){
    // call Sum pass 2, 3 
    int _value = Sum(2, 3);
    printf("Hello World! %d \n", _value);

    Test();
}

/* Basic code

10 LET A = 1
15 A = A + 1
20 PRINT A 
25 IF A > 10 THEN GOTO 40
30 GOTO 15
40 PRINT "END"

RUN 10

*/