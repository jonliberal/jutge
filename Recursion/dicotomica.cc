
#include<iostream>
#include<vector>
using namespace std;

// check if value x is in sorted vector v (and if necessary, where)
bool dicotomica(const vector<int> &v, int x, int e, int d){
  if (e > d) return false;
  int m = (e+d)/2;
  if (v[m] > x) return dicotomica(v, x, e, m-1);
  if (v[m] < x) return dicotomica(v, x, m+1, d);
  return true;

}

int main(){
  int x, n;
  cin >> x >> n;

  vector<int> V(n);
  for(int i=0; i < n; i++){
    cin >> V[i];
  }
  cout << dicotomica(V, x, 0, n-1);

}
