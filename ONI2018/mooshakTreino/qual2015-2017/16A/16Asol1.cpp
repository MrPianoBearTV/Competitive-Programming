/*
Descrição:
Percorrer os olímpicos, se for rapariga, percorrer os olímpicos entre a posição
imediatamente a seguir à rapariga até à posição imediatamente a seguir à
rapariga + k, se o olímpico for rapaz, incrementar o número de pares.

Pontuação: 65 pontos
Complexidade temporal: O(K*N) 
Complexidade espacial:
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  string a;
  cin >> a;

  int pares = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] == 'M') {
      for (int j = i + 1; j < i + 1 + k; j++) {
        if (a[j] == 'H') {
          pares++;
        }
      }
    }
  }

  cout << pares << endl;

  return 0;
}
