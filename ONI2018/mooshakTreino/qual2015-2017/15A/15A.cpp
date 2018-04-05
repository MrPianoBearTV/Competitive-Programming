#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Aluno {
public:
  Aluno(string name="", vector<int> ponts = vector<int>()) : name_(name), ponts_(ponts) {}
  string name() { return name_; }
  vector<int> ponts() { return ponts_; }
  int classificacao() {
    int sum = 0;
    for (int i = 0; i < (int) ponts_.size(); i++) {
      sum += ponts_[i];
    }

    return sum;
  }
private:
  string name_;
  vector<int> ponts_;
};

bool compAlunosCl(Aluno a1, Aluno a2) { return (a1.classificacao() > a2.classificacao()); }

bool compAlunosAl(Aluno a1, Aluno a2) {
    if (a1.classificacao() == a2.classificacao()) {
      int n;
      
      if (a1.name().size() > a2.name().size()) {
	n = a2.name().size();
      } else {
	n = a1.name().size();
      }
      
      for (int i = 0; i < n; i++) {
	if (a1.name()[i] == a2.name()[i]) {
	  continue;
	} else if (a1.name()[i] < a2.name()[i]) {
	  return true;
	} else {
	  return false;
	}
      }
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

    vector<int> ponts(p);
    for (int j = 0; j < p; j++) {
      int pont;
      cin >> pont;
      ponts[j] = pont;
    }

    Aluno aluno(name, ponts);
    alunos[i] = aluno;
  }


  sort(alunos.begin(), alunos.end(), compAlunosCl);
  sort(alunos.begin(), alunos.end(), compAlunosAl);

  //
  // ver se funciona
  for (int i = 0; i < n; i++) {
    cout << alunos[i].name() << " " << alunos[i].classificacao() << endl;
  }
  //

}

