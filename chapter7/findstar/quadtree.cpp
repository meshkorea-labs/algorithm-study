#include <bits/stdc++.h>
#include <string> 
#define DEBUG 0
using namespace std;



const int MAX_STRING_LENGTH = 1000;

void debugPrint(string message) {

#if DEBUG
cout << message << endl;
#endif

}

 
bool checkQuadTreeChar(char c){

  if(c == 'x')
    return true;
  else if(c == 'b')
    return true;
  else if(c == 'w')
    return true;

  return false;
}

string quadTree(string inputString, int *index){

  string A;
  string B;
  string C;
  string D;

  string currentChar;
  int partCount = 0;

  debugPrint("current string index : " + *index );

  while(checkQuadTreeChar(inputString[*index]))
  {
    currentChar = inputString[*index];

    debugPrint("current index string is [before]:[" + currentChar + "]");

    if(inputString[*index] == 'x'){
      debugPrint("current char is compare x true !!! ");
      (*index)++;

      currentChar = quadTree(inputString, index);
      currentChar = "x" + currentChar;
    }

    debugPrint("current index string is [after]: " + currentChar + "");

    if(partCount ==0){
      A.append(currentChar);
    }else if(partCount == 1){
      B.append(currentChar);
    }else if(partCount == 2){
      C.append(currentChar);
    }else if(partCount == 3){
      D.append(currentChar);
    }
    
    partCount++;
    if(partCount == 4){
      break;
    }

    (*index)++;
  }

  C.append(D).append(A).append(B);
  
  debugPrint(" return string is : [" + C + "]");

  return C;

}


int main () {
  
  string inputString;
  string resultString;

  cin >> inputString;
  int stringIndex = 0;
  resultString = quadTree( inputString, &stringIndex);
  
  cout << "input string is : " << inputString << endl;
  cout << "result string is : " << resultString << endl;
  debugPrint("end string index is : " + stringIndex);

  return 0;
}
