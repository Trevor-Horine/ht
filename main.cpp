/*this is a hash table that implements chaining to deal with multiple ocurances.
 *Trevor Horine
 *05/31/2018
 */

#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>

using namespace std;
//this is the node struct
struct node{
  node* next = NULL;
  node* last = NULL;
  char* namef = NULL;
  char* namel = NULL;
  int id = NULL;
  float gpa = NULL;
};

void hashtable(node** &hash, int &size, node* temp);
// this it the print function
void print(node** hash, int size){
  for(int p = 0; p < size; p++){
    cout << p << endl;
    if(hash[p] != NULL){
      cout << " " << hash[p] -> namef << " " << hash[p] -> namel << " Id: " << hash[p] -> id << " GPA: " << hash[p] -> gpa << endl;
      if(hash[p] -> next != NULL){
	node* t = hash[p];
	while(t -> next != NULL){
	  t = t -> next;
	  cout << " " << t -> namef << " " << t -> namel << " Id: " <<  t -> id << " GPA: " << t -> gpa << endl;
	}
      }
    }
  }
}
//this gentrates a ramdome number
int randnum(int n){
  int r = NULL;
  r = rand() % n;
  return r;
}
// this resizes and re hashes the table
void resize(node** &hash, int &size){
  cout << "resize" << endl;
  node** hold;
  size = size*2;
  int h = 0;
  hold = new node*[size];
  for(int n = 0; n < size; n++){
    hold[n] = NULL;
  }
  for(int p = 0; p < (size/2); p++){
    if(hash[p] != NULL){
      if(hash[p] -> next != NULL){
	hash[p] -> next = NULL;
      }
      hashtable(hold, size, hash[p]);
      h++;
      /* if(hash[p] -> next != NULL){
	 node* t = hash[p];
	 while(t -> next != NULL){
	 t = t -> next;
	 hold[h] = t;
	 }  
	 }*/
    }
  }
  /* for(int i = 0; i < size; i++){
    if(hash[i] != NULL){
      for(int j = 0; j < size/2; j++){
	if(hold == NULL){
	  hold[j] = hash[i];
	}
      }
    }
    if(hash[i] != NULL){
      if(hash[i] -> next != NULL){
	for(int j = 0; j < size/2; j++){
	  if(hold == NULL){
	    hold[j] = hash[i];
	  }
	}
      }
    }
    }*/
  hash = hold;
  //}
}
//this hashes students
void hashtable(node** &hash, int &size, node* temp){
  int count = 0;
  //  cout <<"you have reached hash table" << endl;
  // cout << temp -> namef << temp -> namel << " ID: " << temp -> id << " GPA: " << temp -> gpa << endl;
  int h = randnum(size);
  cout << h << endl;
  if(hash[h] == NULL){
    hash[h] = temp;
  }
  else if(hash[h] != NULL){
    node* t = hash[h];
    //    cout << t -> namel;
    int check = 0;
    if(t != NULL){
      while(t != NULL){
	check++;
	if(t -> next != NULL){
	  t = t -> next;
	  count++;
	  cout << "chaining" << count << endl;
	}
	else{
	  t -> next = temp;
	  //temp -> last = t;
	  break;
	}
	if(check >= 3){
	  resize(hash, size);
	}
      }
    }
    /* cout << "h" <<  h << endl << hash[h] << endl;
       node* working = hash[h];
       while(hash[h] != NULL){
       if(working != NULL){
       cout << working << endl;
       if(working -> next != NULL){
       cout << working -> next -> namef << endl;
       working = working -> next;
       count++;
       cout << count << endl;
       cout << "chaining" << endl;
       }
       else{
       working -> next = temp;
       temp -> prev = working;
       break;
       }
       }
       }*/
  }
  /*  if(count >= 3){
    resize(hash, size);
    cout << size << endl;
  }*/
}
//this adds manualy entered students
void add (node** &hash, int &size){
  node* temp = new node();
  char* first = new char[100];
  char* last = new char[100];
  int id;
  float gpa;
  cout << "What is the students first name?" << endl;
  cin >> first;
  temp -> namef = first;
  cout << "What is the students last name?" << endl;
  cin >> last;
  temp -> namel = last;
  cout << "what is the students id number?" << endl;
  cin >> id;
  temp -> id = id;
  cout << "What is the students gpa?" << endl;
  cin >> gpa;
  temp -> gpa = gpa;
  hashtable(hash, size, temp);
}
//this is the randome student gentrator
void make(node** &hash, int &size, int &masterid){
  node* temp = new node();
  char* in = new char[20];
  float g;
  ifstream file;
  file.open("first.txt");
  int t = randnum(10);
  in = new char[20];
  file.getline(in, 20);
  for(int i = 0; i < randnum(10); i++){
    in = new char[20];
    file.getline(in, 20);
  }
  file.close();
  temp -> namef = in;
  ifstream last;
  last.open("last.txt");
  t = randnum(10);
  in = new char[20];
  last.getline(in,20);
  for(int i = 0; i < t; i++){
    in = new char[20];
    last.getline(in, 20);
  }
  last.close();
  temp -> namel = in;
  temp -> id = masterid;
  masterid++;
  g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/4);
  temp -> gpa = trunc(100 * g) / 100;
  hashtable(hash, size, temp);
}
//this is main
int main(){
  srand (time(NULL));
  char* in = new char[20];
  int size = 100;
  int nodes = 0;
  node** hash;
  hash = new node*[size];
  for(int n = 0; n < size; n++){
    hash[n] = NULL;
  }
  int masterid = 0;
  bool run = true;
  while(run  == true){
    cout << "Do you want to add, make, print, delete, or quit?" << endl;
    cin >> in;
    for(int i = 0; i < 20; i++){
      in[i] = toupper(in[i]);
    }
    if(strcmp(in, "ADD") == 0){
      add(hash, size);
      nodes++;
      if(nodes >= size/2){
	resize(hash, size);
      }
    }
    else if(strcmp(in, "MAKE") == 0){
      cout << "How many students would you like to make?" << endl;
      int n;
      cin >> n;
      for(int i = 0; i < n; i++){
	make(hash, size,  masterid);
	nodes++;
      }
      if(nodes >= size/2){
	resize(hash, size);
      }
    }
    else if(strcmp(in, "PRINT") == 0){
      print(hash, size);
    }
    else if(strcmp(in, "DELETE") == 0){
      // remove();
    }
    else if(strcmp(in, "QUIT") == 0){
      run = false;
    }    
  }
}
