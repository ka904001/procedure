#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  vector<char> stroka;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    stroka.push_back(str[i]);
  }
  vector<int> prob;
  for (int i = 0; i < stroka.size(); i++) {
    if ((int)(stroka[i]) == 32) {
      prob.push_back(i);
    }
  }
  vector<int> dlin;
  for (int i = 0; prob.size(); i++) {
    if (i == 0) {
      dlin.push_back(prob[i]);
    } else {
      dlin.push_back(prob[i] - prob[i - 1]);
    }
  }
  int maxi = 0, mini = 0;
  for (size_t i = 0; i < dlin.size(); i++) {
    if (dlin[i] >= dlin[maxi]) {
      maxi = i;
    }
    if (dlin[i] >= dlin[mini]) {
      mini = i;
    }
  }
  vector<char> temp1;
  for (int i = maxi; i < maxi - dlin[maxi]; i++) {
    temp1.push_back(stroka[i]);
  }
  vector<char> temp2;
  for (int i = mini; i < mini - dlin[mini]; i++) {
    temp2.push_back(stroka[i]);
  }
  if (maxi > mini) {
  /*  stroka.erase(stroka.begin() + mini - dlin[mini], stroka.begin() + mini);
    stroka.insert(stroka.begin() + mini - dlin[mini], temp1);*/
    /*Надо, чтобы учитывало смещение индексов*/
  /*  stroka.erase(stroka.begin() + maxi - dlin[maxi] -
                     (temp1.size() - temp2.size()),
                 stroka.begin() + maxi - (temp1.size() - temp2.size()));
    stroka.insert(stroka.begin() + maxi - dlin[maxi] -
                      (temp1.size() - temp2.size()),
                  temp2);*/
  }
  // swap_ranges(_FIter1, _FIter1, _FIter2)
  // stroka.erase(stroka.begin() + mini - dlin[mini], stroka.begin() + mini);
  // stroka.insert(stroka.begin() + mini - dlin[mini], );
  // stroka.erase(stroka.begin() + maxi - dlin[maxi], stroka.begin() + maxi);
  return 0;
}
