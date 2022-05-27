/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator x;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;


  while(true)
  {
    cout << "#> ";
    string line;
    string symb;
    getline(cin,line);
    stringstream ss(line);
    getline(ss, symb, ',');

    if(isNumber(symb) == true ){
      float number;
      number = stof(symb);
      x.push(number);
    }
    else if(isNumber(symb) == false){
        if(symb =="+" || symb =="*"){
            x.compute(symb);
        }
        else if(symb == "="){
            if(x.isEmpty() == true){
                cout << "No operands: Nothing to evaluate" << endl;
                return false;
            }
            else{
                float final;
                Operand* temp1;
                temp1 = x.getStackHead();
                final = temp1 ->number;
                x.pop();
                if(x.isEmpty() == true){
                    cout << setprecision (4) << final;
                    return false;
                }
                else{
                    cout <<"Invalid expression" << endl;
                    return false;
                }
            }
        }

    }


  }

  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */

  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/

  return 0;
}
