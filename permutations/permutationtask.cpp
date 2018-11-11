#include <iostream>
#include <vector>
using namespace std;

int answer;

void permute(int str[], int i, int n) {
  if (i == n) {
    for (int k = 0; k < n; k++) {
      if (str[k] == k) {
        answer++;
        break;
      }
    }
  } else {
    for (int temp, j = i; j < n; j++) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      permute(str, i + 1, n);
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      // backtrack.
    }
  }
}

int main() {
  int str[100];
	int n;
  cin >> n;
	for(int i = 0; i < n; i++){
		str[i] = i;
	}
  cout << endl;
  permute(str, 0, n);
  cout << "The answer is: " << answer;
  return 0;
}
