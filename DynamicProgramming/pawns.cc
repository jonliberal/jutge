#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VVE v;
int r,c;

int f(int i, int j){
  if(j < 0 or j == 50) return 0;
  if(i == 50 - 1) return 1;
  if(v[i][j] != -1) return v[i][j];
  return v[i][j] = f(i+1, j-1) + f(i+1, j+1);
}
int main(){
  v = VVE(50, VE(50, -1));
  while(cin >> r >> c){
    int res = 0;

    //add
    for(int j = 0; j < c; j++){
      res += f(50 - r,j);
    }
    //subtract
    for(int j = 50 - r + 1; j < 50; j++){
      res -= f(j, c);
    }
    cout << res << endl;
    // for(int i = 49; i >= 0; i--){
    //   for(int j = 0; j < 50; j++) cout << ' ' << v[i][j];
    //   cout <<endl;
    // }
  }
}
