#include <iostream>
using namespace std;

bool isPrime(int);

int main() {
  int n;

  cin >> n;

  if (isPrime(n)) {
    cout << n << " e primo" << endl;
  } else {
    cout << n << " nao e primo" << endl;
  }

  return 0;
}

bool isPrime(int n) {
  if (n != 2 && n % 2 == 0) return false;
  if (n != 3 && n % 3 == 0) return false;
  if (n != 5 && n % 5 == 0) return false;
  if (n != 7 && n % 7 == 0) return false;
  if (n != 11 && n % 11 == 0) return false;
  if (n != 13 && n % 13 == 0) return false;

  return true;
}
