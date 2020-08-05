# C언어 정리
-참고 "C언어 입문", 김성엽 지음

1. 역사
1972년 벨 연구소의 Dennis Ritchie, Ken Thompson이 개발한 언어
Unix 개발에 활용

2. 특징
1) 구조화({}/중괄호 활용)
2) 이식성(여러 프로그램에 높은 호환율)
3) 확장성(표현의 다양성)
4) 생산성

3. 컴파일형 언어
소스파일.c-(컴파일)-목적파일.obj-(링크)-실행파일.exe
소스파일.c-(빌드)-실행파일.exe

4. 자료형
정수형
    - char  | 1 byte
    - short | 2 byte
    - int   | 4 byte
    - long  | 4 byte
실수형
    - float         | 4 byte
    - double        | 8 byte
    - long double   | 8 byte 이상
- usigned(부호비트 이용)를 덧붙이면 표현 범위 2배

5. 진수표현
- 2진수 : 0b00 (C99이후)
- 8진수 : 000
- 10진수: 0000
- 16진수: 0x00

6. C 언어 코드 구조
#전처리기 // = #include <stdio.h> // #include <stdlib.h> ...

함수 프로토 타입 or 함수
//프로토 타입 ex/ int f();

int(or void) main(int argc, char* argv[]){
    main 함수 내용
}
// return(반환) 의미 :
return 0; return 1; -> 프로그램이 오류 없이 완료함
                    -> 프로그램이 정상적으로 작업을 끝내고 종료됨, 성공적으로 실행됨, 그 상태를 반환
함수 내에서 return -> 함수의 결과값을 함수를 호출했던 곳에 대치

(위에 함수를 프로토타입으로 선언해뒀을 경우, 함수 정의)
ex/ int f(){함수 내용}

7. 함수 구조
호출자가 아래에 있어야 함수가 제대로 작동
-프로토 타입이 호출자 위에 선언되면 함수 정의가 호출자 밑에 있어도 됨

int Sum(int value1, int value2){ // 반환형 함수이름(자료형 매개변수, ...)
    // 내용
    int result = value1 + value2; 
    
    //자료형에 따른 반환
    return result;
}

8. 빌드

일반 소스파일
- gcc file.c -o file.exe
- ./file.exe

라이브러리 파일 만들기
- gcc lib.c -c -o lib.o
- 컴파일(complier) -> -o // obj -> -c
- 링킹(linking) -> .exe

두 개의 오브젝트 파일 합치기
ar r libex04.a(출력파일) ./ex04_lib.o ./ex04_lib2.o(병합할 파일/들)
gcc ex04.c -o ex04.exe -L ./ -lex04 
-L (경로)
라이브러리 계열 확장자 .a, 접두사는 반드시 lib
ex/ libxxxx.a => 실제이름은 xxxx => -lxxxx 

어셈블리 파일 출력
gcc -S -o out.asm src.c

9. if-else if-else 조건문
c의 컴파일러가 스택을 사용하여 if문을 받아서 else if의 사용이 많아지면 비효율적이다.
따라서 else if 의 사용이 많으면 switch문을 이용하는 것이 효율적이다. 

python은 인터프리터 형 언어이기 때문에 위와 같은 효율성의 문제가 없어 switch문이 없다.