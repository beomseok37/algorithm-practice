#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int n;
  long long answer;
  int a[100005];
  long long dp[2][100005];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }  
  sort(a,a+n);
  dp[0][0]=0; dp[1][0]=a[0];
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      dp[0][i] = dp[0][i-1];
      dp[1][i] = dp[1][i-1]+a[i];
    } else if(a[i] == a[i-1]+1){
      dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
      dp[1][i] = dp[0][i-1]+a[i];
    } else {
      dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
      dp[1][i] = max(dp[0][i-1],dp[1][i-1])+a[i];
    }
  }
  answer = max(dp[0][n-1],dp[1][n-1]);
  printf("%lld\n",answer);

  return 0;
}
