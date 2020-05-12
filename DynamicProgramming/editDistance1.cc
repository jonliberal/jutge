#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VVE d;
VE w1, w2;
VE c;


int editDistance(int i1, int i2){

  if(d[i1][i2] != -1) return d[i1][i2];

  if(i1 == w1.size() and i2 == w2.size()) return d[i1][i2] = 0;
  if(i1 == w1.size()) return d[i1][i2] = c[w2[i2]] + editDistance(i1, i2 + 1);
  if(i2 == w2.size()) return d[i1][i2] = c[w1[i1]] + editDistance(i1 + 1, i2);

  if(w1[i1] == w2[i2]) return editDistance(i1 + 1, i2 + 1);
  return d[i1][i2] = min(c[w2[i2]] + editDistance(i1, i2 + 1),
                          c[w1[i1]] + editDistance(i1 + 1, i2));

}


int main(){
  int n;
  while(cin >> n){
    c = VE(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int l1 = s1.length(), l2 = s2.length();

    w1 = VE(l1);
    w2 = VE(l2);

    for(int i = 0; i < l1; i++) w1[i] = s1[i] - 'a';
    for(int i = 0; i < l2; i++) w2[i] = s2[i] - 'a';



    d = VVE(l1+1, VE(l2+1, -1));

    cout << editDistance(0, 0) << endl;
  }


}
