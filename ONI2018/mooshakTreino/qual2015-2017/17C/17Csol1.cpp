#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> conjunto(n);

  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    conjunto[i] = j;
  }

  int max = 0;

  for (int i = 0; i < n; i++) {
    vector<int> subconjunto;
    subconjunto.push_back(conjunto[i]);

    for (int j = 0; j < n; j++) {
      if (j == i) {
        continue;
      }

      for (int k = 0; k < (int) subconjunto.size(); k++) {
        if (subconjunto[k] % conjunto[j] == 0 || conjunto[j] % subconjunto[k] == 0) {
          subconjunto.push_back(conjunto[j]);
          break;
        }
      }
    }

    if ((int) subconjunto.size() > max) {
      max = subconjunto.size();
    }
  }

  cout << max << endl;
  
  
  return 0;
}
