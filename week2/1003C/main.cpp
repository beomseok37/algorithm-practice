#include <bits/stdc++.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int n, k, temp;
  int temperature[5005];
  int total = 0;
  int maxTotal = 0;
  double tempAnswer, answer = 0.0;
  scanf("%d%d", &n, &k);
  for(int i=1;i<=n;i++){
    scanf("%d",&temperature[i]);
    if(i<k) {
      total += temperature[i];
    }
  }
  temperature[0] = 0;
  for(int i=k;i<=n;i++){
    total = total - temperature[i-k];
    temp = total;
    for(int j=0;j<=n-i;j++){
      temp += temperature[i+j];
      tempAnswer = (double) temp/(double) (k+j);
      if(answer < tempAnswer){
        answer = tempAnswer;
      }
    }
    total += temperature[i];
  }
  printf("%lf\n",answer);
  return 0;
}
