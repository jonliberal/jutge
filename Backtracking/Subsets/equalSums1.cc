#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;

int s, n;
VE x,v;

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
  v[k] = 0;
  f(k+1, j, false);
  v[k] = 1;
  f(k+1, j + x[k], true);
}

int main(){
  cin >> s >> n;
  x = VE(n);
  v = VE(n, 0);
  for(int i = 0; i < n; i++) cin >> x[i];
  f(0,0, true);


}
