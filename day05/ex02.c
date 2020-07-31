#include <stdio.h>

int main()
{
    int _i=5;
    int _a;
    
    printf("%d \n",_i);
    //i=i+1; add 
    _i++; // inc
    printf("%d \n",_i);

    _a = _i++;
    printf("%d \n",_a);
    printf("%d \n",_i);
    
    _a = ++_i;
    printf("%d \n",_a);

    return 1;
}