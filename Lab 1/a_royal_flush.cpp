#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:    
   vector<int> rotation(int n)
  {
      vector<int>ans;
      int arr[1001]={0}; 
      queue<int>q;
      for(int i=1;i<=n;i++)
      {
          q.push(i);
      }
      int i=1;
      while(!q.empty())
      {
          int j=0;
          while(j<i)
          {
              int x=q.front();
              q.pop();
              q.push(x);
              j++;
          }
          int x=q.front();
          if(arr[x]!=0)
          {
              ans.push_back(-1);
              return ans;
          }
          arr[x]=i;
          q.pop();
          i++;
      }
      for(int i=1;i<=n;i++)
      ans.push_back(arr[i]);
      
      return ans;
  }
};

int main()
{
   Solution obj;
   int t;
   cin>>t;
   while(t--)
   {
       int n; 
       cin >> n;
       vector<int>ans;
       ans = obj.rotation(n);
       for(int i:ans)
           cout<< i << " ";
       cout << endl;
       
   }
   return 0;
}
