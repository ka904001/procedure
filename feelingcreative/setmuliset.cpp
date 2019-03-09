#include <iostream>
#include <set>
#include <ctime>
#include <cstdint>
using namespace std;
int main(){
  set<uint64_t> container;
  srand(time(0));
  for(auto i = 0; i < 100; i++){
    container.insert(rand());
  }
  for(auto m: container){
    cout<<m<<' ';
  }
  return 0;
}
