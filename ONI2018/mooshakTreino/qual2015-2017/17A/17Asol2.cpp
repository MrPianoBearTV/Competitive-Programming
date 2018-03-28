#include <iostream>
#include <string>
using namespace std;

bool checkArca(string arcas, int apontador) {
  if (arcas[apontador] == 'T') {
    return true;
  }
  return false;
}

void esvaziarArca(string& arcas, int apontador) {
  arcas[apontador] = 'V';
}

void pisarArca(string& arcas, int apontador, int& encontrados) {
  if (checkArca(arcas, apontador)) {
    esvaziarArca(arcas, apontador);
    encontrados++;
  }
}

int main() {

  int n, b, i, encontrados = 0;
  cin >> n >> b >> i;

  string arcas;
  cin >> arcas;

  int apontador = b - 1;
  pisarArca(arcas, apontador, encontrados);

  for (int x = 0; x < i; x++) {
    char dir;
    cin >> dir;

    int passos;
    cin >> passos;

    int multiplicador = (dir == 'E' ? -1 : 1);

    for (int y = 0; y < passos; y++) {
      apontador += multiplicador;
      pisarArca(arcas, apontador, encontrados);
    }
  }

  cout << encontrados << endl;


  
  return 0;
}
