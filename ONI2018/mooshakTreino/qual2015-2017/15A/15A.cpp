/*
Descrição:
Para cada linha de input criar um objeto da class Aluno com o respetivo nome e
classificacao, ao somar as n pontuacoes. Depois, usar o algoritmo sort do std
com um comparator que depende da classificacao de cada aluno e se estes tiverem
a mesma classificacao, organizar por ordem alfabética.

Pontuação: 100 pontos
Complexidade temporal: O(N*P+N*log(N))
Complexidade espacial: O(N)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Aluno {
public:
  Aluno(string name = "", int c = 0) : name_(name), c(c) {}
  string name() { return name_; }
  int classificacao() { return c; }
private:
  string name_;
  int c;
};

bool compAlunos(Aluno a1, Aluno a2) {
  if (a1.classificacao() > a2.classificacao()) {
    return true;
  } else if (a1.classificacao() == a2.classificacao() && a1.name() < a2.name()) {
    return true;
  }

  return false;
}

int main() {
  int n, p;
  cin >> n >> p;

  vector<Aluno> alunos(n);

  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;

    int c = 0;
    for (int j = 0; j < p; j++) {
      int pont;
      cin >> pont;
      c += pont;
    }

    Aluno aluno(name, c);
    alunos[i] = aluno;
  }

  sort(alunos.begin(), alunos.end(), compAlunos);

  for (int i = 0; i < n; i++) {
    cout << alunos[i].name() << " " << alunos[i].classificacao() << endl;
  }
}

