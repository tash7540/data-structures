/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

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
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty(){
  if (head == NULL){
    return true;
  }
  else{
    return false;
  }
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
       else if(previous == NULL){
       cout << "adding: " << countryName << " (HEAD)" << endl;


           Country* newCountry = new Country;
           newCountry->name = countryName;
           newCountry->next = head;
           head = newCountry;
           //printPath();
       }

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
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */

 void CountryNetwork::deleteCountry(string countryName) {
   Country* del = NULL;
   Country* temp = head;
   if(temp -> name == countryName){
     head = temp->next;
     delete temp;
     return;
   }
   while( temp != NULL){
     if(temp-> next == NULL){
       cout <<"Country does not exist." << endl;
       return;

     }
     if (temp ->next -> name == countryName){
       //temp = temp -> next -> next;
       del = temp -> next;
       temp ->next = del ->next;
       delete del;
       return;
     }
     temp = temp ->next;

   }
 }

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() {
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
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName) {
  Country* ptr = head;
  while (ptr != nullptr && ptr->name != countryName){
              ptr = ptr->next;
  }
    return ptr;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
 void CountryNetwork::deleteEntireNetwork(){
   while (head != NULL){
     Country* del;

     del = head;
     head= head ->next;
     cout <<"deleting: " << del-> name << endl;
     delete del;

     if(head == NULL){


         cout << "Deleted network" << endl;
         return;
     }
     }
 }

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
 void CountryNetwork :: rotateNetwork(int n){
   Country* temp = head;
   Country* temp1 = NULL;
   int counter =0;
   bool flag = true;
   if(head == NULL){
     cout <<"Linked List is Empty" << endl;
     return;
   }
   while(temp !=NULL){
     if(counter == n - 1 && flag == true){
       temp1= temp;
       flag = false;
       //head = temp->next;
       //temp->next = NULL;

     }
     if(temp->next == NULL && flag){
       cout <<"Rotate not possible" << endl;
       return;
     }
     if (temp ->next == NULL && !flag){ //search for last node
       temp -> next = head;
       head = temp1 ->next;
       temp1 -> next = NULL;
        cout <<"Rotate Complete"<< endl;
       return;
     }
     if(counter !=n){
     counter++;
   }
     temp = temp->next;

   }

}


/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */


void CountryNetwork::reverseEntireNetwork() {
    Country* prev = NULL;
    Country* next = NULL;
    Country* curr = head;
    while(curr !=NULL){
      next = curr ->next;
      curr ->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;

}
/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {

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
