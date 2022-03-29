#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int n, l[3];
  int d[3][5000];
  scanf("%d%d%d%d",&n,&l[0],&l[1],&l[2]);

  d[0][0] = d[1][0] = d[2][0] = 0;

  for(int i=1;i<=n;i++){
    for(int j=0;j<3;j++){
      if(i-l[j] < 0)
        d[j][i]=-1;
      else if(i-l[j] == 0)
        d[j][i]=1;
      else{
        if(max(max(d[0][i-l[j]],d[1][i-l[j]]),d[2][i-l[j]]) == -1){
          d[j][i] = -1;
        } else {
          d[j][i] = max(max(d[0][i-l[j]],d[1][i-l[j]]),d[2][i-l[j]])+1;
        }
      }
    }
  }
  printf("%d\n",max(max(d[0][n],d[1][n]),d[2][n]));
  return 0;
}
