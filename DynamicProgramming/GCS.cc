#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VVE v;
string s1, s2;
int l1, l2;
int mx;
queue<int> q;

int f(int i, int j){
  if(i < 0 or j < 0) return 0;
  if(v[i][j] != -1) return v[i][j];

  if(s1[i] == s2[j]){
    int res = 1 + f(i - 1, j - 1);
    v[i][j] = res;
    if(res > mx){
      queue<int> e;
      swap(q, e);
      q.push(i);
      mx = res;
    }
    else if(res == mx){
      q.push(i);
    }
    return res;
  }
  return v[i][j] = 0;
}


int main(){
  while(cin >> s1 >> s2){
    l1 = s1.length();
    l2 = s2.length();
    mx = -1;
    v = VVE(l1, VE(l2, -1));
    for(int i = 0; i < l1; i++){
      for(int j = 0; j < l2; j++){
        f(i, j);
      }
    }
    string ans = "";
    int k;
    if(!q.empty()){
      k = q.front(); q.pop();
      ans = s1.substr(k - mx + 1, mx);
    }
    while(!q.empty()){
      k = q.front(); q.pop();
      ans = min(ans, s1.substr(k - mx + 1, mx));
    }
    cout << ans << endl;





  }

}
