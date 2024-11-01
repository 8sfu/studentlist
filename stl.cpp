#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct student {
  char firstName[20];
  char lastName[20];
  long idNum;
  float gPA;
};


student* add(vector<student*>* list){

  struct student* sptr = new student();

  cout << "enter a name " << endl;
  cin >> sptr->firstName;
  cout << "enter a lastname " << endl;
  cin >> sptr->lastName;
  cout << "enter an id num " << endl;
  cin >> sptr->idNum;
  cout << "enter a GPA " << endl;
  cin >> sptr->gPA;

  list->push_back(sptr);
  
  return sptr;
}

void prt(vector<student*>* list){
  //int n = 0;
  for(student* student : *list) { //this for each loop works fine
    //n++;
    cout << endl;
    cout << student->firstName << " ";
    cout << student->lastName << ", ";
    cout << student->idNum << ", ";
    cout << student->gPA << endl;
  }
  cout << endl;
  return;
}


void del(vector<student*>* list){
  char tbdel[20];
  cout << "Who would you like to delete?" << endl;
  cin >> tbdel;
  cout << "works 1" << endl;
  vector<student*>::iterator it;
  for(it = list->begin(); it != list->end(); ++it) {
    cout << "working 2" << endl; //throws seg fault after this cout
    cout << (*it)->firstName << endl;
  }

  /*for(student* student : *list) { //this for each loop breaks
    if(!strcmp(student->firstName,tbdel)){
      cout << student->firstName << endl;
    }
    }*/
    
  cout << endl;
  return;  
}

int main() {
  //cout << "received " << endl;
  vector<student*>* stlvector = new vector<student*>;
  
  char input[6];
  bool running = true;
  cout << "GENERIC INTRODUCTION TEXTLINE" << endl;
  
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
