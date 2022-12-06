#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  
  string word, lang;
  int caseNum = 1;

  while (cin >> word) {
    if(word == "#")
      break;

    if(word == "HELLO") 
      lang = "ENGLISH";
    else if(word == "HOLA") 
      lang = "SPANISH";
    else if(word == "HALLO")
      lang = "GERMAN";
    else if(word == "BONJOUR")
      lang = "FRENCH";
    else if(word == "CIAO")
      lang = "ITALIAN";
    else if(word == "ZDRAVSTVUJTE")
      lang = "RUSSIAN";
    else
      lang = "UNKNOWN";

    printf("Case %d: %s\n", caseNum, lang.c_str());

    caseNum++;
  }
}
