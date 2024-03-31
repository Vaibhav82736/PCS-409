#include <bits/stdc++.h>
using namespace std;
void count()
{
    int size,i;
    cout<<"Enter the number of alphabet::"<<endl;
    cin>>size;
    char str[size];
    char ch;
    cout<<"Enter the alphabets::"<<endl;
    for ( i = 0; i < size; i++)
   {
       cin>>str[i];
   }
   int freq[26] = { 0 };
   int maxf = -1;
   for ( i = 0; i < size; i++)
   {
       freq[str[i] - 'a']++;
   }
   for ( i = 0; i < 26; i++)
   {
      if (maxf < freq[i]) 
      {
         maxf = freq[i];
      }
   }
   if(maxf == 0)
   {
       cout<<"No duplicate present"<<endl;
       return;
   }
   cout<<"Maximum number of frequency is of::";
   for ( i = 0; i < 26; i++)
   {
      if (freq[i]==maxf) 
      {
          ch= (char)(i + 'a');
          cout<<endl<<ch<<endl;
          cout<<"The frequency of character is::"<<endl;
          cout<<freq[i];
         
      }
   }
}
int main()
{
   int Testcase,i;
   cout<<"Enter the number of testcases::"<<endl;
   cin >>Testcase ;
   for(i=0;i<Testcase;i++)
   {
       cout<<endl<<"Testcase "<<i+1<<endl;
       count();
   }
   return 0;
}