#include <iostream>
#include <string>
using namespace std;

int main(){
  for(int i = 1000; i<10000; i++){
    string num = to_string(i);
    if(num[0]!=num[1]&&num[0]!=num[2]&&num[0]!=num[3]&&num[1]!=num[2]&&num[1]!=num[3]&&num[2]!=num[3])cout<<num<<endl;
  }
  return 0;
}
