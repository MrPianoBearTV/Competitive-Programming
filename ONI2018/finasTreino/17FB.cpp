#include<iostream>
#include<vector>
using namespace std;

long bestPont(int n, int a, int b, int i, vector<int> estacoes, vector<int> zonas) {
  int current;

}

int main() {

  int n, a, b, i;
  cin >> n >> a >> b >> i;

  vector<int> estacoes(n);
  for (int i = 0; i < n; i++) {
    int estacao;
    cin >> estacao;
    estacoes[i] = estacao;
  }

  vector<int> zonas(n);
  for (int i = 0; i< n; i++) {
    int zona;
    cin >> zona;
    zonas[i] = zona;
  }

  cout << bestPont(n, a, b, i, estacoes, zonas) << endl;

  return 0;
}
