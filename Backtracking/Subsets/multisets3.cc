#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;

int n, t;
VE v;

void printSet(vector<int> v){
  cout << "{";
  bool started = false;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < v[i]; j++){
      if(started) cout << ",";
      cout << i+1;
      started = true;
    }
  }
  cout << "}" << endl;
}

void f(vector<int> v, int k, int j){
  if(k == n+1) return;
  if(j == t) {
    printSet(v);
    //for(int z = k; z < n; z++) v[z] = 0;
  }
  else{
    for(int i = 0; j + i < t+1; i++){
      v[k] = i;
      f(v, k+1, j + i);
    }
  }
}


int main(){
  cin >> n >> t;
  v = VE(n, 0);
  f(v, 0, 0);

}
