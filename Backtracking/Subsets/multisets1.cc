#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;

int n,x;
VE v;

void printSet(){
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

void f(int k){
  if(k == n) printSet();
  else{
    for(int i = 0; i < x+1; i++){
      v[k] = i;
      f(k+1);
    }
  }
}


int main(){
  cin >> n >> x;
  v = VE(n, 0);
  f(0);

}
