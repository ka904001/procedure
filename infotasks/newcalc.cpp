#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

double current = 0;
int main() {
  ::current = sqrt(2);
  for(int i = 0; i < 2; i++){
    ::current = sqrt(
        (pow((current / 2), 2) + pow(1 - sqrt((1 - pow((current / 2), 2))), 2)));
  }
  cout << current;
}
