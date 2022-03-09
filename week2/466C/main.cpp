#include <stdio.h>
using namespace std;

int main(){
  long long n,total,third,firstCount;
  long long a[500005];
  long long prefix[500005];
  long long count = 0;
  scanf("%lld",&n);
  prefix[0]=0;
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    prefix[i] = prefix[i-1]+a[i];
  }
  total = prefix[n];
  if (total % 3 == 0){
    third = total/3;
    count=0;firstCount=0;
    for(int i=1;i<n;i++){
      if(third*2==prefix[i])
        count += firstCount;
      if(third == prefix[i])
        firstCount++;
    }
  }
  printf("%lld\n",count);
  return 0;
}
