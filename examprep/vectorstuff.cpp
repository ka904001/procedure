#include <iostream>
#include <vector>
using namespace std;
int main(){
  int a = 0, b = 0;
  cout<<"Enter the number of rows"<<endl;
  cin>>a;
  cout<<"Enter the number of columns"<<endl;
  cin>>b;
  vector<vector<int>> massiv(a, vector<int>(b, 0));
  for(int i = 0; i< a; i++){
    for(int j = 0; j < b; j++){
      cout<<"Enter the element of"<<' '<<i<<" row"<<' '<<j<<" column"<<endl;
      cin>>massiv[i][j];
    }
  }
  vector<int> summ(a, 0);
  for(int i = 0; i< a; i++){
    for(int j = 0; j < b; j++){
      summ[i]+=massiv[i][j];
    }
  }
  for(int i = 0; i < a; i++){
    cout<<"The summ of"<<' '<<i<<" row is:"<<' '<<summ[i]<<endl;
  }
  return 0;
}
