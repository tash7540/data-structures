#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Park {
string parkname;
string state;
int area;
};


// length: Number of items in the array
void printList(const Park parks[], int length){
for(int i = 0; i < length; i++){
cout << parks[i].parkname <<" [" << parks[i].state << "] area: "<< parks[i].area << endl;
}
}


// length: Number of items currently stored in the array
void addPark(Park parks[], string parkname, string state, int area, int length){

Park example;
example.parkname = parkname;
example.state = state;
example.area = area;
parks[length] = example;

}



int main(int argv, char* argc[]){

ifstream fp;
int size = 99; // size of array
Park array[size];
int length = 0; // current array length
string filename = (argc[1]);
fp.open(filename);
ofstream x;
string output_file = (argc[2]);

x.open(output_file);
if ( fp.is_open()){
string word;
while(getline( fp , word) && length < 99){
string parkname , state;
int area = 0;
string number;
stringstream ss(word);
getline(ss,parkname,',');
getline(ss,state,',');
getline (ss,number);
area = stoi(number);
addPark(array, parkname, state, area, length);
length++;
int minimum_area;
minimum_area = stoi((argc[3]));
if(area >= minimum_area && length < 99){

if( x.is_open()){
string output = parkname + "," + state +"," + number;
x << output << endl;
}

}
}
x.close();

printList(array, length);

fp.close();

}
else{
cout << "Failed to open the file." << endl;
}
}
