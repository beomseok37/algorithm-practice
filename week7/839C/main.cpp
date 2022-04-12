#include <bits/stdc++.h>
#include <cstring>
#include <stdio.h>
#include <vector>
using namespace std;
 
int n;
 
class Node{
  public:
  int pt;
  int nChild;
  vector<int> AD;
};
 
Node C[100005];
 
void dfs1(int nd, int pt){
  int i,s;
  C[nd].pt = pt;
  s=C[nd].AD.size();
  C[nd].nChild=0;
  for (i=0;i<s;i++){
    if(C[nd].AD[i] != C[nd].pt){
      C[nd].nChild++;
      dfs1(C[nd].AD[i],nd);
    }
  }
}
 
double dfs2(int nd){
  int i,s;
  double returnValue;
  returnValue = 0.0;
  if(C[nd].nChild==0)return 0.0;
  s=C[nd].AD.size();
  for (i=0;i<s;i++){
    if(C[nd].AD[i] != C[nd].pt){
      returnValue += dfs2(C[nd].AD[i])+1;
    }
  }
  return returnValue/C[nd].nChild;
}
 
int main(){
  int i,x,y;
  double answer;
  scanf("%d",&n);
  for(i=1;i<n;i++){
    scanf("%d%d",&x,&y);
    C[x].AD.push_back(y);
    C[y].AD.push_back(x);
  }
  dfs1(1,0);
  answer=dfs2(1);
  printf("%f\n",answer);
  return 0;
}
