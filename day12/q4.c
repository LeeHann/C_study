//성적 처리 - 구조체 & 파일 처리
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <malloc.h>
#include <string.h>

typedef struct Student
{
  char name[32];
  int kor, eng, math;
  struct Student *next;
} student;

int _count = 0;

int main(int argc, char *argv[])
{
  student *p_student = NULL;

  p_student = (student *)malloc(sizeof(student));
  p_student->kor = 0;
  p_student->eng = 0;
  p_student->math = 0;
  strcpy(p_student->name, " ");
  p_student->next = NULL;

  FILE *fp;
  fp = fopen("student.txt", "r+");

  //파일 내용 연결리스트 만들기
  {
    char strBuf[32];
    while (NULL != fgets(strBuf, sizeof(strBuf), fp))
    {
      student *p = p_student;
      while (p->next != NULL)
      {
        p = p->next;
      }
      p->next = (student *)malloc(sizeof(student));
      p = p->next;

      char *pszTemp;
      //char szName[32];
      int v_kor, v_eng, v_math;

      const char *pszDelimiter = ",";
      pszTemp = strtok(strBuf, pszDelimiter);
      strcpy(p->name, pszTemp);

      pszTemp = strtok(NULL, pszDelimiter);
      v_kor = atoi(pszTemp);

      pszTemp = strtok(NULL, pszDelimiter);
      v_eng = atoi(pszTemp);

      pszTemp = strtok(NULL, pszDelimiter);
      v_math = atoi(pszTemp);

      p->kor = v_kor;
      p->eng = v_eng;
      p->math = v_math;
      p->next = NULL;
      _count++;
    }
  }

  SDL_bool bLoop = SDL_TRUE;

  while (bLoop)
  {
    printf("1. input score \n");
    printf("2. del score \n");
    printf("3. edit score \n");
    printf("4. get total score \n");
    printf("5. get average \n");
    printf("p. print score \n");
    printf("q. quit \n");

    char select_num;
    select_num = getchar();

    switch (select_num)
    {
    case '1': //입력
    {
      _count++;
      student *p = p_student;

      while (p->next != NULL)
        p = p->next;

      p->next = (student *)malloc(sizeof(student));
      p = p->next;
      printf("input student info\n");

      printf("%d student name : ", _count);
      scanf("%s", p->name);

      printf("korean : ");
      scanf(" %d", &p->kor);

      printf("english : ");
      scanf("%d", &p->eng);

      printf("mathmetics : ");
      scanf("%d", &p->math);

      p->next = NULL;

      fseek(fp, 0, SEEK_END);
      fprintf(fp, "\n%s,%d,%d,%d", p->name, p->kor, p->eng, p->math);
    }
    break;

    case '2': //삭제
    {
      if (_count < 1)
      {
        printf("there's no people to remove\n");
        break;
      }
      student *p = p_student;
      student *p_pre;
      student *p_next;
      char name[32];

      printf("input name whom you want to remove : ");
      scanf("%s", name);

      while (p != NULL)
      {
        p_next = p->next;
        if (!strcmp(p->name, name))
        {
          p_pre->next = p_next;
          free(p);
          break;
        }
        p_pre = p;
        p = p->next;
      }
      _count--;
    }
    break;

    case '3': // 수정
    {
      char name[32];
      char strBuf[32];
      printf("input name you want to edit : ");
      scanf("%s ", name);

      fseek(fp, 0, SEEK_SET);
      while (NULL != fgets(strBuf, sizeof(strBuf), fp))
      {
        char *pszTemp;
        char szName[32];

        const char *pszDelimiter = ",";
        pszTemp = strtok(strBuf, pszDelimiter);
        strcpy(szName, pszTemp);
        if (!strcmp(szName, name))
        {
          char v_name[32];
          int v_kor, v_eng, v_math;
          printf("input student info\n");

          printf("name : ");
          scanf("%s", v_name);

          printf("korean : ");
          scanf(" %d", &v_kor);

          printf("english : ");
          scanf("%d", &v_eng);

          printf("mathmetics : ");
          scanf("%d", &v_math);

          fprintf(fp, "\n%s,%d,%d,%d", v_name, v_kor, v_eng, v_math);
        }
      }
    }
    break;

    case '4': // 총점
      break;

    case '5': // 평균
      break;

    case 'p':
    {
      fseek(fp, 0, SEEK_SET);
      char strBuf[32];
      while (NULL != fgets(strBuf, sizeof(strBuf), fp))
      {
        char *pszTemp;
        char szName[32];
        int kor, eng, math;

        const char *pszDelimiter = ",";
        pszTemp = strtok(strBuf, pszDelimiter);
        strcpy(szName, pszTemp);

        pszTemp = strtok(NULL, pszDelimiter);
        kor = atoi(pszTemp);

        pszTemp = strtok(NULL, pszDelimiter);
        eng = atoi(pszTemp);

        pszTemp = strtok(NULL, pszDelimiter);
        math = atoi(pszTemp);

        printf("%s %d %d %d\n", szName, kor, eng, math);
      }
    }
    break;

    case 'q':
      bLoop = SDL_FALSE;
      break;

    default:
      break;
    }
  }

  fclose(fp);
  return 0;
}