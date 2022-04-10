#include <bits/stdc++.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
  int a[100005];
  int n,i,A,B,ALI,BLI,clen,ans;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<=n;i++){
    if(a[i]!=a[1])
      break;
  }
  if(i==n+1){printf("%d",n);return 0;}
  if(a[1]<a[i]){A=a[1];B=a[i];ALI=i-1;BLI=i;}
  else {A=a[i];B=a[1];ALI=i;BLI=i-1;}
  ans = clen = i;
  for(i=i+1;i<=n;i++){
    if(a[i]==A){ALI=i;clen++;}
    else if(a[i]==B){BLI=i;clen++;}
    else if(a[i]==A-1){clen=i-BLI;B=A;A=a[i];BLI=ALI;ALI=i;}
    else if(a[i]==B+1){clen=i-ALI;A=B;B=a[i];ALI=BLI;BLI=i;}
    ans = max(ans,clen);
  }
  printf("%d\n",ans);
  return 0;
}
