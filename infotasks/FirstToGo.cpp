#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#define _USE_MATH_DEFINES

using namespace std;
int pus, choice, summ, summ1, summ0, r;
void menu() {
  cout << "If you wish to create file with 10 numbers and find summ type 1\n"
          "If you wish to evaluate sign function type 2\n"
          "If you wish to evaluate area of geometrical figures type 3\n"
          "If you wish to draw USA flag type 4\n"
          "If you wish to draw function type 5\n"
          "If you wish to evaluate roman number type 6\n"
          "If you wish to generate pseudorandom numbers type 7\n"
          "If you wish to work with matrixes type 8\n"
          "If you wish to finish type 10"
       << '\n';
  cin >> choice;
}
int sign(float x) {
  if (x < 0) {
    return -1;
  } else if (x == 0) {
    return 0;
  } else if (x > 0) {
    return +1;
  }
}
double fac(int x) {
  if (x == 0) {
    return 1;
  } else {
    return fac(x - 1) * x;
  }
}

double mysin(float x) {
  double mid = (double)((double)x - (double)pow(x, 3) / (double)fac(3) +
                        (double)pow(x, 5) / (double)fac(5) -
                        (double)pow(x, 7) / (double)fac(7) +
                        (double)pow(x, 9) / (double)fac(9) -
                        (double)pow(x, 11) / (double)fac(11));
  mid += (double)pow(x, 13) / (double)fac(13) -
         (double)pow(x, 15) / (double)fac(15) +
         (double)pow(x, 17) / (double)fac(17) -
         (double)pow(x, 19) / (double)fac(19);
  return mid;
}

float rectangle(float a, float b) { return a * b; }

float triangle(float a, float b) { return a * b / 2; }

float circle(float r) { return M_PI * r * r; }

int s(int k) {
  if (k == 0) {
    return 40;
  } else {
    return ((37 * s(k - 1) + 3) % 64);
  }
}

int ending();

int num(int i) {
  if (i == 0) {
    return summ1;
  } else {
    summ1 /= r;
    return num(i - 1);
  }
}
/*Returns whats is left after i divisions*/
int main() {
  menu();
  switch (choice) {
  case 1: {
    fstream file;
    file.open("out.txt", ios::out);
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
      file << (char)(48 + rand() % 9) << " ";
    }
    file.close();
    file.open("out.txt", ios::in);
    while (!file.eof()) {
      int a;
      file >> a;
      cout << a << ' ';
      summ += a;
    }
    file.close();
    cout << endl << summ << endl;
  } break;
  case 2: {
    cout << "Enter your value" << endl;
    float value;
    cin >> value;
    cout << sign(value) << endl;
    cout << "If -1, your value is negative.\nIf value is 0, your value is "
            "zero.\nIf value is +1, your number is positive\n";
  } break;
  case 3: {
    cout << "If you wish to evaluate area of rectangle type 1\n";
    cout << "If you wish to evaluate area of trianle type 2\n";
    cout << "If you wish to evaluate area of circle type 3\n";
    int cho;
    cin >> cho;
    switch (cho) {
    case 1: {
      cout << "Enter height and width value\n";
      float height, width;
      cin >> height >> width;
      cout << "The area of rectangle is " << rectangle(height, width) << endl;
    } break;
    case 2: {
      cout << "Enter height and bottom width of triangle\n";
      float height, bottomWidth;
      cin >> height >> bottomWidth;
      cout << "The area of triangle is " << triangle(height, bottomWidth)
           << endl;
    } break;
    case 3: {
      cout << "Enter radius of circle\n";
      float radius;
      cin >> radius;
      cout << "The area of circle is " << circle(radius) << endl;
    } break;
    default:
      cout << "Invalid value";
    }
  } break;
  case 4: {
    char flag[13][20];
    for (int i = 0; i < 13; i++) {
      if (i % 2 == 0) {
        for (int k = 0; k < 20; k++) {
          flag[i][k] = '#';
        }
      } else {
        for (int k = 0; k < 20; k++) {
          flag[i][k] = ' ';
        }
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int k = 0; k < 8; k++) {
        flag[i][k] = '*';
      }
    }
    for (int i = 0; i < 13; i++) {
      for (int k = 0; k < 20; k++) {
        cout << flag[i][k] << ' ';
      }
      cout << endl;
    }
  } break;
  case 5: {
    char a[21][200];
    for (int i = 0; i < 21; i++) {
      for (int k = 0; k < 200; k++) {
        a[i][k] = ' ';
      }
    }
    for (int k = 0; k < 200; k++) {
      int i;
      float r = (float)k / 20;
      i = (int)(-10 * sin(r));
      if (i >= -11 && i <= 10) {
        a[11 + i][k] = '*';
      }
    }
    for (int i = 0; i < 21; i++) {
      for (int k = 0; k < 200; k++) {
        cout << a[i][k];
      }
      cout << endl;
    }
  } break;
  case 6: {
    string str;
    int result = 0, error = 0;
    cout << "Enter roman number in CAPITALS!!!" << endl;
    cin >> str;
    int A[str.length()];
    for (int i = 0; i < str.length(); i++) {
      char M;
      switch (str[i]) {
      case 'I':
        A[i] = 1;
        break;
      case 'V':
        A[i] = 5;
        break;
      case 'X':
        A[i] = 10;
        break;
      case 'L':
        A[i] = 50;
        break;
      case 'C':
        A[i] = 100;
        break;
      case 'D':
        A[i] = 500;
        break;
      case 'M':
        A[i] = 1000;
        break;
      default:
        cout << "Invalid values!!!" << endl;
        ending();
        break;
      }
    }
    for (int i = 0; i < str.length(); i++) {
      if (A[i] >= A[i + 1]) {
        result += A[i];
      } else {
        result -= A[i];
      }
    }
    for (int i = 0; i < str.length(); i++) {
      cout << A[i] << endl;
    }
    cout << "The result is " << result << endl;
  } break;
  case 7:
    for (int i = 0; i < 20; i++) {
      cout << s(i) << endl;
    }
    break;
  case 8: {
    float a[3][4] = {{5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0}};
    float b[4][2] = {{1.2, 0.5}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5}};
    float result[3][2];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        float summ;
        for (int k = 0; k < 4; k++) {
          summ += a[i][k] * b[k][j];
        }
        result[i][j] = summ;
        summ = 0;
      }
    }
    cout << "Matrix A is:" << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        cout << a[i][j] << "\t";
      }
      cout << endl;
    }
    cout << endl << "Matrix B is:" << endl;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        cout << b[i][j] << "\t";
      }
      cout << endl;
    }
    cout << endl << "Matrix A*B is:" << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        cout << result[i][j] << "\t";
      }
      cout << endl;
    }
    int maxc;
    for (int i = 0; i < 2; i++) {
      if (result[i][0] > result[i + 1][0]) {
        maxc = i;
      } else {
        maxc = i + 1;
      }
    }
    int maxco;
    for (int i = 0; i < 1; i++) {
      if (result[i][1] > result[i + 1][1]) {
        maxco = i;
        if (result[i][1] > result[i + 2][1]) {
          maxco = i;
        } else {
          maxco = i + 2;
        }
      } else if (result[i][1] < result[i + 1][1]) {
        maxco = i + 1;
        if (result[i + 1][1] > result[i + 2][1]) {
          maxco = i + 1;
        } else {
          maxco = i + 2;
        }
      }
    }
    int minco;
    for (int i = 0; i < 1; i++) {
      if (result[i][1] < result[i + 1][1]) {
        minco = i;
        if (result[i][1] < result[i + 2][1]) {
          minco = i;
        } else {
          minco = i + 2;
        }
      } else if (result[i][1] > result[i + 1][1]) {
        minco = i + 1;
        if (result[i + 1][1] < result[i + 2][1]) {
          minco = i + 1;
        } else {
          minco = i + 2;
        }
      }
    }
    cout << "The " << maxc + 1 << " seller got the biggest money revolution of "
         << result[maxc][0] << endl;
    cout << "The " << maxco + 1 << " seller got the biggest comission of "
         << result[maxco][1] << endl;
    cout << "The " << minco + 1 << " seller got the smallest comission of "
         << result[minco][1] << endl;
    cout << "The sellers got the total of "
         << result[0][0] + result[1][0] + result[2][0] << endl;
    cout << "The sellers got the total comission of "
         << result[0][1] + result[1][1] + result[2][1] << endl;
    cout << "The sellers got " << result[0][0] + result[1][0] + result[2][0]
         << endl;
    break;
  }
  case 9: {
    string str;
    cout << "Enter the radix of previous numeric system(up to 36)" << endl;
    cin >> r;
    cout << "Enter the radix of new numeric system(up to 36)" << endl;
    int rnew;
    cin >> rnew;
    cout << "Enter number with radix of numeric system " << r << endl;
    cin >> str;
    vector<int> resultn;
    vector<char> result;
    int a[str.length()];
    for (int i = 0; i < str.length(); i++) {
      if ((int)str[i] >= 48) {
        if ((int)str[i] >= 65) {
          a[i] = (int)str[i] - 55;
        } else {
          a[i] = (int)str[i] - 48;
        }
      }
    }
    for (int i = 0; i < str.length(); i++) {
      summ0 += a[i] * pow(r, (str.length() - 1 - i));
    }
    cout << "Your number with radix of 10: " << summ0 << endl;
    int vsum;
    for (int i = 0; i > (-1); i++) {
      int summ1 = summ0;
      resultn[i] = num(i) % r;
      cout << resultn[i];
      int size = resultn.size();
      vsum = 0;
      for (int k = 0; k < resultn.size(); k++) {
        vsum += resultn[k] * pow(r, (size - 1 - k));
        //    cout<<vsum;
      }
      if (vsum == summ0) {
        break;
      }
    }
    int size = resultn.size();
    cout << size << endl;
    for (int i = 0; i < size; i++) {
      if (resultn[i] > 9) {
        result[size - i] = (char)(resultn[i] + 55);
      } else {
        result[size - i] = (char)(resultn[i] + 48);
      }
    }

    for (int i = 0; i < size; i++) {
      cout << (char)result[i];
    }

  } break;
    return 0;
  }
  ending();
}
int ending() {
  cout << "Type any number to continue" << endl;
  cin >> pus;
  printf("\e[1;1H\e[2J");
  // system("cls");
  return main();
}
