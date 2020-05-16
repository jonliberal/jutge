#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

typedef vector<bool> VB;
typedef vector<VB> VVB;

VVE v;
VVB grid;
int n,m;

int f(int i, int j){
  if(i < 0) return 0;
  if(j < 0) return 0;

  if(grid[i][j]) return 0;
  if(v[i][j] != -1) return v[i][j];
  int res = f(i - 1, j) + f(i, j - 1);
  if(res >= 1000000) res = 1000000;
  return v[i][j] = res;
}

int main(){
  cin >> n >> m;
  while(n != 0){
    v = VVE(n, VE(m, -1));
    grid = VVB(n, VB(m, false));
    char c;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> c;
        if (c == 'X') grid[i][j] = true;
      }
    }
    v[0][0] = 1;
    int res = f(n-1, m-1);
    if(res == 1000000) cout << "!!!"<< endl;
    else cout << f(n-1, m-1)<< endl;
    cin >> n >> m;

  }
}
