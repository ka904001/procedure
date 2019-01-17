#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cout << "Enter the number of characters" << endl;
  cin >> n;
  string buff;
  cout << "Enter the string of"<<' '<<n<< " characters" << endl;
  getline(cin, buff);
  bool wronginput = buff.length() != n;
  while (wronginput) {
    getline(cin, buff);
    wronginput = buff.length() != n;
    if (wronginput) {
      cout << "The size of string is out of range, try again" << endl;
    }
  }
  string temp;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (buff[i] == ' '){c++;}
    if (c == 2) {
      for (int j = i + 1; j < n; j++) {
        if(buff[j]==' ')break;
        temp += buff[j];
      }
      break;
    }
  }
  for(int i = 0; i < temp.length(); i++){
    cout<<temp[temp.length()-1-i];
  }
  return 0;
}
