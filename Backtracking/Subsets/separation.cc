#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> VE;
VE v, w;
int n;
int m;

void f(int k, int s){
  if(s - w[k] > m) return;
  if(k == n){
    if(s < m) m = s;
    return;
  }
  f(k+1, abs(s + v[k]));
  f(k+1, abs(s - v[k]));

}

int main(){
  while(cin >> n){
    v = VE(n);
    w = VE(n);
    m = 10000000;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    w[n-1] = v[n-1];
    for(int i = 1; i < n; i++) w[n-i-1] = v[n-i-1] + w[n-i];
    f(0,0);
    cout << m << endl;
  }
}

// int main2(){
//   while(cin >> n){
//     v = VE(n);
//     for(int i = 0; i < n; i++) cin >> v[i];
//     sort(v.begin(), v.end(), greater<int>());
//     int res = 0;
//     for(int i = 0; i < n; i++){
//       if(res < 0) res += v[i];
//       else res -= v[i];
//     }
//     cout << abs(res) << endl;
//
//   }
// }
