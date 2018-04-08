#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int getPares(vector<int> p, int d) {
  int pares = 0;

  for (int i = 0; i < (int) p.size(); i++) {
    for (int j = i + 1; j < (int) p.size(); j++) {
      if (p[j] == p[i]) {
	for (int k = i + 1; k < j; k++) {
	  if (abs((double) p[k] - p[i]) <= d) {
	    if (k == j - 1) pares++;
	  } else {
	    break;
	  }
	}
      }
    } 
    //
    //cout << "  i = " << i << ", pares = " << pares << endl;
    //
  }

  return pares;
}

int main() {
  int c;
  cin >> c;

  vector<int> pares(c);

  for (int i = 0; i < c; i++) {
    int n, d;
    cin >> n >> d;
    //
    //cout << "n = " << n << ", d = " << d << endl;
    //

    vector<int> p(n);
    for (int j = 0; j < n; j++) {
      int pj;
      cin >> pj;
      p[j] = pj;
    }

    //
    //for (int j = 0; j < n; j++) {
    //  cout << " j = " << j << ", p[j] = " << p[j] << endl;
    //}
    //

    int currentPares = getPares(p, d);
    //
    //cout << "  pares = " << currentPares << endl;
    //
    pares[i] = currentPares; 
  }

  for (int i = 0; i < c; i++) {
    cout << pares[i] << endl;
  }
  
  return 0;
}
