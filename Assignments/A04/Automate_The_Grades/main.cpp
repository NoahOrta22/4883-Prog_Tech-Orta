#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double testGrade(int, int, int);
char grade(int);

int main() {
  int testCases, term1, term2, final, att, test1, test2, test3;
  double avg;

  cin >> testCases;

  for(int i = 0; i < testCases; i++) {
    cin >> term1 >> term2 >> final >> att >> test1 >> test2 >> test3;

    avg = testGrade(test1, test2, test3);

    printf("Case %d: %c\n", i+1, grade(term1+term2+final+att+avg));
  }
}

char grade(int num) {
  if(num >= 90) 
    return 'A';
  else if(num >= 80)
    return 'B';
  else if(num >= 70)
    return 'C';
  else if(num >= 60)
    return 'D';
  else 
    return 'F';
}

double testGrade(int t1, int t2, int t3) {
  vector<int> nums = {t1, t2, t3};

  // first number
  auto it = max_element(nums.begin(), nums.end());
  int num1 = *it;
  nums.erase(it);

  // first number
  it = max_element(nums.begin(), nums.end());
  int num2 = *it;

  return (num1 + num2) / 2;
}
