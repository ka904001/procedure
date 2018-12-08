#include <fstream>
#include <iostream>

using namespace std;

int main(){
  fstream file;
  file.open("some.txt", ios::out);
  file<<"Doll_1 200 4 6\n"<<"Doll_2 300 2 3\n"<<"Doll_3 500 0 7\n"<<"Doll_4 800 2 12\n"<<"Doll_5 350 2 12\n";
  file.close();
  file.open("some.txt", ios::in);
  int choice = 0;
  cin>>choice;
  switch(choice){
    case 1:{
      while(!file.eof()){
        string str;
        int price = 0, dage = 0, oage = 0;
        file>>str>>price>>dage>>oage;
        if(price<=400&&dage<=8&&oage>=8)cout<<str<<endl;
        //file.clear();
        //file.seekg(0, std::ios_base::beg);
        //cout<<str<<price<<dage<<oage<<endl<<endl;
      }
    }
    break;
    case 2:{
      int max = 0;
      while(!file.eof()){
        string str;
        int price = 0, dage = 0, oage = 0;
        file>>str>>price>>dage>>oage;
        if(price>max)max=price;
      }
      cout<<max;
    }
    break;
    case 3:{
      while(!file.eof()){
        string str;
        int price = 0, dage = 0, oage = 0;
        file>>str>>price>>dage>>oage;
        if(dage<=4&&oage>=10)cout<<str<<' '<<price<<endl;
      }
    }
    break;
    default:
    cout<<"Wrong input!!!";
  }
  file.close();
  return 0;
}
