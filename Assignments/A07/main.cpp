/**************************************************************************************
*                    
*  Author:           Noah Orta
*  Email:            noahraulscout@gmail.com  
*  Label:            A07
*  Title:            Rails
*  Course:           CMPS 4883
*  Semester:         Fall 2022
* 
* Description:
*      See if we can push and pop items off a stack so that we order them sequentially.
*
* Files: 
*      main.cpp
*      input.txt
* 
**************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
*   Checker
*
*   Description:
*       Checks to see if we can reorder the train on a "Y" shaped train 
*       track so the carts are in sequential order.
*
*
*   Public:
*       
*                       Checker()
*
*       void            getCargo()
*       void            solve()
*
*   Usage:
*       Checker check                    - makes a Checker object
*       check.solve()                    - solves the problem
*
*/
class Checker {
  private:

  vector<int> cargo;                          //  the order the cargo came in (the "queue")
  vector<int> order;                          //  sequential order its supposed to be in
  vector<int> stack;                          //  the stack (bottom of the "Y")

  int coaches;

  public:

  //
  // Description: gets the number of how many cargo containers/coaches there are
  //              then sets up the "order" queue
  //
  Checker(int c) {
    for(int i = 0; i < c; i++) {
      order.push_back(i+1);
    }

    coaches = c;
  }

  //
  //  Description: Gets the order that the cargo originally came in. 
  //
  void getCargo() {
    
    cargo.clear();

    // gets the order of the cargo
    for(int i = 0; i < coaches; i++) {
      int num;
      cin >> num;
      cargo.push_back(num);
    }
  }

  //
  //  Description: Finds if we can reorder the cargo containers sequentially
  //
  void solve() {
    vector<int> queue = order;

    char next = 'a';
    bool job = true;

    while(next != '0') {
      
      getCargo();

      /*for(int i = 0; i < coaches; i++) {
        cout << cargo[i] << " ";
      }
      cout << '\n';*/
      
      queue = order;                          // sets up the queue to have the order
      stack.clear();                          // clears out the stack from the last use
      job = true;                             // make the job true till it makes itself false

      while(job && (!queue.empty() || !stack.empty())) {
        job = false;
        
        if(queue[0] < cargo[0]) {
          stack.push_back(queue[0]);      
          queue.erase(queue.begin());
          job = true;
        }
  
        else if(queue[0] == cargo[0]) {
          queue.erase(queue.begin());
          cargo.erase(cargo.begin());
          job = true;
        }
  
        else if(stack.back() == cargo[0]) {
          cargo.erase(cargo.begin());
          stack.pop_back();
          job = true;
        }
      }
      if(job) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }

      cin >> ws;
      next = cin.peek();

      //cout << next << " <---\n";
    }
    cin >> next;
  }

};


//
//  main driver of the program
//
int main() {

  int numCoaches;

  cin >> numCoaches;

  do {

    Checker checker(numCoaches);
    checker.solve();

    cin >> numCoaches;

    cout << '\n';
    
  }while(numCoaches != 0);
  
}
