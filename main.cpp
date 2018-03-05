/*this is a max heap program
 *Trevor Horine
 *2/28/18
 */
#include <iostream>
#include <cstring>
#include "node.h"
#include <math.h>

using namespace std;

int parent (int);
int left(int);
int right(int);
void heapify(int[], int, int);
void mktree(node*, int[], int, int);
void print(node*, int, int);

int main(){
  int input[100] = {0};
  char in[400];
  int current = 0;
  node* root = new node();
  node* start = new node();
  cout << "Enter up to 100 numbers that range between 1 and 1000 with a space between each one" << endl;
  cin.getline(in, 400);
  int i = 0;
  char *s = strtok(in, " ");
  while (s) {
    if (i < 400) {
      input[i++] = atoi(s);
    }
    s = strtok(NULL, " ");
  }
  int y = i;
  heapify(input, i, y);
  //for(int i = 0; i < y; i++){
  //cout << input[i] << endl;
  //}
  int tree[y] = {0};
  for(int i = 0; i < y; i++){
    tree[i] = input[i];
    //cout << tree[i];
  }
  cout << endl;
  root -> setvalue(NULL);
  int r = y;
  mktree(root, tree, 0, r);
  start = root;
  while (start-> getright() != NULL){
    start = start -> getright();
  }
  int d = log2(y+1);
  print(root, 0, y);
}

int parent(int i){
  return ((i-1)/2);
}

int left(int i){
  return((2*i)+1);
}

int right(int i){
  return((2*i)+2);
}

void heapify(int input[],int i, int h){
  for(int i = 0; i < h; i++){
    int par = input[i];
    int lc = input[left(i)];
    int rc = input[right(i)];
    if(left(i) < h && par < lc){
      swap(input[i], input[left(i)]);
      i = -1;
    }
    else if(right(i) < h && par < rc){
      swap(input[i], input[right(i)]);
      i = -1;
    }
  }
}
void print(node* current, int d, int y){
  if(current -> getleft() != NULL){
    print(current-> getleft(), d+1, y);
  }
  int t = d;
  for(t; t>0; t--){
    cout << "\t";
  }
  cout << current -> getvalue() << endl;
  if(current -> getright() != NULL){
    print(current -> getright(), d+1, y);
  }
}
void mktree(node* current, int tree[], int y, int r){
  if(tree[y] != 0 && y < r){
      if (current -> getvalue() == 0){
	current -> setvalue(tree[y]);
    }
      if(tree[right(y)] != 0 && right(y) < r){
	node* t = new node();
	t -> setvalue(tree[right(y)]);
	t -> setprev(current);
	current -> setright(t);
	mktree(current-> getright(), tree, right(y), r);
    }
      if(tree[left(y)] != 0 && left(y) < r){
	node* t = new node();
	t -> setvalue(tree[left(y)]);
	t -> setprev(current);
	current -> setleft(t);
	mktree(current -> getleft(), tree, left(y), r);
      }
  }
}