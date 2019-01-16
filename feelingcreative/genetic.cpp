#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream file;
  file.open("out.txt", ios::out);
  int n = 1000, generation = 1;
  bool found = 0;
  srand(time(0));
  double parent[5][n], child[2][n], mutationrate = 0.01;
  /*
    parent[0] - x
    parent[1] - y
    parent[2] - f(x;y)
    parent[3] - fitness
    parent[4] - probability;
  */
  double maxvalue = 100, k = 200.0;
  for (int i = 0; i < n; i++) {
    parent[0][i] = (double)rand()/(double)RAND_MAX*maxvalue;
    parent[1][i] = (double)rand()/(double)RAND_MAX*maxvalue;
  }

  for (;; generation++) {

    cout << generation << endl;
    for (int i = 0; i < n; i++) {
      parent[2][i] = -(parent[0][i]-3)*(parent[0][i]-3)/16-(parent[1][i]+4)*(parent[1][i]+4)/32;
      //parent[2][i] = atan(parent[0][i] * sqrt(parent[1][i]));
      //file<<parent[0][i]<<" "<<parent[1][i]<<" "<<parent[2][i]<<endl;
      int count = 0;
      for (int j = 0; j < k; j++) {
        //diversity around point
        double x = pow(-1,(rand()%2))*rand()/RAND_MAX;
        double y = pow(-1,(rand()%2))*rand()/RAND_MAX;
        double okrestnost = -(parent[0][i]+x-3)*(parent[0][i]+x-3)/16-(parent[1][i]+y+4)*(parent[1][i]+y+4)/32;
        if (parent[2][i] >= okrestnost)
          count++;
      }
      //file<<count<<' ';
      parent[3][i] = pow((double)count/k, 3);
      if (1.0-parent[3][i]<0.01) {
        cout << parent[0][i] << " " << parent[1][i] << endl;
        found = 1;
      }
      if (found)
        break;
    }
    if (found)
      break;
    double summ = 0;
    for (int i = 0; i < n; i++) {
      summ += parent[3][i];
    }
    for (int i = 0; i < n; i++) {
      parent[4][i] = parent[3][i] / summ;
      file<<parent[0][i]<<" "<<parent[1][i]<<" "<<parent[2][i]<<" "<<parent[3][i]<<" "<<parent[4][i]<<" "<<endl;
    }
    // child making
    for (int i = 0; i < n; i++) {
      double random1 = (double)rand() / (double)RAND_MAX;
      double random2 = (double)rand() / (double)RAND_MAX;
      int index1 = 0, index2 = 0;
      while (random1 > 0) {
        random1 -= parent[4][i];
        index1++;
      }
      while (random2 > 0) {
        random2 -= parent[4][i];
        index2++;
      }
      child[0][i] = (parent[0][--index1] + parent[0][--index2]) / 2.0;
      child[1][i] = (parent[1][--index1] + parent[1][--index2]) / 2.0;
      double mutation = (double)rand() / (double)RAND_MAX;
      if ((mutation - mutationrate) < 0||abs(child[0][i])>100||abs(child[1][i])>100) {
        child[0][i] = (double)rand()/(double)RAND_MAX*maxvalue;
        child[1][i] = (double)rand()/(double)RAND_MAX*maxvalue;
      }
    }
    // transit of generations
    for (int i = 0; i < n; i++) {
      parent[0][i] = child[0][i];
      parent[1][i] = child[1][i];
    }
  }

  file << "We are done!!!" << endl;
  file.close();
  return 0;
}
