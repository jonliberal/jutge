#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> VE;
typedef vector<bool> VB;
VE c, w;
VB v;


int n,g;

bool f(int i, int k){
  if(i > g) return true;
  if(i == g){
    cout << w[0];
    for(int j = 1; j < k; j++) cout << ',' << w[j];
    cout << endl;
    return false;

  }

  if(v[i]){
    return true;

  }
  bool reachable = false;
  for(int j = 0; j < n; j++){
    w[k] = c[j];
    reachable  = (reachable or !f(i + c[j], k + 1));
  }
  return v[i] = !reachable;


}

int main(){
  while(cin >> n){
    c = VE(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());
    cin >> g;
    v = VB(g, false);
    w = VE(g);
    if(f(0, 0)) cout << -1 << endl;
  }



}
