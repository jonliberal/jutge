#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;

VE v;
int n;

int f(int i){
  if(v[i] != -1) return v[i];
  return v[i] = (f(i - 1) + f(i - 2))%(100000007);
}

int main(){
  v = VE(100002, -1);
  v[0] = 0;
  v[1] = 1;
  while(cin >> n){
    cout << f(n) << endl;

  }

}
