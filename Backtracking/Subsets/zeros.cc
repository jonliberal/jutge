#include<iostream>
#include<queue>
using namespace std;


void zeros(queue<int> q, int i){
  if(i == 0){
    cout << q.front();
    q.pop();
    while(!q.empty()){
      cout << " " << q.front();
      q.pop();
    }
    cout << endl;
    return;
  }
  queue<int> q1 = q;
  q1.push(0);
  zeros(q1, i - 1);
  queue<int> q2 = q;
  q2.push(1);
  zeros(q2, i - 1);


}
int main(){
  int n;
  cin >> n;
  queue<int> q;
  zeros(q, n);

}
