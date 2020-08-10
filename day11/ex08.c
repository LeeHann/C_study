#include <stdio.h>

/*
struct People
{
  char id;
  int age;
  int height;
};
typedef struct People people;
*/

typedef struct //People
{
  char id;
  int age;
  int height;
}people;

int main(){
  people data;

  data.id = 'a';
  data.age = 22;
  data.height = 156;

  printf("%c %d %d\n", data.id, data.age, data.height);
  return 0;
}