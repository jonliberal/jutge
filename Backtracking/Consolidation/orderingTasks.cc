#include<iostream>
#include<vector>
#include<list>

using namespace std;

typedef list<int> L;
typedef vector<list<int>> VL;

VL v;

int n,m;



int main(){
  cin >> n >> m;
  v = VL(n);
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    v[b].push_back(a);
  }

  for(int j = 0; j < n; j++){
    L::iterator itr = v[j].begin();
    while(itr != v[j].end()) cout << " " << *itr; ++itr;
    cout << endl;
  }


}
