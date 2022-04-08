#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

long long n, cost[100005];
char CO[100005], CR[100005], PO[100005], PR[100005];
long long ans, AO, AR, PAO, PAR;

int main(){
  int i, j, len;
  long long MAX = LLONG_MAX;
  scanf("%lld",&n);
  for(i=1;i<=n;i++)scanf("%lld",&cost[i]);

  scanf("%s",CO);
  len = strlen(CO);
  for(j=0;j<len;j++)CR[len-j-1]=CO[j];
  CR[len]='\0';
  AO=0; AR=cost[1];

  for(i=2;i<=n;i++){
    strcpy(PO,CO);strcpy(PR,CR);
    PAO=AO;PAR=AR;
    scanf("%s",CO);
    len = strlen(CO);
    for(j=0;j<len;j++)CR[len-j-1]=CO[j];
    CR[len]='\0';
    if (PAO==MAX && PAR==MAX){AO=MAX;AR=MAX;}
    else {
      AO=MAX;AR=MAX;
      if(strcmp(CO,PO)>=0 && PAO!=MAX)AO=PAO;
      if(strcmp(CO,PR)>=0 && PAR!=MAX)AO=min(AO,PAR);
      if(strcmp(CR,PO)>=0 && PAO!=MAX)AR=PAO+cost[i];
      if(strcmp(CR,PR)>=0 && PAR!=MAX)AR=min(AR,PAR+cost[i]);
    }
  }

  ans = AR==MAX&&AO==MAX?-1:min(AO,AR);
  printf("%lld\n",ans);
  return 0;
}
