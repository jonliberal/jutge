#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VVE grid, v;
int m = 1000000;
int L, W;



void f(int i, int j, int c){
  if(i == L){
    if(c < m) m = c;
    return;
  }
  if(j < 0 or j == W) return;
  if(grid[i][j] == -3) return;
  
  if(v[i][j] != -1){
    if(v[i][j] <= c) return;
  }
  v[i][j] = c;
  if(grid[i][j] == -2) c += 3;
  f(i+1, j, c);
  f(i+1, j-1, c+1);
  f(i+1, j+1, c+1);




}

int main(){
  cin >> W >> L;
  grid = v = VVE(L, VE(W, -1));
  char c;
  int xs = 0;
  for(int i = 0; i < L; i++){
    for(int j = 0; j < W; j++){
      cin >> c;
      if(c == 'M') xs = j;
      if(c == 'T') grid[i][j] = -2;
      if(c == '*'){
        grid[i][j] = -3;
        v[i][j] = -10;
      }
    }
  }
  f(0,xs,0);
  if(m == 1000000) cout << "IMPOSSIBLE" << endl;
  else cout << m << endl;
}
