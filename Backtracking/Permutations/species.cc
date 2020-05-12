#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<bool> VB;
typedef vector<VB> VVB;

VVB u;
VE v;
VB w;

typedef map<char, int> MCI;
typedef map<int, char> MIC;


MCI m1;
MIC m2;

int n;


void f(int k){
  if(k == n){
    for(int i = 0; i < n; i++){
      cout << m2[v[i]];
    }
    cout << endl;
    return;
  }

  for(int i = 0; i < n; i++){
    if(not u[v[k-1]][i] and (not w[i])){
      v[k] = i;
      w[i] = true;
      f(k+1);
      w[i] = false;
    }
  }

}


int main(){
  char c, c1,c2;
  while(cin >> n){
    u = VVB(n, VB(n, false));
    v = VE(n);
    w = VB(n, false);
    //MCI m1;
    //MIC m2;
    for(int i = 0; i < n; i++){
      cin >> c;
      m1[c] = i;
      m2[i] = c;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
      cin >> c1 >> c2;
      u[m1[c1]][m1[c2]] = true;
      u[m1[c2]][m1[c1]] = true;
    }

    for(int i = 0; i < n; i++){
      v[0] = i;
      w[i] = true;
      f(1);
      w[i] = false;
    }

    // for(int j= 0; j < n; j++){
    //   for(int l = 0; l < n; l++) cout << " " << u[j][l];
    //   cout << endl;
    // }
  }
}
