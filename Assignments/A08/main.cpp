#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

unordered_map<char, int> key;
char keyMatrix[3][3] = {{'R', 'P', 'R'}, 
                        {'P', 'P', 'S'},
                        {'R', 'S', 'S'}};

// decides who the winner is based off two player's moves
// char winner(char player1, char player2) {
//   // unordered_map<char, int> key;
//   // key['R'] = 0;          // row one column one
//   // key['P'] = 1;          // row two column two
//   // key['S'] = 2;          // row three column three

//   // char keyMatrix[3][3] = {{'R', 'P', 'R'}, 
//   //                         {'P', 'P', 'S'},
//   //                         {'R', 'S', 'S'}};

//   return keyMatrix[key[player1]][key[player2]];

// }

// replaces the spot with the winner
void replace(vector<vector<char>> &graph) {
  // char change = graph[r][c];

  vector<vector<char>> temp(graph);


  // let everyone play the person next to them (cardinal directions)
  for(int r = 0; r < graph.size(); r++) {
    for(int c = 0; c < graph[0].size(); c++) {
      char letter;
      
      // one down
      if(r+1 < graph.size()) {
        // see who the winner is, and replace if it changes the original
        //letter = winner(graph[r][c], graph[r+1][c]);
        letter = keyMatrix[key[graph[r][c]]][key[graph[r+1][c]]];
        if(letter != graph[r][c]) {
          temp[r][c] = letter;
          continue;
        }
      }
      //one up
      if(r-1 >= 0) {
        // see who the winner is, and replace if it changes the original
        //letter = winner(graph[r][c], graph[r-1][c]);
        letter = keyMatrix[key[graph[r][c]]][key[graph[r-1][c]]];
        if(letter != graph[r][c]) {
          temp[r][c] = letter;
          continue;
        }
      }
      //one to the right
      if(c+1 < graph[0].size()) {
        // see who the winner is, and replace if it changes the original
        //letter = winner(graph[r][c], graph[r][c+1]);
        letter = keyMatrix[key[graph[r][c]]][key[graph[r][c+1]]];
        if(letter != graph[r][c]) {
          temp[r][c] = letter;
          continue;
        }
      }
      //one to the left
      if(c-1 >= 0) {
        // see who the winner is, and replace if it changes the original
        //letter = winner(graph[r][c], graph[r][c-1]);
        letter = keyMatrix[key[graph[r][c]]][key[graph[r][c-1]]];
        if(letter != graph[r][c]) {
          temp[r][c] = letter;
          continue;
        }
      }

    }
  }

  //now we update the environment
  graph = temp;
  
}

void survival(int days, vector<vector<char>> &graph) {

  vector<vector<char>> temp(graph);

  for(int i = 0; i < days; i++) {
    replace(graph);
  }
  // if(days == 0){
  //   return;
  // }
  // else {
  //   replace(graph);
  //   survival(days-1, graph);
  // }
  
}

int main() {

  auto start = std::chrono::high_resolution_clock::now();

  key['R'] = 0;          // row one column one
  key['P'] = 1;          // row two column two
  key['S'] = 2;          // row three column three
  
  int testCases;
  cin >> testCases;

  int numRows = 0, numColumns = 0, numDays = 0;

  // loop through all the test cases
  for(int i = 0; i < testCases; i++) {

    // get number of rows and columns
    cin >> numRows >> numColumns >> numDays;

    cin.ignore(1, '\n'); // flush the buffer

    vector<vector<char>> env(numRows, vector<char>(numColumns));

    for(int r = 0; r < numRows; r++) {
      string row;
      getline(cin, row);          // get the line of Characters

      for(int c = 0; c < numColumns; c++) {
        env[r][c] = row[c];
      }
    }

    survival(numDays, env);

    for(int r = 0; r < numRows; r++) {
      for(int c = 0; c < numColumns; c++) {
        cout << env[r][c];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  auto end = std::chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::nanoseconds>(end-start).count();
}
