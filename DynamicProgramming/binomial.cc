#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VVE v;
int f(int n, int k){
  if(k > n) return 0;
  if(k < 0) return 0;
  if(v[n][k] != -1) return v[n][k];
  return v[n][k] = f(n-1, k) + f(n-1, k-1);


}

int main(){
  v = VVE(31, VE(31, -1));
  v[0][0] = 1;
  int k, n;
  while(cin >> n >> k){
    cout << f(n, k) << endl;
  }

}
