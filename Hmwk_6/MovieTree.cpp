#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;
void destroyNode(MovieNode *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
  destroyNode(root);
}

// You may add helper functions between this comment and the addMovieNode
MovieNode* addMovieHelper(MovieNode* currNode, int ranking, string title,int year, float rating){

    if(currNode == NULL){
      MovieNode* node = new MovieNode(ranking,title,year,rating);

        return node;
    }
    else if(currNode->title < title){
        currNode->right = addMovieHelper(currNode->right,ranking,title,year,rating);
    }
    else if(currNode->title > title){
        currNode->left = addMovieHelper(currNode->left,ranking,title,year,rating);
    }
    return currNode;

}

// definition if you like

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating)
{
    // Your code here
      root = addMovieHelper(root,ranking,title,year,rating);

}

void helperPrintMovie(MovieNode* node){


        if (node == NULL){
             return;
        }
         /* first print data of node */

         /* then recur on left sutree */
         helperPrintMovie(node->left);
         cout << "Movie: " << node->title << " " << node->rating << endl;

         /* now recur on right subtree */
         helperPrintMovie(node->right);
}

void MovieTree::printMovieInventory() {
   //write your code
   if(root == NULL){
    cout << "Tree is Empty. Cannot print" << endl;
    return;
   }
    helperPrintMovie(root);

}

MovieNode* helperFindMovie(MovieNode* node, string title ){
if(node ==NULL){
    return NULL;
}
  if(node-> title == title){
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << node->ranking << endl;
    cout << "Title :" << node->title << endl;
    cout << "Year :" << node->year << endl;
    cout << "rating :" << node->rating << endl;
  }
  else if(title < node->title){
     return helperFindMovie(node->left, title);
  }
  else if(title > node->title){
    return helperFindMovie(node->right, title);
  }
    return node;
}
void MovieTree::findMovie(string title) {
MovieNode* x;
    x = helperFindMovie(root,title );
    if(x ==NULL){
        cout << "Movie not found." << endl;
    }

}

void helperPrintQuery(MovieNode* node , float rating, int year){


        if (node == NULL){
             return;
           }

        if((rating <= node->rating) && (year < node->year)){
          cout << node->title << "(" << node->year << ") " << node->rating << endl;

        }
        /* then recur on left sutree */
        helperPrintQuery(node->left, rating,year);

        /* now recur on right subtree */
        helperPrintQuery(node->right,rating,year);
}

void MovieTree::queryMovies(float rating, int year) {
  if (root == NULL){
    cout << "Tree is Empty. Cannot query Movies" << endl;

  }
  else{
  //write your code
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
// each movie that satisfies the constraints should be printed with
helperPrintQuery(root,rating,year);
}

}

void helpercalcMovie(MovieNode* node, float* x,int* y){

       if (node == NULL){
            return;


        }
        /* first print data of node */

        /* then recur on left sutree */
        helpercalcMovie(node->left,x,y);
        *x = *x + (node->rating);
        *y = *y + 1;

        /* now recur on right subtree */
        helpercalcMovie(node->right,x,y);
}


void MovieTree::averageRating() {
 //write your code
 if(root == NULL){
   cout << "Average rating:0.0" << endl;
   return;
 }
   float x =0;
   int y =0;
   helpercalcMovie(root,&x,&y);
   float average = x / y;
   cout << "Average rating:" << average << endl;

}
