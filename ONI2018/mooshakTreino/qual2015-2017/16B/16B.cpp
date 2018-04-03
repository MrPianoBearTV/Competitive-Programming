/*
Descrição: 
Cria a grelha como descrita no enunciado, realçando que a cada "diagonal"
corresponde a variável k, que por sua vez corresponde à soma da abcissa x e da
ordenada y de cada quadrado da diagonal. De seguida, usa o mesmo método para
percorrer a grelha e guarda as coordenadas x e y de cada canto. Por fim,
adiciona todos os quadrados das coordenadas entre os dois cantos.

Pontuação: 35 pontos
Complexidade temporal:
Complexidade espacial:
*/
#include <iostream>
using namespace std;

int getSum(int grid[][550], int a, int b) {
  int ax, ay, bx, by, sum = 0;

  
  for (int k = 0; k < 510; k++) {
    for (int x = 0; x <= k; x++) {
      int y = k - x;
      if (grid[x][y] == a) {
	ax = x;
	ay = y;
      } else if (grid[x][y] == b) {
	bx = x;
	by = y;
      }
    }
  }

  for (int x = ax; x <= bx; x++) {
    for (int y = ay; y <= by; y++) {
      sum += grid[x][y];
    }
  }

  return sum;
}

int main() {
  int n;
  cin >> n;
  
  int grid[550][550];
  int current = 1;
  
  for (int k = 0; k < 510; k++) {
    for (int x = 0; x <= k; x++) {
      int y = k - x;
      grid[x][y] = current++;
    }
  }

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cout << getSum(grid, a, b) << endl;
  }
  
  return 0;
}
