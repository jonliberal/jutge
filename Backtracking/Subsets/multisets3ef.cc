#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;

int n, x, y, t;
VE v;

void printSet(int k){
  cout << "{";
  bool started = false;
  for(int i = 0; i < k; i++){
    for(int j = 0; j < v[i]; j++){
      if(started) cout << ",";
      cout << i+1;
      started = true;
    }
  }
  cout << "}" << endl;
}

void f(int k, int j){
  if(j == t) {
    printSet(k);
    return;
  }
  if(k == n) return;

  for(int i = x; i < min(t - j + 1, y + 1); i++){
    v[k] = i;
    //cout << "set ";
    //printSet(n);
    //cout << "executing f(" << k+1 << " , " << j +i << ")" << endl;
    //cout << "j: " << j << endl;
    f(k+1, j + i);
  }
}


int main(){
  cin >> n >> x >> y >> t;
  v = VE(n, 0);
  f(0, 0);

}
