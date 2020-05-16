#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
VE v;
string s;
int n;

int f(){
  for(int i = n - 1; i >= 0; i--){
    for(int j = n - 1; j > i; j--){
      if(s[j] > s[i]){
        v[i] += v[j] + 1;
      }
    }
  }

  int t = 0;
  for(int i = 0; i < n; i++) t += v[i];
  return t;
}

int main(){
  while(cin >> s){
    n = s.length();
    v = VE(n, 0);
    cout << f() << endl;
  }
}
