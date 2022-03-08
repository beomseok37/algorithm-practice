#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  char A[200];
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",A);
    if(strlen(A) <= 10){
      printf("%s\n",A);
    } else {
      printf("%c",A[0]);
      printf("%d",strlen(A)-2);
      printf("%c\n",A[strlen(A)-1]);
    }
  }
  return 0;
}
