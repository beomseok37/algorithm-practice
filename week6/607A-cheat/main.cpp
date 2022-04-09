#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>

int N;
int destroyed[1000001]; //destroy[i] = i position의 비콘이 파괴하는 비콘 수
vector<pii> PL;

int lowerBound(int s, int e, ll v) {
  while (s < e) {
    int mid = (s + e) / 2;
    if (PL[mid].first >= v)
      e = mid;
    else
      s = mid + 1;
  }
  return s;
}



int main(void) {
  FIO;

  cin >> N;

  PL.push_back(make_pair(0, 0));
  for (int i = 1; i <= N; i++)
  {
    int a, b;
    cin >> a >> b;
    PL.push_back(make_pair(a, b));
  }

  sort(PL.begin(), PL.end());

  for (size_t i = 1; i <= N; i++)
  {
    int nextPos = lowerBound(1, N, PL[i].first - PL[i].second) - 1;

    destroyed[i] = i - nextPos - 1 + destroyed[nextPos];
  //i번째를 activate하면 몇 개가 부숴지는지
  }

  int ans = 10000000;
 
  for (int i = 1; i <= N; i++)
  {
    ans = min(ans, destroyed[i] + N - i);
  }

  cout << ans <<endl;
}

//Reference By https://wasd222.blogspot.com/2020/04/codeforce-chain-reaction607a.html
