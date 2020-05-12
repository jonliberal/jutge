#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<string> VS;

VS w;
int n, p;

void f(VE &v, int i){
  if(i == 0){
    for(int j=0; j < p; j++){
      cout << "subset " << j+1 << ": {";
      bool started = false;
      for(int k = 0; k < n; k++){
        if(v[k] == j){
          if(started) cout << ",";
          cout << w[k];
          started = true;
        }
      }
      cout << "}" << endl;
    }
    cout << endl;
    return;
  }

  for(int k = 0; k < p; k++){
    v[n-i] = k;
    f(v, i - 1);
  }


}
int main(){
  cin >> n;
  w = VS(n);
  string s;
  for(int i = 0; i < n; i++){
    cin >> s;
    w[i] = s;
  }
  cin >> p;
  VE v(n);
  f(v, n);

}
