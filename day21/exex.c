#include <stdio.h>

int main()
{
  char szBuf[7] = "1+2-3+4";
  int ans1 = szBuf[0] - '0', ans2;
  for (int i = 0; i < sizeof(szBuf); i++)
  {
    ans2 = szBuf[i + 1]-'0';
    if (szBuf[i] == '+')
    {
      ans1 = ans1 + ans2;
      printf("%d ", ans1);
    }
    else if (szBuf[i] == '-')
    {
      ans1 = ans1 - ans2;
      printf("%d ", ans1);
    }
    else if (szBuf[i] == '*')
    {
      ans1 = ans1 * ans2;
    }
    else if (szBuf[i] == '/')
    {
      ans1 = ans1 / ans2;
    }
  }
  printf("%d ", ans1);
  return 0;
}