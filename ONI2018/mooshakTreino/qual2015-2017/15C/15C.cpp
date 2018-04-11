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

bool isDiffDir(int dir1, int dir2) {
  if ((dir1 > 0 && dir2 < 0) || (dir1 < 0 && dir2 > 0)) {
    return true;
  }

  return false;
}

bool isFogoDir(int x, int prevDir) {
  if (x < 100) return false;

  int prev = x % 10;
  x /= 10;
  int current = x % 10;
  
  int currentDir = prev - current;

  if (isDiffDir) {
    return true;
  } else {
    return isFogoDir(x, currentDir);
  }

  return false;
}

bool isFogo(int x) {
  return isFogoDir(x, 0);
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
