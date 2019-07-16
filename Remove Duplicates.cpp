#include <bits/stdc++.h>
using namespace std;

void Remove_Duplicate(char *str, char current, int index)
{
  if (str[index]=='\0')
  {
    return;
  }
  if (str[index]==current)
  {
    for (int i = index; i < strlen(str); i++)
    {
      str[i]=str[i+1];
    }
    Remove_Duplicate(str,current,index);

  }
  else
  {
    current = str[index];
    Remove_Duplicate(str,current,index+1);
  }
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
  Remove_Duplicate(str, ' ', 0);
  cout<<str;
  return 0;
}