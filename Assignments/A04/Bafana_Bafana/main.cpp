#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int testCases, players, current, moves;

  cin >> testCases;

  for(int i = 0; i < testCases; i++) {
    cin >> players >> current >> moves;

    int num = (current+moves)%players;
    if(num == 0) 
      num = players;

    printf("Case %d: %d\n", i+1, num);
  }
    
}
