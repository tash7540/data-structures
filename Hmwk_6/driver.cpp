#include "MovieTree.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
void menu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Quit" << endl;

}

int main(int argv, char* argc[]){
    MovieTree x;
  string line;
  ifstream fp;
  string title;
  int year;
  string year_s;
  int ranking;
  string ranking_s;
  float rating;
  string rating_s;
  string filename1;
  filename1= argc[1];

  fp.open(filename1.c_str());
  int counter = 0;
  if ( fp.is_open() && counter < 20){
    while(getline(fp, line)){
    stringstream ss(line);
    getline(ss,ranking_s,',');
    getline(ss,title,',');
    getline(ss,year_s,',');
    getline(ss,rating_s,',');
    ranking = stoi(ranking_s);
    year = stoi(year_s);
    rating = stof(rating_s);
    x.addMovieNode(ranking, title, year, rating);




    }
    fp.close();

  }
  else{
    cout << "Failed to open the file." << endl;
  }

  string input;
  string choice;
  string s_rating,s_year;
  int year1;
  float rating1;
    while (choice != "5") {
          menu();

        getline(cin, choice);


        // convert the `choice` to an integer
        int menuChoice = stoi(choice);
    switch(menuChoice){

        case 1:
        cout << "Enter title:" << endl;
        getline(cin,input);
        x.findMovie(input);
          break;
        case 2:
        cout << "Enter minimum rating:" << endl;
        getline(cin,s_rating);
        // get user input
        cout << "Enter minimum year:" << endl;
        getline(cin,s_year);
        year1 = stoi(s_year);
        rating1 = stof(s_rating);
        x.queryMovies(rating1, year1);


          break;

        case 3:
            x.printMovieInventory();

        break;

        case 4:
        x.averageRating();

        break;

        case 5:
            cout << "Goodbye!" << endl;
        break;



    }


    }



}
