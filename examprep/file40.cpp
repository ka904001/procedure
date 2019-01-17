#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
  fstream file;
  file.open("file4_1.txt", ios::out);
  file<<"4586 Bfdeef Viktor Moliev 5 4 4 5 4"<<endl;
  file<<"4587 Afdeef Viktor Moliev 5 4 3 5 4"<<endl;
  file<<"4588 Cfdeef Viktor Moliev 5 3 4 5 4"<<endl;
  file<<"4589 Gfdeef Viktor Moliev 5 4 4 5 4"<<endl;
  file<<"4590 Dfdeef Viktor Moliev 5 4 4 5 4"<<endl;
  file.close();
  fstream file2;
  file2.open("file4_2.txt", ios::out);
  file.open("file4_1.txt", ios::in);
  while(!file.eof()){
      string result;
      bool badmark = false;
      getline(file, result);
      for(int i = 0; i < 5; i++){
        if(result[result.length()-1-2*i]=='2'||result[result.length()-1-2*i]=='3') badmark = true;
      }
      if(!badmark){
        file2<<result<<endl;
      }
  }
  file2.close();
  file.close();
  fstream file3;
  file2.open("file4_2.txt", ios::in);
  file3.open("file4_3.txt", ios::out);
  vector<string> mas;
  while(!file2.eof()){
    string result;
    getline(file2, result);
    if(result.length()!=0)mas.push_back(result);
  }
  for(uint i = 0; i < mas.size(); i++){
    for(uint j = i+1; j<mas.size(); j++){
      if(mas[j][5] < mas[i][5]){
        string temp = mas[j];
        mas[j] = mas[i];
        mas[i] = temp;
      }
    }
  }
  for(uint i = 0; i < mas.size(); i++){
    file3<<mas[i]<<endl;
  }
  file3.close();
  file2.close();
  return 0;
}
