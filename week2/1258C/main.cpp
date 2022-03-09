#include <stdio.h>

using namespace std;

int main(){
  long long t, n,total,MN,ans;
  long long a[100005];
  long long prefix[100005];
  long long m[100005];
  scanf("%lld",&t);
  prefix[0]=0;
  for(int i=1;i<=t;i++){
    scanf("%lld",&n);
    for(int j=1;j<=n;j++){
      scanf("%lld",&a[j]);
      prefix[j]=prefix[j-1]+a[j];
    }
    total = prefix[n];
    ans = 1;
    MN = 0;
    for (int j=1;j<n;j++){
      m[j] = prefix[j] - MN;
      if(MN>prefix[j])
        MN=prefix[j];
      if(total<=m[j])
        ans=0;
    }
    for(int j=1;j<=n;j++)
      prefix[j] -= a[1];
    MN = 0;
    for (int j=2;j<=n;j++){
      m[j] = prefix[j] - MN;
      if(MN>prefix[j])
        MN=prefix[j];
      if(total<=m[j])
        ans=0;
    }
    if(ans==1)printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
