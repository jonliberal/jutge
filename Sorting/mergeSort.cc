#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &v, int e, int m, int d){
  if(e >= d) return;

  vector<int> aux(d-e+1);
  int i = e;
  int j = m+1;
  for(int k=0; k < d-e+1; k++){
    if(i>m){
      aux[k] = v[j];
      j += 1;
    }
    else if(j > d){
      aux[k] = v[i];
      i += 1;
    }
    else{
      if (v[i] > v[j]){
        aux[k] = v[j];
        j += 1;
      }
      else{
        aux[k] = v[i];
        i += 1;
      }
    }
  }
  for(int k=0; k < d-e+1; k++){
    v[e+k] = aux[k];
  }

}

void mergeSort(vector<int> &v, int e, int d){
  if (e >= d) return;
  int m = (e + d)/2;
  mergeSort(v, e, m);
  mergeSort(v, m+1, d);
  merge(v, e, m, d);
}




int main(){
  int n;
  cin >> n;
  vector<int> V(n);
  for(int i=0; i < n; i++) cin >> V[i];
  mergeSort(V, 0, n-1);
  for(int i=0; i < n; i++) cout << ' ' << V[i];
}
