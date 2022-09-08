/**************************************************************************************
*                    
*  Author:           Noah Orta
*  Email:            noahraulscout@gmail.com  
*  Label:            A05
*  Title:            Traffic Lights UVA 161
*  Course:           CMPS 4883
*  Semester:         Spring 2022
* 
* Description:
*      Given a set of traffic lights with varrying times for their cycle this program
*      will find out in what amount of time all of the lights are green
*
* Files: 
*      main.cpp
* 
**************************************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isGreen(int cycleTime, int time);

int main() {
  
  stringstream ss;

  char peeker = '1';

  vector<int> lights;              //stores all the traffic light cycles in a stores

  int time = 1;                    //  seconds that have passed
  int minTime = 150;               //  minimun time that has to pass before the check
                                   //  can be preformed
  const int overTime = 18002;      //  5 hours and one sec, 
  bool allGreen = false;           //  says if all the lights are green
  int cycleTime;                   //holds the cycle time being read in to be used by pushback


   //loops through all the different sets of lights
  while(peeker != '0') {
      
    time = 1;
    minTime = 150;
    allGreen = false;
    lights.clear();

    
    int x = 0;                      //the subscript of what we are adding in
    cin >> cycleTime;               //read in the cycle time
    lights.push_back(cycleTime);    //add it to the vector

    //  reads in the infile, light cycles, to store in the vector
    while(lights[x] != 0) {
      x++;
      cin >> cycleTime;             //read in the cycle time
      lights.push_back(cycleTime);  //add it to the vector
    }
    lights.pop_back();              //delete the zero from the end;

    // Finds the smallest cycle time to know when we can start 
    // looking for all greens
    for(int i = 0; i < lights.size(); i++) {
      if(minTime > lights[i]) {     // If the loop finds a smaller value than
        minTime = lights[i];        // whats stored in min, then assign that
      }                             // value to it
    }


    //  Runs through every second until all the stop lights are green
    //  or until the time reaches 5 hours
    for(time = 0; time < overTime && (!allGreen); time++) {

      // this loop will skip till the time where the smallest cycle 
      // has already passed once, or in a crazy scenerio, 5 hours pass
      while(minTime > time && time < overTime) {
        time++;
      }

      allGreen = true;     // set to true and wait for a light to make it false
      //  Runs through all lights in the set to see if they're green or not
      //  if one is not green then get out of the for loop to save time
      for(int i = 0; i < lights.size() && allGreen; i++) {
        if(!isGreen(lights[i], time)) {   //if a light is not green, break from the loop
          allGreen = false;
          break;
        }
      }

    }

    // if we found a time when all the lights are green at the same time
    //  then print out the formitted time
    if(allGreen) {
      time -=2;       //  an extra second was added in the for loop
      //cout << "total seconds: " << time << endl;

      int hours = time / 3600;          //how many hours have passed 
      int minutes = (time % 3600) / 60; //mins that have passed 
      int seconds = time - ((hours * 3600) + (minutes * 60));
      cout << setfill('0') << setw(2) << hours << ":";
      cout << setfill('0') << setw(2) << minutes<< ":";
      cout << setfill('0') << setw(2) << seconds << '\n'; 
    }
    else {
      cout << "Signals fail to synchronise in 5 hours\n";
    }

    cin.ignore(3, '\n');
    peeker = cin.peek();

  }

}

/////////////////////////////////////////////////////////////////////
//
//  Determines whether the stop light is green at time than
//
//  params: int cycleTime - how long the cycle time of the current 
//                          light is in seconds
//
//          int time      - how many seconds have passed
//
//  return: bool - whether the light is green or not
//
bool isGreen(int cycleTime, int currentTime) {
  bool isGreen = false;  //if the light is green

  int completeCycle = cycleTime*2; //the amount of time a complete cycle takes
  int gTime = cycleTime - 5;       //the amount of time at which the light is green

  int part;      // the part of the cycle we are currently at (green or not green) 
  part = (currentTime % completeCycle);

  if(part > 0 && part <= gTime) {
    return 1;
  }
  else {
    return 0;
  }
}
