#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int n,mx,ans=0;
  int arr[105];
  int dp[2][105];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    ans += arr[i]==1?1:0;
    dp[0][i] = arr[i]==0?1:-1;
  }
  dp[1][0] = dp[0][0];
  mx = dp[1][0];
  for(int i=1;i<n;i++){
    dp[1][i] = dp[1][i-1]+dp[0][i]>dp[0][i]?dp[1][i-1]+dp[0][i]:dp[0][i];
    mx = max(mx,dp[1][i]);
  }
  
  printf("%d\n",ans+mx);
  return 0;
}
