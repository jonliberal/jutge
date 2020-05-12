#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;

void zeros(VE &v, int n, int i, int j){
  if(j > i) return;
  if(j < 0) return;
  if(i == 0){
    if (j != 0) return;
    cout << v[0];
    for(int k = 1; k < n; k++){
      cout << " " << v[k];
    }
    cout << endl;
    return;
  }

  v[n-i] = 0;
  zeros(v, n, i - 1, j);

  v[n-i] = 1;
  zeros(v, n, i - 1, j - 1);


}
int main(){
  int n, o;
  cin >> n >> o;
  VE v(n);
  zeros(v, n, n, o);

}
