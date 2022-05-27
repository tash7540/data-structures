#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;



struct wordItem {
string word;
int count;
};

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
  for(int i = N; i < N + 10; i++){
    float pro = uniqueWords[i].count/float(totalNumWords);
    cout << fixed << setprecision(4) << pro << " - " << uniqueWords[i].word << endl;
  }
}

void arraySort(wordItem uniqueWords[], int length){

  wordItem tmp;   // temporary holding variable for swapping

  // loop over the number of passes through the list to sort
  // i represents how far from the end of the list we can stop comparing on each pass
  for (int i = 1; i < length; i++) {

      // start comparing at front of the list (j=0)
      // the last i elements have already bubbled down to where they belong
      for (int j = 0; j < length - i; j++) {

          if (uniqueWords[j].count < uniqueWords[j+1].count) {
              // swap elements values[j] and values[j+1]
              tmp.word = uniqueWords[j+1].word;
              tmp.count = uniqueWords[j+1].count;

              uniqueWords[j+1].count = uniqueWords[j].count;
              uniqueWords[j+1].word = uniqueWords[j].word;

              uniqueWords[j].count = tmp.count;
              uniqueWords[j].word = tmp.word;

          }
      }
  }
}



int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
  int total= 0;
  for(int i = 0; i < length; i++){
    total = total + uniqueWords[i].count;
  }
  return total;

}


void resize( wordItem *&arrayPtr, int &capacity){
	// TODO increase the capacity by two times
	 int newCapacity = capacity * 2;

	// TODO dynamically allocate an array of size newCapacity
	 wordItem *newArray = new wordItem[newCapacity];

	//TODO copy all data from oldArray to newArray
  for( int i = 0; i < capacity; i++){
    newArray[i] = arrayPtr[i];
  }
	// TODO free the memory associated with oldArray
  delete [] arrayPtr;
	arrayPtr = newArray;
	capacity = newCapacity;

}
bool isStopWord(string temp, string igr[]){
  for ( int j = 0; j<50; j++){
    if(igr[j] == temp){
      return true;
    }
    else if((igr[j] == temp) && (j == 49)){
      return false;
    }
  }
}


void getStopWords(const char *filename, string array[]){
  string line;
  ifstream fp;
  string word;
  int size = 50;
  int index = 0;
  int index_ignore = 0;
  for( index = 0; index < 15; index++){
      word = word + filename[index];

  }
  fp.open(word);
  if ( fp.is_open()){
    while (getline(fp, line) && index_ignore < size){
      array[index_ignore] = line;
      index_ignore++;
    }
    fp.close();
  }
  else{
    cout << "Failed to open " << filename << endl;
  }
}


int main(int argc, char* argv[]){
  if(argc != 4){
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" <<endl;
    return 0;
	}
  int size_ignore = 50;
  string igr[size_ignore];
  string ignore_file = (argv[3]);
  char ar[ignore_file.length()];
  for (int a = 0; a <ignore_file.length(); a++){
    ar[a] = ignore_file[a];
  }
  getStopWords(&ar[0], igr);  // read ignore words file
  string read_file = argv[2];
	ifstream data;
	data.open(read_file.c_str());

	int capacity = 100;
	wordItem *arrayPtr;

	// TODO Dynamically allocate space here for the array
	arrayPtr = new wordItem[capacity];
	int numOfElement = 0;
	string temp, line;
  int double_array = 0;
	if(data.is_open()){
		while (getline(data, line)){
    stringstream ss(line);
    while(getline(ss, temp, ' ')){

      bool flag = isStopWord(temp, igr);
      if (flag){
        continue;
      }
      else if(!flag){
        int num = numOfElement;
        for(int t = num ; t >= 0; t--){
          if (arrayPtr[t].word == temp){        // if word already exist.
            arrayPtr[t].count++; //increment by 1
            break;
          }
          else if(t == 0){
            arrayPtr[numOfElement].word = temp;
            arrayPtr[numOfElement].count = 1; // first time just 1
            numOfElement++;
          }
      }

			if(numOfElement == capacity ){
				// Complete this function
				resize(arrayPtr, capacity);
        double_array++; // number of time array has been double
			}
		///	arrayPtr[numOfElement] = toBeInsert;
		}
	}
}
  cout << "Array doubled: " << double_array << endl;
  cout <<"#" << endl;
  cout << "Unique non-common words: " << numOfElement << endl;
  cout << arrayPtr[4].word << endl;

  cout <<"#" << endl;
  int totalnum = getTotalNumberNonStopWords ( arrayPtr, numOfElement);

  cout <<"Total non-common words: " << totalnum << endl;
  cout <<"#" << endl;
   arraySort(arrayPtr, numOfElement);
   int N = stoi(argv[1]);
   cout <<"Probability of next 10 words from rank " << N << endl;
   cout <<"---------------------------------------" << endl;
   printNext10(arrayPtr, N ,totalnum);


}
data.close();
}
