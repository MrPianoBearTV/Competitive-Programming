#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s) {
  if (s.length() == 1 || s.length() == 0) {
    return true;
  }

  if (s[0] != s[s.length() - 1]) {
    return false;
  }

  return isPalindrome(s.substr(1, s.length() - 2));
}

int main() {
  int n;

  cin >> n;
  cout << n << endl;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (isPalindrome(s)) {
      cout << "Sim" << endl;
    } else {
      cout << "Nao" << endl;
    }
  }
  return 0;
}
