#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> VE;

int n;
VE v;

void f(int k){
  if(k == n) return;
  for(int i = 1; i + k < n; i++){
    swap(v[k], v[k+i]);
    for(int j = 0; j < n; j++) cout << " " << v[j];
    cout << endl;
    f(k + i);
    swap(v[k], v[k+i]);

  }
}

int main(){
  cin >> n;
  v = VE(n);
  for(int j = 0; j < n; j++) v[j] = j+1;
  for(int j = 0; j < n; j++) f(j);

}
