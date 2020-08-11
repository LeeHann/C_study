# 파일 사용 형식

t : text 속성으로 파일 사용 ex/fopen("file", "rt");
b : binary 속성으로 파일 사용 ex/fopen("file", "rb");

모드
r : 읽기 모드
w : 쓰기 모드
a : 이어쓰기 모드

+ : rw모드, 강조모드
r+: 파일이 없으면 파일 읽기 실패
w+: 파일이 없으면 새로 만들고, 있으며 기존 파일을 지우고 새로 시작

ex / code - 
{
  #include <stdio.h>
  int main(){
    FILE *fp;
    fp = fopen("file.txt", "r");
    
    while(NULL != fgets(strBuf, sizeof(strBuf), fp)) 
      printf("%s\n", strBuf);
  
    fclose(fp);
  }
}

binary file
fseek : 오프셋 지정
fread : 현재 오프셋 기준으로 바이트 단위로 파일 읽기


