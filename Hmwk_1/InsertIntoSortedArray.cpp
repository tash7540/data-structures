#include <iostream>
#include <fstream>
using namespace std;


void bubblesort(int values[], int size) {

    int tmp;   // temporary holding variable for swapping

    // loop over the number of passes through the list to sort
    // i represents how far from the end of the list we can stop comparing on each pass
    for (int i = 1; i < size; i++) {

        // start comparing at front of the list (j=0)
        // the last i elements have already bubbled down to where they belong
        for (int j = 0; j < size - i; j++) {

            if (values[j] > values[j+1]) {
                // swap elements values[j] and values[j+1]
                tmp = values[j+1];
                values[j+1] = values[j];
                values[j] = tmp;
            }
        }
    }
}


void show(int array[], int size ){

  for( int i= 0; i < size; i++){
    if(i == (size -1)){
      cout<< array[i];
    }
    else{
      cout << array[i] << ",";
    }
  }
  cout << endl;
}


int insertIntoSortedArray(int myArray[], int numEntries , int newValue) {
  myArray[numEntries] = newValue;
  numEntries++;
  bubblesort(myArray,numEntries);
return numEntries;

}


int main(int argv, char* argc[]){
  string number;
  int newValue;
  int maxSize = 99;
  int numEntries = 0;
  int array[maxSize];
  ifstream fp;
  string filename = (argc[1]);
  fp.open(filename);
  if ( fp.is_open()){
    while(getline(fp, number) && numEntries < 100){
      newValue = stoi(number);
      int new_entry = insertIntoSortedArray(array ,numEntries, newValue);
      show(array, new_entry);
      numEntries = new_entry;
    }
    fp.close();

  }
  else{
    cout << "Failed to open the file." << endl;
  }
}
