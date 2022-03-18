#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, s[100005],temp,result=0,counts[5]={0,};
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&s[i]);
    counts[s[i]]+=1;
  }

  result += min(counts[1],counts[3]);
  counts[1] -= result;
  counts[3] -= result;

  result += counts[2]/2;
  counts[2] %= 2;

  temp = counts[1] != 1 ? min(counts[1]/2,counts[2]) : min(counts[1],counts[2]);
  result += temp;
  counts[1] -= counts[1] != 1 ? temp*2 : temp;
  counts[2] -= temp;

  result += (counts[1]%4 ? (counts[1]/4)+1 : counts[1]/4) + counts[2] + counts[3] + counts[4];

  printf("%d\n",result);

  return 0;
}
