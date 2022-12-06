#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  
  string word; 
  int caseNum = 1;

  while(cin >> word) {
    if(word == "*")
      break;

    printf("Case %d: ", caseNum);
    caseNum++;
    if(word == "Hajj") {
      cout << "Hajj-e-Akbar\n";
    }
    else {
      cout << "Hajj-e-Asghar\n";
    }
    
  }
}
