#include <iostream>
#include <string>
using namespace std;

int main() {

  // 65 pts. sol.

  int n, b, instrucoes, encontrados = 0;
  string arcas;

  cin >> n >> b >> instrucoes;

  cin >> arcas;

  string::iterator it = arcas.begin() + b - 1;
  if (*it == 'T') {
    encontrados++; 
    *it = 'V';
  }

  for (int j = 0; j < instrucoes; j++) {
    char direcao;
    cin >> direcao;

    int passos;
    cin >> passos;

    int dir = ( direcao == 'E' ? -1 : 1);

    for (int x = 0; x < passos; x++) {
      it += dir;
      if (*it == 'T') {
        encontrados++;
        *it = 'V';
      }
    }
  }

  cout << encontrados << endl;

  return 0;
}
