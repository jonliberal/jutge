#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> VE;

int s, n;
VE x,v;
bool found;

void printSet(int k){
  found = true;
  cout << "{";
  bool started = false;
  for(int i = 0; i < k; i++){
    if(v[i] == 1){
      if(started) cout << ",";
      cout << x[i];
      started = true;
    }
  }
  cout << "}"<< endl;
}

void f(int k, int j){
  if (found) return;
  if (k == n){
    if (j == s){
      printSet(k);
    }
    return;

  }
  v[k] = 1;
  f(k+1, j + x[k]);
  v[k] = 0;
  f(k+1, j);
}

int main(){
  cin >> s >> n;
  x = VE(n);
  v = VE(n, 0);
  for(int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end(), greater<int>());

  found = false;
  f(0,0);
  if(not found) cout << "no solution" << endl;


}
