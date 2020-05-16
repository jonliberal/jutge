#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

VVE m, num;

int c, minAv, minj, mini;


int f(int i, int j){
  if(i < 0 or j < 0) return 0;
  if(m[i][j] != -1) return m[i][j];
  return m[i][j] = num[i][j] + f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1);
}
void av(int i, int j){
  int a = f(i,j) - f(i - c, j) - f(i, j - c) + f(i - c, j - c);
  if (a > minAv) {
    minAv = a;
    mini = i - c + 1;
    minj = j - c + 1;
  }
}


int main(){
  int w,h;
  minAv = 0;
  mini = 0;
  minj = 0;
  cin >> w >> h >> c;
  num = VVE(h, VE(w));
  m = VVE(h, VE(w, -1));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> num[i][j];
      av(i,j);
    }
  }
  cout << mini<< ' ' << minj << endl;




}
