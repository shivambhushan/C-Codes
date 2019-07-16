#include <bits/stdc++.h>
using namespace std;

int Convert_String(string str)
{
   if (str.length()==0)
   {
      return 0;
   }
   else
   { 
        //int answer=Convert_String(arr+1, n);
        int answer=stoi(str);
        return answer;
   }
}

int main() 
{
    string str;
    cin>>str;
    cout<<Convert_String(str)<<endl;
    return 0;
}