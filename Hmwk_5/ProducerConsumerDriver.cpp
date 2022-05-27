/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer x;
	string choice;
	string pro;
	string item;
	string con;
	int num;
	int number;


while (choice != "3"){
    	menu();

	getline(cin,choice);
	int menuChoice = stoi(choice);
    switch(menuChoice){
	case 1:
	    cout << "Enter the number of items to be produced:" << endl;
	    getline(cin,pro);
	    number = stoi(pro);
	    for(int i = 0; i< number;i++){
		    cout << "Item" << i+1 << ":" << endl;
		    getline(cin,item);
		    x.enqueue(item);

	    }
	    break;
	case 2:
	    cout << "Enter the number of items to be consumed:" << endl;
	    getline(cin,con);
	    num = stoi(con);
	    if(num > x.queueSize() ){
	        int aha = (x.queueSize());
		    for(int j =0; j < aha; j++){
			    cout << "Consumed: " << x.peek() << endl;

			    x.dequeue();
		    }
		    cout<< "No more items to consume from queue" << endl;

	    }
	    else{
		    for(int j =0; j < (num ); j++){
			    cout << "Consumed: " << x.peek() << endl;

			    x.dequeue();
		    }

    	}
	    break;
	 case 3:
	     cout << "Number of items in the queue:"<< x.queueSize() <<endl;
	    break;

}
}


}
