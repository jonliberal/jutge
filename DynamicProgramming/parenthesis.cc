#include<iostream>
#include<vector>

using namespace std;
#define LL long long

typedef vector<LL> VLL;
VLL v;



LL parenthesis(LL n){
  if(v[n] != -1) return v[n];
  if(n == 0) return v[0] = 1;
  LL res = 0;
  for(int i=0; i<n; i++){
    res += parenthesis(n-i-1)*parenthesis(i);
  }
  return v[n] = res;
}

int main(){
  int n;
  v = VLL(100, -1);
  LL res = -1;
  while(cin >> n){
    if (n % 2 == 1) res = 0;
    else res = parenthesis(n/2);
    cout << res << endl;
  }


}
