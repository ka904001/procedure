#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
  for(int i = 0; i<1000; i++){
    cout<<(double)rand()/(double)RAND_MAX*100<<" ";
  }
  return 0;
}
