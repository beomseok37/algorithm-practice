#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int arr[4],a2;
  int a1 = 5000001;
  
  for(int i=0;i<4;i++){
    scanf("%d",&arr[i]);
    a1 = i!=1?min(a1,arr[i]):a1;
  }
  arr[0] = arr[0]>a1?arr[0]-a1:0;
  a2 = min(arr[0],arr[1]);
  printf("%d\n",a1*256+a2*32);
  return 0;
}
