#include "CountryNetwork.hpp"
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork(){
  head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName){

     //Check if head is Null i.e list is empty
     if(head == NULL){
 cout << "adding: " << countryName << " (HEAD)" << endl;

       head = new Country;
       head->name = countryName;
       head->next = NULL;
     }

     // if list is not empty, look for prev and append our node there
//     else if(previous == NULL){
  //   cout << "adding: " << countryName << " (HEAD)" << endl;


    //     Country* newCountry = new Country;
    //     newCountry->name = countryName;
    //     newCountry->next = head;
    //     head = newCountry;
         //printPath();
     //}

     else{
         cout << "adding: " << countryName << " (prev: " << previous->name <<")" << endl;

         Country* newCountry = new Country;
         newCountry->name = countryName;
         newCountry->next = previous->next;
         previous->next = newCountry;
         //printPath();

       }


 }

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup(){
    insertCountry(NULL,"United States");
    insertCountry(searchNetwork("United States"), "Canada");
	insertCountry(searchNetwork("Canada"),"Brazil");
	insertCountry(searchNetwork("Brazil"),"India");
	insertCountry(searchNetwork("India"),"China");
	insertCountry(searchNetwork("China"),"Australia");


}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName){

    Country* ptr = head;
  //  while (ptr != nullptr && ptr->name != countryName){
//                ptr = ptr->next;
  //  }
    //  return ptr;
    Country* ptr2 = head;
    while(ptr2 !=nullptr){
      //handle edge case
      if(ptr2->next == nullptr){
        Country* newC= new Country;
        newC->name=countryName;
        newC ->next

        cout<<ptr->name<<endl;
        return(ptr);
      }
      ptr = ptr->next; // 1 step
      ptr2=ptr2->next->next; //2 step
    }
    cout<<ptr->name<<endl;

    return(ptr);
  }


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
 void CountryNetwork::transmitMsg(string receiver, string message){
   Country * temp = head;
   if(head == NULL){
     cout << "Empty list" << endl;
     return;
   }
   if(searchNetwork(receiver) ==NULL){
     cout <<"Country not found" << endl;
   }
   else{
      while (temp !=NULL){
        temp->message = message;
        temp->numberMessages++;
        cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;

        if( temp->name == receiver){
          break;
        }
        temp = temp->next;
      }

    }
  }

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath(){

  Country* temp = head;
  if(head == NULL){
    cout <<"== CURRENT PATH ==" << endl;
    cout <<"nothing in path" << endl;
    cout << "===" << endl;

    return;
  }
cout <<"== CURRENT PATH ==" << endl;
  while(temp->next != NULL){
    cout<< temp->name <<" -> ";
    temp = temp->next;
  }

  cout<<temp-> name;
    if (temp->next == NULL){
      cout << " -> "<< "NULL" << endl;
  }
cout <<"===" << endl;
}
