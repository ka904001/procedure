#include <iostream>
using namespace std;

void permute(string str, int i, int n) {
  if (i == n) {
    cout << str << endl;
  } else {
    for (char temp, j = i; j < n; j++) {
      cout << (char)(i + 48) << ' ' << (char)(j + 48) << endl;
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      permute(str, i + 1, n);
      cout << (char)(i + 48) << ' ' << (char)(j + 48) << endl;
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      // backtrack.
    }
  }
}

int main() {
  string str;
  cin >> str;
  cout << endl;
  permute(str, 0, str.length());
  return 0;
}
