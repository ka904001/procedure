#include <iostream>
using namespace std;

int main(){
  double a = 0.0, b = 0.0, c = 0.0, max = 0.0;
  cin>>a>>b;// a < b
  for(double i = 0.0; i < a/2; i+=0.001){
    double vol = (a-2*i)*(b-2*i)*i;
    if(vol > max){
      max = vol;
      c = i;
    }
  }
  cout<<c<<endl;
}
