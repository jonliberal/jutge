#include<iostream>
#include<vector>
#include <math.h>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

int editDistance(const VE &w1, const VE &w2, const VE &c, const int &minCost, VVE &d, int i1, int i2){

  if(d[i1][i2] != -1) return d[i1][i2];

  if(i1 == w1.size() and i2 == w2.size()) return d[i1][i2] = 0;
  if(i1 == w1.size()) return d[i1][i2] = min(c[w2[i2]], int(ceil(minCost + c[w2[i2]]/4.)) + minCost)
                                          + editDistance(w1, w2, c, minCost, d, i1, i2 + 1);
  if(i2 == w2.size()) return d[i1][i2] = min(c[w1[i1]], int(ceil(minCost + c[w1[i1]]/4.)) + minCost)
                                          + editDistance(w1, w2, c, minCost, d, i1 + 1, i2);
  int d0 = 1000000000;
  if(w1[i1] == w2[i2]) d0 = editDistance(w1, w2, c, minCost, d, i1 + 1, i2 + 1);
  // insert costs
  int d1 = editDistance(w1, w2, c, minCost, d, i1+1, i2);
  int d2 = editDistance(w1, w2, c, minCost, d, i1, i2+1);
  int d3 = editDistance(w1, w2, c, minCost, d, i1 + 1, i2 + 1);


  int m_in_1 = min(c[w1[i1]], minCost +  int(ceil((c[w1[i1]] + minCost)/4.))) + d1;
  int m_in_2 = min(c[w2[i2]], minCost +  int(ceil((c[w2[i2]] + minCost)/4.))) + d2;
  // modify costs
  int m_mod = int(ceil((c[w2[i2]] + c[w1[i1]])/4.)) + d3;

  return d[i1][i2] = min(min(m_in_1, m_in_2), min(m_mod, d0));
}


int main(){
  int n;
  while(cin >> n){
    vector<int> c(n);
    int minCost = 10000;
    for(int i = 0; i < n; i++){
      cin >> c[i];
      if(c[i] < minCost) minCost = c[i];
    }

    string s1, s2;
    cin >> s1;
    cin >> s2;

    int l1 = s1.length(), l2 = s2.length();

    VE w1(l1), w2(l2);

    for(int i = 0; i < l1; i++) w1[i] = s1[i] - 'a';
    for(int i = 0; i < l2; i++) w2[i] = s2[i] - 'a';



    VVE d(l1+1, VE(l2+1, -1));
    int res = editDistance(w1, w2, c, minCost, d, 0, 0);
    cout << res << endl;

    cout << "Printing distance matrix" << endl;

    for(int i = 0; i < l1 + 1; i++){
      for(int j = 0; j < l2 + 1; j++) cout << " " << d[i][j];
      cout << endl;
    }
  }


}
