#include<iostream>
#include<vector>

using namespace std;

typedef vector<bool> VB;
typedef vector<int> VE;

VB u;
VE v;
int n;

void printPerm(){
  cout << "(";
  bool started = false;
  for(int i = 0; i < n; i++){
    if(started) cout << ',';
    cout << v[i]+1;
    started = true;
  }
  cout << ")" << endl;
}

void f(int k){
  if(k == n){
    printPerm();
    return;
  }
  for(int i = 0; i < n; i++){
    if(not u[i]){
      u[i] = true;
      v[k] = i;
      f(k+1);
      u[i] = false;
    }
  }

}

int main(){
  cin >> n;
  u = VB(n, false);
  v = VE(n);
  f(0);
}
