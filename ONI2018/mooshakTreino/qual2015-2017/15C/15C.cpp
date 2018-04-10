#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getLength(int x) {
    int length = 1;

    for (length = 0; x > 0; length++) {
        x /= 10;
    }

    return length;
}

bool isFogo(int x) {
  int prev = x % 10;
  x /= 10;

  int current = x % 10;

  // true -> crescente, false -> decrescente
  bool dir = prev < current ? true : false;

  for (x; x > 0; x /= 10) {
    prev = current;
    current = x % 10;

    if (dir) {
      if (prev <= current) {
	continue;
      } else {
	return true;
      }
    } else {
      if (prev >= current) {
	continue;
      } else {
	return true;
      }
    }
  }

  return false;
}

int getNums(int a, int b) {
    int nums = 0;


    for (int i = a; i <= b; i++) {
      if (isFogo(i)) nums++;
    }

    return nums;
}

int main() {

  // experimentar com long em vez de int

    int c;
    cin >> c;

    vector<int> nums(c);

    for (int i = 0; i < c; i++) {
      int a, b;
      cin >> a >> b;
      nums[i] = getNums(a, b);
    }
    
    for (int i = 0; i < c; i++) {
      cout << nums[i] << endl;
    }
    
    return 0;
}