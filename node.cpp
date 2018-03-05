/* this is a node class
*Trevor Horine
 *3/2/2018
 */
#include "node.h"
node::node(){
  right = NULL;
  left = NULL;
  prev = NULL;
  dataptr = 0;
}
//destructor
node::~node(){
  left = NULL;
  right = NULL;
  prev = NULL;
}
//method to set value
void node::setvalue(int newdata){
  dataptr = newdata;
}
//method to get value
int node::getvalue(){
  return dataptr;
}
//mehtod to set left
void node::setleft(node* newnext){
  left = newnext;
}
//mehtod to get left
node* node::getleft(){
  return left;
}
//method to set right
void node::setright(node* newnext){
  right = newnext;
}
//method to get right
node* node::getright(){
  return right;
}
//mehtod to set previous
void node::setprev(node* newnext){
  prev = newnext;
}
//method to get previous
node* node::getprev(){
  return prev;
}
