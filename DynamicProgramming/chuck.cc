#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;

VE v, dp;
int n;

void f(){
  for(int i = n-1; i >= 0; i--){
    for(int j = n-1; j > i; j--){
      if(v[i] + 10 <= v[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  int maxn = -1;
  for(int i = 0; i < n; i++) if(dp[i] > maxn) maxn = dp[i];
  cout << maxn << endl;
}
int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> n;
    v = VE(n);
    dp = VE(n, 1);
    for(int j = 0; j < n; j++) cin >> v[j];
    f();
  }


}
