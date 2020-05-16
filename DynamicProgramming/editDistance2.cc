#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VE c, mc;
string s1, s2;
int l1, l2;

VVE d;
int mn;



int f(int j, int i){


  if(j == l1 and i == l2) return 0;
  if(j == l1) return mc[s2[i] - 'a'] + f(j, i + 1);
  if(i == l2) return mc[s1[j] - 'a'] + f(j + 1, i);
  if(d[j][i] != -1) return d[j][i];

  if(s1[j] == s2[i]) return f(j + 1, i + 1);
  // insert costs
  int min_1 = min(mc[s1[j] - 'a'] + f(j+1, i), mc[s2[i] - 'a'] + f(j, i+1));
  // modify costs
  int m_mod = (c[s2[i] - 'a'] + c[s1[j] - 'a'] + 3)/4 + f(j + 1, i + 1);

  return d[j][i] = min(min_1 , m_mod);
}


int main(){
  int n;
  while(cin >> n){
    c = mc = VE(n);
    mn = 10000;
    for(int i = 0; i < n; i++){
      cin >> c[i];
      if(c[i] < mn) mn = c[i];
    }
    for(int i = 0; i < n; i++){
      mc[i] = min(c[i], mn +  (c[i] + mn + 3)/4);
    }
    cin >> s1;
    cin >> s2;

    l1 = s1.length(), l2 = s2.length();

    d = VVE(l1+1, VE(l2+1, -1));
    int res = f(0, 0);
    cout << res << endl;
  }


}
