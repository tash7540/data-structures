


// main and any other functions from main.cpp go here
/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();
int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string choice;
    string countryName1;
    string previous;

    while (choice != "5") {
        bool flag =true;

        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);
        string message1;
        string countryName0;
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
          cout<< CountryNet.searchNetwork("asd")<<endl;

          cout <<"Enter name of the country to receive the message:" << endl;
          getline(cin,countryName0);
          cout <<"Enter the message to send:" << endl;
          getline(cin,message1);
          cout << endl;
          CountryNet.transmitMsg(countryName0,message1);
          break;

        case 4:

          cout << "Enter a new country name:" << endl;
          getline(cin,countryName1);

          cout << "Enter the previous country name (or First):" << endl;
          while(flag){
            getline(cin,previous);
            if(previous == "First"){

              CountryNet.insertCountry( NULL ,countryName1);
              CountryNet.printPath();
              flag = false;

            }
            else if(CountryNet.searchNetwork(previous) == nullptr){
              cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
              flag = true;

            }
            else if(CountryNet.searchNetwork(previous) != nullptr){//
              CountryNet.insertCountry(CountryNet.searchNetwork(previous),countryName1);
              CountryNet.printPath();
              flag = false;

            }



          }


          break;
          case 5:
          cout << "Quitting..." << endl;
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
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
