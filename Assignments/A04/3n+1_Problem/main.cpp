#include <iostream>
#include <algorithm>

using namespace std;

int counter(int num, int count) {
  if(num == 1) {
    count++;
    return count;
  }
  // it's odd
  else if(num % 2) {
    return counter(3*num+1, count+1);
  }
  // it's even
  else {
    return counter(num/2, count+1);
  }
}

int main() {
  
  int i, j;
  int minVal, maxVal;
  int count;

  while(cin >> i >> j) {
    count = 0;
    
    minVal = min(i, j);
    maxVal = max(i, j);

    for(int n = minVal; n <= maxVal; n++) {
      count = max(counter(n, 0), count);
    }
    
    cout << i << " " << j << " " << count << '\n';
  }
}
