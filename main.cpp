/*this is a max heap program
 *Trevor Horine
 *2/28/18
 */
#include <iostream>
#include <cstring>

using namespace std;

int parent (int);
int left(int);
int right(int);
void heapify(int[], int, int);
void print(int[], int, int);

int main(){
  int input[100] = {0};
  char in[400];
  int current = 0;
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
  //int h = sizeof(input);
  heapify(input, i, y);
  for(int i = 0; i < y; i++){
    cout << input[i] << endl;
  }
  int tree[y] = {0};
  for(int i = 0; i < y; i++){
    tree[i] = input[i];
    cout << tree[i];
  }
  cout << endl;
  print(tree, y, 0);
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
void print(int tree[], int i, int depth){
  /*for(int i = 0; i < depth; i++){
    cout << "\t";
  }
  cout << tree[i-1] << endl;
  int next = i * 2;
  if(tree[next-1] !=0){
    print(tree, next, depth+1);
  }
  if(tree[next] != 0){
    print(tree, next+1, depth+1);
  }*/
  for (i;tree[i]!=tree[0];i--){

  }
}
