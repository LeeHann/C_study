#include <stdio.h>

int main()
{
    printf("%d %d %d %d \n",
        1 > 2,
        1 < 2,
        1 == 2,
        1 != 2
    );

    printf( "%d \n", ((1==1) && (2>1)) ); // 둘 모두
    printf( "%d \n", ((1!=1) || (2>1)) ); // 둘중하나

    printf( "%d \n", 1 && 1 && 1 ); 
}