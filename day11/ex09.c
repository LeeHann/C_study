#include <stdio.h>

typedef struct
{
  char szName[32];
  int kor;
  int eng;
  int math;
} S_Score;

void serScoreData(S_Score *pScore)
{
  scanf("%s %d %d %d",
        pScore->szName, //(*pScore).szName,
        &pScore->kor,
        &pScore->eng,
        &pScore->math);
}

int main()
{
  S_Score _score;
  scanf("%s %d %d %d", _score.szName, &_score.kor, &_score.eng, &_score.math);

  printf("name : %s \n", _score.szName);
  printf("kor : %d \n", _score.kor);
  printf("eng : %d \n", _score.eng);
  printf("math : %d \n", _score.math);

  return 0;
}