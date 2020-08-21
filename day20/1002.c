#include <stdio.h>
#include <math.h>

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int x1, x2, y1, y2, r1, r2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    
    int r1_r2 = r1+r2;
    double length = pow(x1-x2, 2) + pow(y1-y2, 2);
    length = sqrt(length);

    if(length == 0) {
      if(r1 == r2)
        printf("-1\n");
      else
        printf("0\n");
    }
    else if(r1_r2 > length){
      int max = (r1>r2) ? r1 : r2;
      int min = (r1>r2) ? r2 : r1;
      //내접
      if((max-length) == min)
        printf("1\n");
      //겹치기
      printf("2\n");//2점에서 만난다
    }
    else if(r1_r2 == length) printf("1\n"); //외접, 1점에서 만난다
    else if(r1_r2 < length) printf("0\n");  //밖에서, 만나지 않는다
  }
  return 0;
}