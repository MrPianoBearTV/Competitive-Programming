#include <iostream>
#include <vector>
using namespace std;

long shortestDistance(vector<vector<int> > passeios, vector<vector<int> > passadeiras, int A, int B, int C, int D) {
  // A - ponto de partida
  // B - passeio de cima ou baixo
  // C - ponto de chegada
  // D - passeio de cima ou baixo
  
  int distance = 0;
  int current = A;

  //
  /*
  cout << "Call ao shortest distance" << endl;
  cout << " A = " << A << endl;
  cout << " B = " << B << endl;
  cout << " C = " << C << endl;
  cout << " D = " << D << endl;
  */
  //

  // mesmo passeio
  if (B == D) {
    //
    //cout << "Caso 1" << endl;
    //
    while (current < C) {
      distance += passeios[B-1][current];
      current++;
    }
  } else {
    //
    //cout << "Caso 2" << endl;
    //

    int passadeiraX = passadeiras[0][0];
    int passadeiraT = passadeiras[0][1];
    //
    //cout << "Definir os int's da passadeira" << endl;
    //cout << " passadeiraX = " << passadeiraX << endl;
    //cout << " passadeiraT = " << passadeiraT << endl;
    //

    int otherY = 0;
    if (B == 0) otherY = 1;

    //
    //cout << " otherY = " << otherY << endl;
    //
    
    //
    //cout << "1o loop:" << endl;
    //

    while (current < passadeiraX) {
      //
      //cout << " current = " << current << endl;
      //cout << " distance = " << distance << endl;
      //
      distance += passeios[B-1][current];
      current++;
    }

    //
    //cout << "1o loop done" << endl;
    //

    distance += passadeiraT;
    
    //
    //cout << " current = " << current << endl;
    //cout << " distance = " << distance << endl;
    //

    //
    //cout << "2o loop:" << endl;
    //

    if (passadeiraX < C) {
      while (current < C) {
        //
        //cout << "current = " << current << endl;
        //cout << "distance = " << distance << endl;
        //
        distance += passeios[otherY][current++];
      }
    } else if (passadeiraX > C) {
      while (current > C) {
        //
        //cout << "current = " << current << endl;
        //cout << "distance = " << distance << endl;
        //
        distance += passeios[otherY][--current];
      }
    
    }

  
  }

  return distance;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int> > passeios(2, vector<int>(n - 1));
  for (int i = 0; i < n - 1; i++) {
    int seg;
    cin >> seg;
    passeios[0][i] = seg;
  }

  for (int i = 0; i < n - 1; i++) {
    int seg;
    cin >> seg;
    passeios[1][i] = seg;
  }

  int s;
  cin >> s;
  vector<vector<int> > passadeiras(s, vector<int>(2));
  for (int i = 0; i < s; i++) {
    int p, t;
    cin >> p >> t;
    passadeiras[i][0] = p;
    passadeiras[i][1] = t;
  }

  int q;
  cin >> q;
  vector<vector<int> > perguntas(q, vector<int>(4));
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    perguntas[i][0] = a;
    perguntas[i][1] = b;
    perguntas[i][2] = c;
    perguntas[i][3] = d;
  }

  //
  /*
  cout << "n = " << n << endl;
  cout << "passeios: " << endl;
  for (int i = 0; i < (int) passeios[0].size(); i++) {
    cout << " passeios[0][" << i << "] = " << passeios[0][i] << endl;
  }

  for (int i = 0; i < (int) passeios[1].size(); i++) {
    cout << " passeios[1][" << i << "] = " << passeios[1][i] << endl;
  }

  cout << "s = " << s << endl;
  for (int i = 0; i < (int) passadeiras.size(); i++) {
    for (int j = 0; j < (int) passadeiras[i].size(); j++) {
      cout << " passadeiras[" << i << "][" << j << "] = " << passadeiras[i][j] << endl;
    }
  }

  cout << "q = " << q << endl;
  for (int i = 0; i < (int) perguntas.size(); i++) {
    for (int j = 0; j < (int) perguntas[i].size(); j++) {
      cout << " perguntas[" << i << "][" << j << "] = " << perguntas[i][j] << endl;
    }
  }
  */
  //
  
  for (int i = 0; i < q; i++) {
    //
    //cout << "Antes do shortestDistance" << endl;
    //
    cout << shortestDistance(passeios, passadeiras, perguntas[i][0], perguntas[i][1], perguntas[i][2], perguntas[i][3]) << endl;
  }
  

  






}
