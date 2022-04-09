#include <bits/stdc++.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int binary_search(int arr[], int size, int number){
  int first,last,middle;
  first = 1; last = size;
  while(first<last){
    middle=(first+last)/2;
    if(arr[middle]>=number){
      last=middle;
    } else {
      first = middle+1;
    }
  }
  return first-1;
}

int main(){
  int a[100005],dp[100005];
  int n,i,temp,answer;
  map<int, int> c;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&a[i],&temp);
    c[a[i]]=temp;
  }
  sort(a+1,a+n+1);
  dp[0]=0;dp[1]=0;
  answer = 1000000;
  for(i=2;i<=n;i++){
    temp = binary_search(a,n,a[i]-c[a[i]]);
    dp[i]=dp[temp]+i-temp-1;
  }
  for(i=1;i<=n;i++){
    answer=min(answer,dp[i]+n-i);
  }
  printf("%d\n",answer);
  return 0;
}
