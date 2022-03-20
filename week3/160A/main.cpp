#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main(){
  int n, coins[100], answer=0, mySum=0, sum=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&coins[i]);
    sum += coins[i];
  }
  sort(coins,coins+n);

  for(int i=n-1;i>=0;i--){
    answer++;
    mySum += coins[i];
    if(sum/2<mySum)
      break;
  }
  printf("%d\n",answer);
  return 0;
}
