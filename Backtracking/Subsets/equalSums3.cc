#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;

int s, n;
VE x,v, m;

void printSet(int k){
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

void f(int k, int j, bool added){
  if (j == s and added){
    printSet(k);
    //return;
  }
  if (k == n) return;
  if(j > s) return;
  if(s - j > m[k]) return;
  v[k] = 0;
  f(k+1, j, false);
  v[k] = 1;
  f(k+1, j + x[k], true);
}

int main(){
  cin >> s >> n;
  x = VE(n);
  v = VE(n, 0);
  m = VE(n);
  for(int i = 0; i < n; i++) cin >> x[i];
  m[n-1] = x[n-1];
  for(int i = 1; i < n; i++) m[n-i-1] = x[n-i-1] + m[n-i];
  f(0,0, false);


}
