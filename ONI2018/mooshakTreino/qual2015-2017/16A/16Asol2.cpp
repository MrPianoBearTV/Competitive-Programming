/*
Descrição:
A cada iteração dos caracteres da string verificar se é rapariga, se for,
incrementar o número de raparigas consecutivas. Se for rapaz, adicionar
o número de raparigas consecutivas ao número de pares. Ao longo das
iterações, se na posição i - k estiver uma rapariga, diminuir o
número de raparigas consecutivas, já que passa a distância máxima k.

Pontuação: 100 pontos
Complexidade temporal: O(N)
Complexidade espacial: O(N)
*/
#include <iostream>
#include <string>
using namespace std;

int pares(string a, int n, int k) {
  int pares = 0;
  int ms = (a[0] == 'M' ? 1 : 0);

  for (int i = 1; i < n; i++) {
      if (a[i] == 'M') {
        ms++;
      } else {
        pares += ms;
      }

      if (i - k >= 0 && a[i - k] == 'M') ms--;
  }

  return pares;
}

int main() {
  int n, k;
  cin >> n >> k;

  string a;
  cin >> a;

  
  cout << pares(a, n, k) << endl;

  return 0;
}
