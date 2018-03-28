#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

  int n, k;

  cin >> n;
  cout << n << endl;

  for (int i = 0; i < n; i++) {
    cin >> k;

    vector<int> v(k);

    for (int j = 0; j < k; j++) {
      cin >> v[j];
    }

    sort(v.begin(), v.end());

    int min = v[1] - v[0];

    for (unsigned int i = 1; i < v.size() - 1; i++) {
      if (v[i + 1] - v[i] < min) min = v[i + 1] - v[i];
      if (min == 1) break;
    }

    cout << min << endl;
    


  }
  
}
