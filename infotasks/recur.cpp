#include <iostream>
#include <cmath>
using namespace std;

int fact(int i){
  if(i==1){return i;}
  else{return i*fact(i-1);}
}

int main(){
  double summ = 0.0, el = 1.0, x = 0.0;
  cin>>x;
  for(int k = 0; el > 0.000001; k++){
    el = (double)fact(2*k+1)/(pow(k+1, k)*pow(x, 4*k));
    summ+=el;
  }
  cout<<summ;
  return 0;
}
