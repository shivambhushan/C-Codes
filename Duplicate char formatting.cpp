#include <bits/stdc++.h>
using namespace std;

void Duplicate_String(char *str, char current, int index)
{
  if (str[index]=='\0')
  {
    return;
  }
  if (str[index]==current)
  {
    for (int i = strlen(str); i >= index; i--)
    {
      str[i+1]=str[i];
    }
    str[index]='*';
    current='*';
  }
  else
  {
    current = str[index];
    Duplicate_String(str,current,index+1);
  }
    Duplicate_String(str,current,index+1);
    
}

int main() 
{
  char str[1000];
  cin>>str;
  int n = sizeof(str)/sizeof(int);
  if(n==0 || n==1)
  {
    return 0;
  }
  Duplicate_String(str, '*', 0);
  cout<<str;
  return 0;
}