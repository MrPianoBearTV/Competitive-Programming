#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, b, i, encontrados = 0;
  cin >> n >> b >> i;

  string arcas;
  cin >> arcas;

  int maxE = 0, maxD = 0;
  int apontador = b - 1;

  for (int x = 0; x < i; x++) {
    char dir;
    cin >> dir;

    int passos;
    cin >> passos;

    if (dir == 'E') {
      apontador -= passos;
      if (apontador < maxE) {
        maxE = apontador;
      }
    } else {
      apontador += passos;
      if (apontador > maxD) {
        maxD = apontador;
      }
    }
  }

  apontador = b - 1;

  if (arcas[apontador] == 'T') {
    encontrados++;
    arcas[apontador] = 'V';
  }

  for (int x = 0; x < maxE; x++) {
    apontador--;
    if (arcas[apontador] == 'T') {
      encontrados++;
      arcas[apontador] = 'V';
    }
  }

  apontador = b - 1;

  for (int x = 0; x < maxD; x++) {
    apontador++;
    if (arcas[apontador] == 'T') {
      encontrados++;
      arcas[apontador] = 'V';
    }
  }

  cout << encontrados << endl;

}
