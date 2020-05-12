#include<iostream>
#include<vector>

using namespace std;
#define ULLI long long

ULLI parenthesis(vector<ULLI> &v, int n){
  if(v[n] != -1) return v[n];
  if(n == 0) return v[0] = 1;
  int res = 0;
  for(int i=0; i<n; i++){
    res += parenthesis(v,n-i-1)*parenthesis(v,i);
  }
  return v[n] = res;
}

int main(){
  int n;
  vector<ULLI> v(500, -1);
  ULLI res = -1;
  while(cin >> n){
    if (n % 2 == 1) res = 0;
    else res = parenthesis(v, n/2);
    cout << res << endl;
  }


}
