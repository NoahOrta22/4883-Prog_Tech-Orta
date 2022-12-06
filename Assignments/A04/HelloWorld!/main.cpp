#include <iostream>

using namespace std;

int main() {

  int num;
  int testCase = 0;

  cin >> num;
  
  while(num >= 0) {
    
    testCase++;

    if(num == 0) {
      cout << "Case " << testCase << ": " << 0 << '\n';
      cin >> num;
      continue;
    }
    
    int sum = 1;
    int loop = 1;
    while(sum < num) {
      // cout << "loop: " << loop << '\n';
      // cout << "sum: " << sum << '\n' << '\n';
      
      sum += sum;
      loop++;
    }
    cout << "Case " << testCase << ": " << loop-1 << '\n';

    cin >> num;
  }   
}
