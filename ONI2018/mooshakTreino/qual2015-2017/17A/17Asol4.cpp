#include <iostream>
#include <string>
using namespace std;

int main() {

  // 100 pts. sol.

  int n, b, i, encontrados = 0;
  cin >> n >> b >> i;
  b -= 1;

  string arcas;
  cin >> arcas;

  int maxE = b, maxD = b;

  for (int x = 0; x < i; x++) {
    char d;
    cin >> d;

    int p;
    cin >> p;

    int sentido = (d == 'E' ? -1 : 1);

    p *= sentido;

    b += p;

    if (sentido == -1 && b < maxE) {
      maxE = b;
    }

    if (sentido == 1 && b > maxD) {
      maxD = b;
    }
  }

  for (int x = maxE; x <= maxD; x++) {
    if (arcas[x] == 'T') {
      encontrados++;
    }
  }

  cout << encontrados << endl;


  return 0;
}
