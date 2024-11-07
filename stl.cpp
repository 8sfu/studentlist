#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct student {
  char firstName[20];
  char lastName[20];
  long idNum;
  float gPA;
};


void add(vector<student*>* list){

  struct student* sptr = new student();

  cout << "enter a name " << endl;
  cin >> sptr->firstName;
  cout << "enter a lastname " << endl;
  cin >> sptr->lastName;
  cout << "enter an id num " << endl;
  cin >> sptr->idNum;
  cout << "enter a GPA " << endl;
  cin >> sptr->gPA;
  //double gPAMath;
  //cin >> gPAMath;
  //sptr->gPA = round(100*gPAMath)/100;

  list->push_back(sptr);
  
  return;
}

void prt(vector<student*>* list){
  //int n = 0;
  for(student* student : *list) { //this for each loop works fine
    //n++;
    cout << student->firstName << " ";
    cout << student->lastName << ", ";
    cout << student->idNum << ", ";
    cout << fixed;
    cout << setprecision(2) << student->gPA << endl;
  }
  cout << endl;
  return;
}


void del(vector<student*>* list){
  long tbdel;
  cout << "Who would you like to delete?" << endl;
  cin >> tbdel;
  vector<student*>::iterator it;
  for(it = list->begin(); it != list->end(); ++it) {
    // cout << (*it)->firstName << endl;
    if((*it)->idNum == tbdel){
      list->erase(it);
      --it;
    }
  }
  cout << endl;
  return;  
}

int main() {
  //cout << "received " << endl;
  vector<student*>* stlvector = new vector<student*>;
  
  char input[7];
  bool running = true;
  cout << "Enter 'ADD','PRINT', or 'DELETE' to add, print, or delete to or from the studentlist and enter 'QUIT' to exit the program when finished." << endl;
  
  while(running){
    cin.getline(input,80);
    if(!strcmp(input,"QUIT")){
      running = false;
    } else if (!strcmp(input,"ADD")){
      add(stlvector);
    } else if (!strcmp(input,"PRINT")){
      prt(stlvector);
    } else if (!strcmp(input,"DELETE")){
      del(stlvector);
    } else {
      cout << endl;
    }
  }
 
  
  return 0;
}
