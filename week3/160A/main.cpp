#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(){
  int n, coins[100], answer=0, mySum=0, sum=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&coins[i]);
    sum += coins[i];
  }
  qsort(coins,n,sizeof(int),compare);

  for(int i=n-1;i>=0;i--){
    answer++;
    mySum += coins[i];
    if(sum/2<mySum)
      break;
  }
  printf("%d\n",answer);
  return 0;
}
