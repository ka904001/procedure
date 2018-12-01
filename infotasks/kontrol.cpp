#include <cmath>
#include <cstdint>
#include <iostream>
#define _USE_MATH_DEFINES

int choice = 0, pus = 0;
int ending();
void menu() {
  std::cout << "For first task type 1\n"
               "For second task type 2\n"
               "For third task type 3\n"
               "For fourth task type 4\n"
               "For fifth task type 5\n"
               "If you wish to finish type 6"
            << '\n';
  std::cin >> choice;
}

int main() {
  menu();
  switch (choice) {
  case 1: {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::cout << (c - a) / b;
    ending();
  }
  case 2: {
    int n = 0;
    std::cin >> n;
    (n % 3 == 0) ? std::cout << n / 3 << std::endl
                             << '0'
                 : (n % 3 == 1) ? std::cout << (n - 3) / 3 << std::endl
                                            << '1'
                                : std::cout << (n - 6) / 3 << std::endl
                                            << '2';
    ending();
  }
  case 3: {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::cout << n * (n + 1) * m * (m + 1) / 4;
    ending();
  }
  case 4: {
    int n = 0, a[9], res = 0;
    std::cin >> n;
    for (; n > 0; n--) {
      int t = 0;
      std::cin >> t;
      (t < 37) ? a[(t - 1) / 4]++ : a[(t - 35) / 2]++;
    }
    for (; n < 9; n++) {
      if (a[n] == 6)
        res++;
    }
    std::cout << res;
    ending();
  }
  case 5: {
    uint64_t n = 0, k = 0, i = 1;
    uint64_t a[2][4] = {{0, 0, 0}, {0, 0, 0}};
    std::cin >> n >> k;
    a[0][1] = n;
    a[1][1] = 1;
    if (k == 1) {
      std::cout << (a[0][1] / 2 - (int)(a[0][1] % 2 == 0)) << std::endl
                << a[0][1] / 2 << std::endl;
    } else {
      for (; k > i; i *= 2) {
        if (a[0][0] != 0 && a[0][0] % 2 == 0 && a[0][1] % 2 == 1) {
          a[0][2] = a[0][1] / 2 - 1;
          a[0][3] = a[0][1] / 2;
        } else {
          a[0][2] = a[0][1] / 2 - (int)(a[0][1] % 2 == 0);
          a[0][3] = a[0][1] / 2;
        }
        a[1][2] = 0;
        a[1][3] = 0;
        ((a[0][0] / 2 - (int)(a[0][0] % 2 == 0)) == a[0][2])
            ? a[1][2] += a[1][0]
            : a[1][3] += a[1][0];
        ((a[0][0] / 2) == a[0][3]) ? a[1][3] += a[1][0] : a[1][2] += a[1][0];
        ((a[0][1] / 2 - (int)(a[0][1] % 2 == 0)) == a[0][2])
            ? a[1][2] += a[1][1]
            : a[1][3] += a[1][1];
        ((a[0][1] / 2) == a[0][3]) ? a[1][3] += a[1][1] : a[1][2] += a[1][1];
        k -= i;
        a[0][0] = a[0][2];
        a[0][1] = a[0][3];
        a[1][0] = a[1][2];
        a[1][1] = a[1][3];
        //std::cout << a[0][2] << ' ' << a[0][3] << std::endl;
        //std::cout << a[1][2] << ' ' << a[1][3] << std::endl;
      }
      // std::cout<<a[0][2]<<' '<<a[0][3]<<std::endl;
      // std::cout<<a[1][2]<<' '<<a[1][3]<<std::endl;
      // std::cout << a[1][3] << std::endl;
      (k > a[1][3])
          ? std::cout << (a[0][2] / 2 - (int)(a[0][2] % 2 == 0)) << std::endl
                      << a[0][2] / 2 << std::endl
          : std::cout << (a[0][3] / 2 - (int)(a[0][3] % 2 == 0)) << std::endl
                      << a[0][3] / 2 << std::endl;
      ending();
    }
  }
  }
  return 0;
}

int ending() {
  std::cout << "Type any number to continue" << std::endl;
  std::cin >> pus;
  printf("\e[1;1H\e[2J");
  // system("cls");
  return main();
}
