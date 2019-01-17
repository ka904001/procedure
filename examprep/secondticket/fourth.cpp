#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <array>
using namespace std;

int main(){
  fstream file1;
  file1.open("fourth_1.txt", ios::out);
  srand(time(0));
  int n;
  cout << "Enter the number of integers" << '\n';
  cin>>n;
  for(int i = 0; i < n; i++){
    file1<<trunc((double)rand()/(double)RAND_MAX*256)<<' ';
  }
  file1.close();
  file1.open("fourth_1.txt", ios::in);
  union num{
    int num[2];
  };
  vector<num> mas(1, {.num={0,0}} );
  //cout<<"check"<<endl;
  while(!file1.eof()){
    int temp;
    bool found = 0;
    file1>>temp;
    cout<<temp<<' ';
    for(uint i = 0; i < mas.size(); i++){
      if(temp==mas[i].num[0]){
        mas[i].num[1]++;
        found = 1;
        break;
      }
    }
    if(!found){
      num tempobj;
      tempobj.num[0]=temp;
      tempobj.num[1]=1;
      mas.push_back(tempobj);
    }
  }
  cout<<endl;
  file1.close();
  vector<num> newmas(1, {.num={0,0}} );
  newmas.clear();
  for(uint i = 0; i < mas.size(); i++){
    if(mas[i].num[1]>newmas[0].num[1]){
      newmas.clear();
      newmas.push_back(mas[i]);
    }else if(mas[i].num[1]==newmas[0].num[1]){
      newmas.push_back(mas[i]);
    }
  }
  for(int i = 0; i < newmas.size(); i++){
    for(int j = i+1; j < newmas.size(); j++){
      if(newmas[i].num[0]>newmas[j].num[0]){
        num temp;
        temp = newmas[j];
        newmas[j] = newmas[i];
        newmas[i] = temp;
      }
    }
  }
  for(uint i = 0; i< newmas.size(); i++){
    cout<<newmas[i].num[0]<<' '<<newmas[i].num[1]<<endl;
  }
  fstream file2;
  file2.open("result.txt", ios::out);
  for(uint i = 0; i< newmas.size(); i++){
    file2<<newmas[i].num[0]<<' '<<newmas[i].num[1]<<endl;
  }
  file2.close();
  cout<<"finish"<<endl;
  return 0;
}
