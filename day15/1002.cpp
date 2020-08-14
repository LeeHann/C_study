#include <iostream>
#include <cmath>
using namespace std;

int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int r1_r2 = r1+r2;
    double length = pow(x1-x2, 2) + pow(y1-y2, 2);
    length = sqrt(length);

    if(length == 0) {
      if(r1 == r2)
        cout << -1 << "\n";
      else
        cout << 0 << "\n";
    }
    else if(r1_r2 > length){
      //내접
      
      //겹치기
      cout << 2 << "\n";//2점에서 만난다
    
    }
    else if(r1_r2 == length) cout << 1 << "\n"; //1점에서 만난다
    else if(r1_r2 < length) cout << 0 << "\n";  //만나지 않는다
  }
  return 0;
}