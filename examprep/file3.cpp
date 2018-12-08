#include <cstdint>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  fstream file1, file2, file3;
  file1.open("file3_1.txt", ios::out);
  for (int i = 0; i < 400; i++) {
    file1 << rand() << ' ';
  }
  file1.close();
  file1.open("file3_1.txt", ios::in);
  uint64_t min[4]{4000000000, 4000000000, 4000000000, 4000000000}, max[4]{0};
  uint64_t num = 0;
  for (int i = 0; i < 400; i++) {
    file1 >> num;
    if (num > max[i / 100])
      max[i / 100] = num;
    if (num < min[i / 100])
      min[i / 100] = num;
  }
  file1.close();
  file1.open("file3_1.txt", ios::in);
  file2.open("file3_2.txt", ios::out);
  for (uint64_t i = 0, curr = 0; i < 400; i++) {
    file1 >> curr;
    (curr == min[i / 100] || curr == max[i / 100]) ? file2 << '0' << ' '
                                                   : file2 << curr << ' ';
  }
  file1.close();
  file2.close();
  file2.open("file3_2.txt", ios::in);
  file3.open("file3_3.txt", ios::out);
  for (int k = 0; k < 4; k++) {
    file3 << "This is a " << k + 1 << " matrix:\n";
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        uint64_t tmp = 0;
        file2 >> tmp;
        file3.width(13);
        file3 << tmp;
      }
      file3 << '\n';
    }
  }
  file3.close();
  file2.close();
  int choice = 0;
  cout << "If you wish to wiew the result type 1" << endl;
  cin >> choice;
  if (choice == 1) {
    file3.open("file3_3.txt", ios::in);
    for (int k = 0; k < 4; k++) {
      string a1, a2, a3, a4, a5;
      file3 >> a1 >> a2 >> a3 >> a4 >> a5;
      cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' << a5 << endl;
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          uint64_t tmp = 0;
          file3 >> tmp;
          cout.width(15);
          cout << tmp << ' ';
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
