#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
int n,m;
VE v;

int f(int i){
  if(i < 1) return 0;
  if(i % 2 == 0) return 0;
  if(v[i] != -1) return v[i];
  int res = f(i-2);
  for(int j = 1; j < i - 5; j++) res += f(j) * f(i - 5 -j);
  return v[i] = res;
}

int main(){
  while (cin >> n >> m){
    v = VE(n+1, -1);
    v[1] = m;
    cout << f(n) << endl;

  }
}
