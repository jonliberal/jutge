#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

typedef vector<bool> VB;
typedef vector<VB> VVB;

bool found;


VVE v;
VVB u, d1, d2, d3;

void f(int i, int j){
  if(i == 9){
    cout << endl;
    for(int x = 0; x < 9; x++){
      cout << v[x][0];
      for(int y = 1; y < 9; y++){
        cout << ' ';
        cout << v[x][y];
      }
      cout << endl;
    }
    found = true;
    return;
  }
  if(found) return;
  if(j == 9){
    f(i+1, 0);
    return;
  }

  if(u[i][j]){
    f(i, j+1);
    return;
  }
  for(int k = 0; k < 9; k++){
    if(not (d1[i][k] or d2[j][k])){
      int square = 3 * (i / 3) + (j / 3);
      if (not d3[square][k]){
        v[i][j] = k + 1;
        u[i][j] = true;

        bool b1 = d1[i][k];
        bool b2 = d2[j][k];
        bool b3 = d3[square][k];

        d1[i][k] = true;
        d2[j][k] = true;
        d3[square][k] = true;
        f(i, j+1);
        u[i][j] = false;
        if(!b1) d1[i][k] = false;
        if(!b2) d2[j][k] = false;
        if(!b3) d3[square][k] = false;
      }

    }
  }



}

int main(){
  int n;
  cin >> n;
  cout << n << endl;
  for(int q = 0; q < n; q++){
    v = VVE(9, VE(9, -1));
    u = d1 = d2 = d3 = VVB(9, VB(9, false));
    char c;
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cin >> c;
        if (c != '.'){
          int a = c -'0';
          v[i][j] = a;
          u[i][j] = true;
          d1[i][a - 1] = true;
          d2[j][a - 1] = true;
          int square = 3 * (i / 3) + (j / 3);
          d3[square][a - 1] = true;


        }
      }
    }
    found = false;
    f(0,0);
  }
}
