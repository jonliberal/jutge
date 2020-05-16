#include<iostream>
#include<vector>

using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;

VE l;
VVE v, w;

int f(int i, int j){
  if(i < 0 or j < 0) return 0;
  if(v[i][j] != -1) return v[i][j];
  //cout << "         " << i << ' ' << j << ' ' <<  w[i][j] << endl;
  return v[i][j] = w[i][j] + f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1);

}

int main(){
  int n = 'Z' - 'A' + 1;
  l = VE(n);
  l[0] = 1;
  for(int i = 1; i < n; i++) l[i] = l[i - 1] + (i + 1);


  v = VVE(500, VE(500, -1));
  w = VVE(500, VE(500, -1));

  string s;
  int m = 0;
  while (cin >> s){
    int n = s.length();
    bool line = false;
    for(int i = 0; i < n; i++){
      w[m][i] = l[s[i] - 'A'];
      //cout << "            " << l[s[i] - 'A'] <<  endl;
      if (line) cout << ' ';
      cout << f(m, i);
      line = true;
    }
    m += 1;
    cout << endl;
  }

}
