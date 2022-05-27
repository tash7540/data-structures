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
TreeNode* addMovieHelper(TreeNode* currNode, string title,int ranking,int year,float rating){
    char char1 = title[0];
    if(currNode == NULL){
        TreeNode* node = new TreeNode;
        node->titleChar = char1;
        currNode = node;
        return currNode;
    }
    else if(currNode->titleChar < char1){
        currNode->rightChild = addMovieHelper(currNode->rightChild,title,ranking,year,rating);
    }
    else if(currNode->titleChar > char1){
        currNode->leftChild = addMovieHelper(currNode->leftChild,title,ranking,year,rating);
    }
    return currNode;

}
TreeNode* helperFindChar(TreeNode* node, char char1 ){
if(node ==NULL){
    return NULL;
}
  if(node-> titleChar == char1){
    return node;
  }
  else if(char1 < node->titleChar){
     return helperFindChar(node->leftChild, char1);
  }
  else if(char1 > node->titleChar){
    return helperFindChar(node->rightChild, char1);
  }

    return node;
}


// definition if you like

void MovieTree::addMovie(int ranking, std::string title, int year, float rating)
{
    if(helperFindChar(root, title[0]) == NULL){
      root = addMovieHelper(root,title,ranking,year,rating);

    }

      TreeNode* x;
      x = helperFindChar(root,title[0]);
      LLMovieNode* y;
      y = x->head;
      LLMovieNode* temp;
      bool flag = 0;
      if(y == NULL){
        LLMovieNode* newNode = new LLMovieNode(ranking,title,year,rating);
        x->head = newNode;
        return;

      }

      while(y != NULL ){
        if(title < y->title && flag == 0){
        LLMovieNode * newNode = new LLMovieNode(ranking,title,year,rating);
        newNode->next = y
        //temp ->next = newNode;
        x->head = newNode;
        return;
        }
        if(title < y->title && flag == 1){
          LLMovieNode * newNode = new LLMovieNode(ranking,title,year,rating);
          newNode ->next =y;
          temp->next = newNode;
          return;

        }
        flag = 1;

        temp = y;
        y = y->next;
      }
    if(y == NULL){
        LLMovieNode* newNode = new LLMovieNode(ranking,title,year,rating);
        temp ->next = newNode;
        return;
    }

}




void helperPrintMovie(TreeNode* node){


        if (node == NULL){
             return;
        }
         /* first print data of node */

         /* then recur on left sutree */
         helperPrintMovie(node->leftChild);
         cout << "Movies starting with letter: " << node->titleChar << endl;
         // for every LLMovieNode (m) attached to t
         LLMovieNode* temp = node->head;

         while(temp !=NULL){
           cout << " >> " << temp->title << " " << temp->rating << endl;
           temp = temp->next;



         }



         /* now recur on right subtree */
         helperPrintMovie(node->rightChild);
}

void MovieTree::printMovieInventory() {
   //write your code
   if(root == NULL){
    return;
   }
    helperPrintMovie(root);

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
