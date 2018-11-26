#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
int main(){
  int r = 1000000;
  double pires = 0;
  for(int x = 0; x < r; x++){
    pires+=pow(-1, x)/(2*x+1);
  }
  cout<<4*pires;
  return 0;
}
