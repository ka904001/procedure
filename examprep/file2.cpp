#include <iostream>
#include <fstream>

using namespace std;

int main(){
   fstream file;
   file.open("file2.txt", ios::out);
   file<<"Author_1 Name_1 1901"<<endl<<"Author_2 Pascal 1902"<<endl<<"Author_3 Name_3 1903"<<endl<<"Author_4 Name_4 1904"<<endl;
   file.close();
   file.open("file2.txt", ios::in);
   string auth;
   int year = 0, err = 1;
   cin>>auth>>year;
   while(!file.eof()){
     string au, name;
     int yr;
     file>>au>>name>>yr;
     if(auth==au&&yr==year){
       cout<<name<<endl;
       err = 0;
     }
   }
   //file.close();
   file.clear();
   file.seekg(0, ios_base::beg);
   if(err == 1){
     cout<<"No book was found!"<<endl;
   }
   while(!file.eof()){
     string au, name;
     int yr;
     file>>au>>name>>yr;
     if(name == "Pascal"){
       cout<<"There seems to be be a Pascal book by "<<au<<' '<<yr<<endl;
     }
   }
   file.close();
   return 0;
 }
