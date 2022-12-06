#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int testCases, students;

  cin >> testCases;

  for(int i = 0; i < testCases; i++) {
    cin >> students;
    
    // getting the sum of the students grades
    vector<double> grades;
    int sum = 0, num;
    for(int j = 0; j < students; j++) {
      cin >> num;
      grades.push_back(num);
      sum += num;
    }

    // get avg
    double avg = sum / students;

    //cout << avg << '\n';

    // calculate how many students were above avg
    double above = 0; 
    for(int j = 0; j < grades.size(); j++) {
      if(grades[j] > avg) 
        above++;
    }

    double percent = round((above/students)*100000)/1000.0;

    printf("%.3f%\n", percent);
  }
}
