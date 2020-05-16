#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;

VE zeros, ones;

int f0(int i){
  if(i <= 0) return 0;
  if(zeros[i] != -1) return zeros[i];
  return zeros[i] = f1(i - 1);
}

int f1(int i){
  if(i <= 0) return 0;
  if(ones[i] != -1) return ones[i];
  return ones[i] = f0(i - 1) + f1(i - 1) - f0(i - 3);
}


int main(){
  int n;
  zeros = ones = VE(151, -1);
  while(cin >> n){
    cout << f1(n) + f0(n) << endl;
  }
}
