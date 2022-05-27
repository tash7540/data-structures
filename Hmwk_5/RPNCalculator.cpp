#include "RPNCalculator.hpp"
using namespace std;


RPNCalculator::RPNCalculator(){
  stackHead = NULL;
}
RPNCalculator::~RPNCalculator(){
  while(stackHead != NULL){
    pop();
  }

}
bool RPNCalculator::isEmpty(){
  if(stackHead ==NULL){
    return true;
  }
  else{
    return false;
  }

}
void RPNCalculator::push(float num){
  Operand* temp = new Operand;
  temp ->number = num;
  temp->next = stackHead;
  stackHead = temp;



}
void RPNCalculator::pop(){
  if(isEmpty() == true){
    cout<<"Stack empty, cannot pop an item."<< endl;
    return;
  }
  else{
    Operand* temp = stackHead;
    stackHead = temp ->next;
    delete temp;
  }

}
Operand* RPNCalculator::peek(){
  if(isEmpty() == true){
    cout<<"Stack empty, cannot peek."<< endl;
    return NULL;
  }
  else{
    Operand* temp = stackHead;
    return temp;
  }

}

bool RPNCalculator::compute(std::string symbol){
  if(symbol != "+" && symbol != "*"){
    cout <<"err: invalid operation" << endl;
    return false;
  }
  else{
    float num1;
    float num2;
    float total;
    if (isEmpty() == true){
        cout <<"err: not enough operands" << endl;
        return false;

    }
    else{

        Operand* temp = stackHead;
        num1 = temp -> number;
        pop();
        if (isEmpty() == true){
        cout <<"err: not enough operands" << endl;
        push(num1);
        return false;
        }
        else{
            temp = stackHead;
            num2 = temp ->number;
            pop();
        }

  if(symbol =="+"){
    total = num1 + num2;

    push(total);
  }
  else if( symbol =="*"){
    total = num1 * num2;
    push(total);

  }




}
}
}
