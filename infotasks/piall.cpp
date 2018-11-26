#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
uint64_t counti = 0;
int main(){
  double r = 30000.0;
  for(int x = 0; x < r; x++){
    for(int y = 0; y < r; y++){
      if((x*x+y*y)<r*r){::counti++;}
    }
  }
  double pires = 4*(double)counti/(r*r);
  cout<<pires;
  return 0;
}
