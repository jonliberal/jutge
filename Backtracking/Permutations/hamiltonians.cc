#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
typedef vector<bool> VB;

int n;
VVE v;

VE w;
VB u;


void f(int k, int j, int c){
  if(k == 0 and j != 0){
    if(j >= n){
      cout << 0;
      for(int i = 0; i < n; i++) cout << " " << w[i];
      cout << " " << "(" << c <<  ")" << endl;
    }
    return;
  }
  for(int i = 0; i < n; i++){
    if((not u[i]) and v[k][i] != 0){
      u[i] = true;
      w[j] = i;
      f(i, j + 1 ,c + v[k][i]);
      u[i] = false;
    }
  }
}

int main(){
  while(cin >> n){
    v = VVE(n,VE(n));
    w = VE(n);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++) cin >> v[i][j];
    }
    u = VB(n, false);


    w[0] = 0;
    f(0,0,0);
    for(int z = 0; z < 20; z++) cout << "-";
    cout<< endl;
  }
}
