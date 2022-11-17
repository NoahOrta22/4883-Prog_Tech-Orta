#include <iostream>

using namespace std;

int main() {
  int testCases;

  cin >> testCases;

  for(int i = 0; i < testCases; i++) {
    int a, b;
    cin >> a >> b;

    // if a is even make it odd
    if(a%2 == 0)
      a++;

    // add up the sum
    int sum = 0;
    while(a <= b) {
      sum += a;
      a += 2;
    }

    // print the sum
    cout << "Case " << i+1 << ": " << sum << '\n';
  }
}
