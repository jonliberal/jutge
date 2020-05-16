#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
typedef vector<VVE> VVVE;

int c, v;
VVVE m;
VE coins{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int num = coins.size();

int f(int val, int k, int j){

  if(val == 0 and k == 0){
    //for(int l = 0; l < c; l++) cout << ' ' << u[l+1];
    //cout << endl;
    return 1;
  }
  if(k <= 0) return 0;
  if(val <= 0) return 0;
  if(m[val][k][j] != -1) return m[val][k][j];
  int res = 0;
  for(int i = j; i < num; i++){
    //u[k] = coins[i];
    //cout << coins[i] << "   ";
    res += f(val - coins[i], k - 1, i);
  }
  return m[val][k][j] = res;
}


int main(){
  int n;
  m = VVVE(29*20+1, VVE(20+1,VE(num+1, -1)));
  while(cin >> n){

    for(int i = 0; i < n; i++){
      cin >> c >> v;

      if(v > 29*c) cout << 0 << endl;
      else cout << f(v, c, 0) << endl;
    }
  }
}
