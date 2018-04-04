/*
Descrição:
Guardar o input, onde a linha de assentos é guardada numa string de C para os
assentos não partidos(0) serem registados corretamente. De seguida passar essa
string para um vector<int>. Depois, alterar os assentos consoante o input e
quando o input é Q, percorrer o vector e contar o número máximo de assentos
contíguos.

Pontuação: 30 pontos
Complexidade temporal: O(Q*N)
Complexidade espacial: O(N)
*/


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int maiorNum(vector<int> assentos) {
  int max = 0;
  int currentMax = 0;

  for (int i = 0; i < (int) assentos.size(); i++) {
    if (assentos[i] == 0) {
      currentMax++;
    } else {
      if (currentMax > max) {
	max = currentMax;
      }
      currentMax = 0;
    }
  }

  if (currentMax > max) {
    max = currentMax;
  }

  return max;
}

int main() {

  int n, q;
  cin >> n >> q;

  char assentosString[n];
  scanf("%s", assentosString);

  vector<int> assentos(n);

  for (int i = 0; i < n; i++) {
    assentos[i] = assentosString[i] - '0';
  }
	
  for (int i = 0; i < q; i++) {
    char formato;
    cin >> formato;

    int k = 0;

    if (formato != 'Q') {
      cin >> k;
    }

    if (formato == 'P') {
      assentos[k - 1] = 1;
    } else if (formato == 'A') {
      assentos[k - 1] = 0;
    } else if (formato == 'Q') {
      cout << maiorNum(assentos) << endl;
    }
  }

  return 0;
}
