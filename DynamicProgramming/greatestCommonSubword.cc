#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
VVE dp;
string s1, s2;
int l1, l2;



int f(int i, int j, int l){
  cout << i << ' ' << j << endl;
  if(i == l1 or j == l2) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int r = max(f(i+1, j, 0), f(i, j+1, 0));
  if(s1[i] == s2[j]){
    cout << "similar" << endl;
    return dp[i][j] = max(f(i+1, j+1, l+1), r);
  }
  return dp[i][j] = max(r, l);
}

int main(){

  while(cin >> s1 >> s2){
    l1 = s1.length();
    l2 = s2.length();
    dp = VVE(l1, VE(l2, -1));
    for(int i = 0; i < l1; i++){
      for(int j = 0; j < l2; j++) cout << ' ' << dp[i][j];
      cout << endl;
    }
    cout << f(0,0,0) << endl;

    for(int i = 0; i < l1; i++){
      for(int j = 0; j < l2; j++) cout << ' ' << dp[i][j];
      cout << endl;
    }
  }
}
