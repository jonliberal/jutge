#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


void quicksort(vector<int> &v, int e, int d){
  if(d > e){
  p = partition(v, e, d);
  quicksort(v, e, p);
  quicksort(v, p+1, d);
  }
}

int partition(vector<int> &v, int e, int d){
  int i = e-1;
  int j = d+1;
  int p = v[e];
  while(true){
    while(v[--j] > p);
    while(v[++i] < p);
    if(i >= j) return j;
    swap(v[i], v[j]);
  }
}


int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i < n; i++) cin >> v[i];
  quicksort(v, 0, n-1);
  for(int i=0; i < n; i++) cout << v[i];

}
