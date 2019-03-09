#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
  int n;
  cout << "vvedite kolichestvo strok" << endl;
  cin >> n;
  vector<string> str;
  cout << "vvedite stroki" << endl;
  string temp;
  getline(cin, temp);
  for (int i = 0; i < n; i++) {
    getline(cin, temp);
    str.push_back(temp);
  }
  for(int i = 0; i < str.size(); i++){
    for(int j = i + 1; j < str.size(); j++){
      if(str[i].length()>str[j].length()){
        string temp = str[j];
        str[j]=str[i];
        str[i]=temp;
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << str[i]<<endl;
  }
  return 0;
}
