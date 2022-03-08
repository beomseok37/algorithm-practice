#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main(){
  char A[200];
  int i;
  scanf("%s",A);
  for(i=0;A[i] != '\0';i++){
    if(A[i] == 'A' || A[i] == 'O' || A[i] == 'Y' || A[i] == 'E' || A[i] == 'U' || A[i] == 'I' ||
    A[i] == 'a' || A[i] == 'o' || A[i] == 'y' || A[i] == 'e' || A[i] == 'u' || A[i] == 'i');
    else{
      printf(".");
      if(A[i]>='A' && A[i] <='Z') {
        A[i] += 'a' - 'A';
      }
      printf("%c",A[i]);
    }
  }
  printf("\n");
  return 0;
}
