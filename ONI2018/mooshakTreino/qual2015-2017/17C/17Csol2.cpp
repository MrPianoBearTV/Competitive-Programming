#include <iostream>
#include <vector>
using namespace std;

int calculate(vector<int>::iterator it, vector<int> a, vector<int> b) {

  if (it == a.end()) return (int) b.size();

  bool add = true;
  for (int i = 0; i < (int) b.size(); i++) {
    if (!(*it % b[i] == 0 || b[i] % *it == 0)) {
      add = false;
      break;
    }
  }

  if (add) {
    b.push_back(*it);
  }

  return calculate(it++, a, b);
}

int main() {

  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int max = 0;

  for (int i = 0; i < n; i++) {
    vector<int> b;
    b.push_back(a[i]);
    int calc = calculate(a.begin(), a, b);
    if (calc > max) {
      max = calc;
    }
  }

  cout << max << endl;

  return 0;
}
