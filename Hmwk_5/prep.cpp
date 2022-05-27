#include <iostream>
using namespace std;

int myFunc(int n){
  int result = 0;
  if(n<=0){
    return 1;

  }
  result  = n*myFunc(n-2);
  return result;
}
int main(){
  cout <<myFunc(7);
  return 0;
}
