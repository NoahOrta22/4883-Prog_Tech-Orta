#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int testCases, numWalls, height, heightPrev;

  cin >> testCases;

  // test Cases
  for(int i = 0; i < testCases; i++) {
    // types of jumps
    int downJump = 0;
    int upJump = 0;
    
    // number of walls
    cin >> numWalls;
    // if(numWalls == 1) {    // if no walls then skip
    //   continue;
    // }
    
    // the previous wall height
    cin >> heightPrev;
    
    //count the types of jumps
    for(int j = 1; j < numWalls; j++) {
      cin >> height;

      // jump up
      if(height > heightPrev) {
        downJump++; 
      }
      // jump down
      else if(height < heightPrev) {
        upJump++;
      }
      heightPrev = height;
    }
    printf("Case %d: %d %d\n", i+1, downJump, upJump);
  }
}
