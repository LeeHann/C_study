#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#define STUDENT_MAX 1000

int score[STUDENT_MAX][3]; //성적
char name[STUDENT_MAX][8]; //이름
int tail_Index = -1;

int main(int argc, char *argv[])
{

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    char _sel_menu;

    printf("1. input score \n");
    printf("2. del score \n");
    printf("3. edit score \n");
    printf("4. get total score \n");
    printf("5. get average \n");
    printf("p. print score \n");
    printf("q. quit \n");

    _sel_menu = getchar();
    rewind(stdin); 
    switch (_sel_menu)
    {
    case '1': //input score
    //lee,80,70,85
      printf("input score [name,kor,eng,math] \n");
      {
        char _tokenBuffer[32][8];
        int _tokenIndex = 0;
        int _index = 0;

        char _c;
        do {
          _c = getchar();
          
          if(_c == ',') {
            _tokenBuffer[_tokenIndex][_index] = 0x00;
            _tokenIndex++;
            _index = 0;          
          }
          else 
          {
            _tokenBuffer[_tokenIndex][_index++] = _c;
          }

        } while(_c != '\n');
        _tokenBuffer[_tokenIndex][_index] = 0x00;
        printf("%s %s %s %s \n",_tokenBuffer[0],_tokenBuffer[1],_tokenBuffer[2],_tokenBuffer[3]);

        tail_Index++;
        strcpy(name[tail_Index],_tokenBuffer[0]);
        score[tail_Index][0] = atoi(_tokenBuffer[1]);
        score[tail_Index][1] = atoi(_tokenBuffer[2]);
        score[tail_Index][2] = atoi(_tokenBuffer[3]);
      }
      break;

    case '2' : //del score
      if(tail_Index < 0){
        printf("there's no person to remove\n");
      }
      else {
        for(int i=0; i<=tail_Index; i++){
          puts(name[i]);
        }
        printf("select person who want to remove : \n");
        char select[8];
        gets(select);
        for(int i=0; i<=tail_Index; i++){
          if(!strcmp(select, name[i])){
            name[i][0] = '\0';
            for(int j=0; j<3; j++){
              score[i][j] = 0;
            }
            for(int j=i; j<tail_Index; j++){
              strcpy(name[j], name[j+1]);
              for(int k=0; k<3; k++){
                score[j][k] = score[j+1][k];
              }
            }
            tail_Index--;
            break;
          }
          if(i==tail_Index){
            printf("there's no person like that\n");
          }
        }
      }
      break;

    case '3' : //edit score
      if(tail_Index < 0){
        printf("there's no person to edit\n");
      }
      else {
        for(int i=0; i<=tail_Index; i++){
          puts(name[i]);
        }
        printf("select person who want to edit : \n");
        char select[8];
        gets(select);
        for(int i=0; i<=tail_Index; i++){
          if(!strcmp(select, name[i])){
            printf("input edit data(name,First-score,Second-score,Third-score :\n");
            {
              char _tokenBuffer[32][8];
              int _tokenIndex = 0;
              int _index = 0;

              char _c;
              do {
              _c = getchar();
          
              if(_c == ',') {
                _tokenBuffer[_tokenIndex][_index] = 0x00;
                _tokenIndex++;
                _index = 0;          
              }
              else 
              {
                _tokenBuffer[_tokenIndex][_index++] = _c;
              }

              }while(_c != '\n');
              _tokenBuffer[_tokenIndex][_index] = 0x00;
              printf("%s %s %s %s \n",_tokenBuffer[0],_tokenBuffer[1],_tokenBuffer[2],_tokenBuffer[3]);

              strcpy(name[i],_tokenBuffer[0]);
              score[i][0] = atoi(_tokenBuffer[1]);
              score[i][1] = atoi(_tokenBuffer[2]);
              score[i][2] = atoi(_tokenBuffer[3]);
            }
            break;
          }
          if(i==tail_Index){
            printf("there's no person like that\n");
          }
        }
      }
      break;

    case '4' : //get total score
      if(tail_Index < 0) printf("there's no personal information");
      else{
        for(int i=0; i<=tail_Index; i++){
          puts(name[i]);
        }
        printf("select person whose score to get total : \n");
        char select[8];
        gets(select);
        for(int i=0; i<=tail_Index; i++){
          if(!strcmp(select, name[i])){
            int _total = 0;
            for(int j=0; j<3; j++){
              _total += score[i][j];
            }
            printf("total score is %d\n", _total);
            break;
          }
          if(i==tail_Index){
            printf("there's no person like that\n");
          }
        }
      }
      break;

    case '5' : //get average
      if(tail_Index < 0) printf("there's no personal information");
      else{
        for(int i=0; i<=tail_Index; i++){
          puts(name[i]);
        }
        printf("select person whose score to get average : \n");
        char select[8];
        gets(select);
        for(int i=0; i<=tail_Index; i++){
          if(!strcmp(select, name[i])){
            int _total = 0;
            for(int j=0; j<3; j++){
              _total += score[i][j];
            }
            float _average = _total/3;
            printf("the average is %f\n", _average);
            break;
          }
          if(i==tail_Index){
            printf("there's no person like that\n");
          }
        }
      }
      break;

    case 'p':
      {
        printf("---------------------------\n");
        for(int i=0;i<=tail_Index;i++)
        {
          printf("%8s%4d%4d%4d\n",name[i],score[i][0],score[i][1],score[i][2]);
        }
        printf("press any key......");
        getchar();
        rewind(stdin);
      }
      break;

    case 'q':
      bLoop = SDL_FALSE;
      break;

    default:
      break;
    }
  }
  return 0;
}