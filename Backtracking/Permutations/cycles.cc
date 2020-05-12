#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<bool> VB;

int n;
VE v;
VB u;

void f(int p, int c){
  if (c == n-1){
    v[0] = p;
    cout << "(" << v[0]+1;
    for(int i = 1; i < n; i++) cout << "," << v[i]+1;
    cout << ")" << endl;
  }

  for(int i = 0; i < n; i++){
    if(not u[i]){
      u[i] = true;
      v[i] = p;
      f(i, c+1);
      u[i] = false;
    }
  }
}

int main(){
  cin >> n;
  v = VE(n,0);
  u = VB(n, false);
  u[0] = true;
  f(0,0);
}
