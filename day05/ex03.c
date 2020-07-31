#include <stdio.h>

int main()
{
    int _i = 0;

    printf("%d \n",_i++);
    printf("%d \n",_i);

    printf("%d \n",++_i);

    printf("%d %d \n",++_i,++_i); //?

    printf("%d %d \n",_i++,_i++);  //?
    printf("%d \n",_i);


    return 1;
}
