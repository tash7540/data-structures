/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string choice;
    string newCountry;
    string previous;
    string number;
    int number1;

    while (choice != "8") {
        bool flag =true;

        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);
        string message1;
    switch(menuChoice){

        case 1:
          CountryNet.loadDefaultSetup();
          CountryNet.printPath();
          break;
        case 2:
            //displayMenu();
          CountryNet.printPath();
          break;

        case 3:
            cout<<"Enter a new country name:" << endl;
            getline(cin,newCountry);
            cout <<"Enter the previous country name (or First):" << endl;
            while(flag){
              getline(cin,previous);
              if(previous == "First"){

                CountryNet.insertCountry( NULL ,newCountry);
                CountryNet.printPath();
                flag = false;

              }
              else if(CountryNet.searchNetwork(previous) == nullptr){
                cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                flag = true;

              }
              else if(CountryNet.searchNetwork(previous) != nullptr){//
                CountryNet.insertCountry(CountryNet.searchNetwork(previous),newCountry);
                CountryNet.printPath();
                flag = false;

              }
            }

            break;

        case 4:

          cout << "Enter a country name:" << endl;
          getline(cin,newCountry);
          CountryNet.deleteCountry(newCountry);
          CountryNet.printPath();


          break;
          case 5:
            CountryNet.reverseEntireNetwork();
            CountryNet.printPath();
            break;

          case 6:
        cout <<"Enter the count of values to be rotated:"<< endl;
          getline(cin,number);
          number1 = stoi(number);
          CountryNet.rotateNetwork(number1);
          CountryNet.printPath();
          break;

          case 7:
            cout <<"Network before deletion"<< endl;
            CountryNet.printPath();
          CountryNet.deleteEntireNetwork();
          cout <<"Network after deletion" << endl;
          CountryNet.printPath();
          break;

          case 8:
            cout << "Quitting... cleaning up path: " << endl;
            CountryNet.printPath();
            CountryNet.deleteEntireNetwork();
            if( CountryNet.isEmpty()){
              cout << "Path cleaned" << endl;

            }
            else{
                cout << "Error: Path NOT cleaned" << endl;
          }



          cout << "Goodbye!" << endl;

        }
}
    return 0;
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
