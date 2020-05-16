#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

VVB u;
VVC v;
int n, m, xe, ye;
VC path;



void f(int i, int j, int k){

  if(i < 0 or i >= n) return;
  if(j < 0 or j >= m) return;
  if(u[i][j]) return;

  if(i == xe and j == ye){
    for(int e = 0; e < k; e++) cout << path[e];
    cout << v[i][j] << endl;
    //cout << k << endl;
    return;
  }

  path[k] = v[i][j];
  u[i][j] = true;


  int e = 0;
  int d1 = 1, d2 = 0;
  while(e < 4){

    //cout << "JA    " << i << "  " << j << "  " << k << "  "<< xe << ye <<endl;
    f(i + d1, j + d2, k + 1);
    // direction
    swap(d1,d2);
    d1 *= -1;
    e += 1;
  }
  u[i][j] = false;

}

int main(){
  cin >> n >> m;
  v = VVC(n, VC(m));
  u = VVB(n, VB(m, false));
  path = VC(n*m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> v[i][j];
  }
  int xs,ys;
  cin >> xs >> ys >> xe >> ye;
  f(xs, ys, 0);


}
