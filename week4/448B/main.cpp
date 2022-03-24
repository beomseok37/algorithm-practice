#include <stdio.h>

using namespace std;

int dp(int arr[],int size) {
  int start,end,newAnswer,answer = 0;
  int minHeight = 1000000001;
  for(int i=0;i<size;i++){
    minHeight = minHeight>arr[i]?arr[i]:minHeight;
  }
  answer += minHeight;
  for(int i=0;i<size;i++){
    arr[i] -= minHeight;
  }
  start=0;
  while (start<size){
    if(arr[start]==0){
      start++;
      continue;
    }
    end=start;
    while(end+1<size && arr[end+1] != 0)end++;
    newAnswer = dp(arr+start,end-start+1);
    answer += newAnswer;
    start = end+1;
  }
  return answer<size?answer:size;
}

int main(){
  int n,arr[5005];
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&arr[i]);
  }
  printf("%d\n",dp(arr,n));
  return 0;
}
