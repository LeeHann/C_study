#include <stdio.h>

int main(){
  char input_str[10];

  if(!gets(input_str)){
    printf("input cancel\n");
  }
  else printf("%s \n", input_str);

  return 0;
}