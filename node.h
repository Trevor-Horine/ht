/*This is the header for the node class
 *Trevor Horine
 *12/11/2017
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class node{
 public:
  //methods
  node();
  ~node();
  void setvalue(int);
  int getvalue();
  void setleft(node*);
  node* getleft();
  void setright(node*);
  node* getright();
  void setprev(node*);
  node* getprev();
 private:
  //varables
  int dataptr;
  node* left;
  node* right;
  node* prev;
};
#endif
