#include <iostream>
#include <vector>
using namespace std;

int getLength(vector<vector<int> > charcos, int x) {
  int length = 0;

  int n = charcos.size();
  for (int i = 0; i < n; i++) {
    int x1 = charcos[i][0];
    int x2 = charcos[i][2];

    if (x1 <= x && x2 >= x) {
      int y1 = charcos[i][1];
      int y2 = charcos[i][3];

      length += y2 - y1;
    }
  }


  return length;
}

int main() {

  // 35 pts. sol.

  int n, q;
  cin >> n >> q;

  vector<vector<int> > charcos(n);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    charcos[i].push_back(x1);
    charcos[i].push_back(y1);
    charcos[i].push_back(x2);
    charcos[i].push_back(y2);
  }

  vector<int> posicoes(q);
  for (int i = 0; i < q; i++) {
    int pos;
    cin >> pos;
    posicoes[i] = pos;
  }


  for (int i = 0; i < q; i++) {
    cout << getLength(charcos, posicoes[i]) << endl;
  }

  return 0;
}
