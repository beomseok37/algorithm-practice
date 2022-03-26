#include <stdio.h>

using namespace std;

long long recursion(long long n, long long l, long long r){
  long long nn, mid, length;
  nn = n/2; length = 1;
  while (nn > 0) {
    length = length * 2 + 1; nn/=2;
  }

  if (l == 1&& r == length) return n;
  mid = (length+1)/2;
  if (l > mid) return recursion(n/2, l-mid, r-mid);
  if (r < mid) return recursion(n/2, l, r);
  if (l == mid && r==mid) return n%2;
  if (l == mid) return recursion(n/2, 1, r-mid) + n%2;
  if (r == mid) return recursion(n/2, l, r)+n%2;
  return recursion(n/2,l,mid-1)+recursion(n/2,1,r-mid)+n%2;
}

int main(){
  long long n,l,r;
  scanf("%lld%lld%lld",&n,&l,&r);
  
  printf("%d", recursion(n,l,r));
  return 0;
}
