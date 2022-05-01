#include <iostream>
#include <vector>
#include "record.h"
using namespace std;

void record::addatbeg(string i, string f, string l, string d, string g) {
  // create
  info *cur = head;
  info *temp = new info;
  // fill
  temp->id = i;
  temp->first = f;
  temp->last = l;
  temp->dob = d;
  temp->gpa = g;
  temp->next = nullptr;
  
  while(cur != nullptr) {
    if(cur->id == i) {
      cur->id = i;
      cur->first = f;
      cur->last = l;
      cur->dob = d;
      cur->gpa = g;
      return;
    }
    cur = cur->next;
  }
  cur = head;
  // link it in the list
  if(cur == nullptr) 
    head = temp;
  else {
    while(cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = temp;
  }
  
}
void record::deleteatbeg(string s) {
    bool flag = false;
    info *cur = head;
    info *prev = nullptr;
      while(cur != nullptr) {
        if(cur->id == s) {
          flag = true;
          break;
        }
        prev = cur;
        cur = cur->next;
      }
      if(flag) {
        info *temp = cur;
        prev->next = cur->next;
        delete temp;
      }  
}
void record::print(ostream &out) {

  info *cu = head;
  while(cu != nullptr) {
    out << "{id:" << cu->id << ",first:" << cu->first << ",last:" 
    << cu->last << ",DOB:" << cu->dob << "," << cu->gpa << "}" << endl;
    cu = cu->next;
  }
}
void record::bubbleSort(vector<string> s) {

    info *cu1 = new info;
    info *cu2 = new info;
  
    int swapCount = 1;
    while(swapCount) {
      swapCount = 0;
      cu1 = head;
      cu2 = head->next;
      while(cu2 != nullptr) {
        if(s.empty()) {
            if(cu1->id > cu2->id) {
              swap(cu1, cu2);
              swapCount = 1;
            }
        }
        for(int i = 0; i < s.size(); i++) {
          if(s[i] == "id") {
            if(cu1->id > cu2->id) {
              swap(cu1, cu2);
              swapCount = 1;
            }
          }
          if(s[i] == "DOB") {
            if(cu1->dob > cu2->dob) {
              swap(cu1, cu2);
              swapCount = 1;
            }
            if(cu1->dob == cu2->dob) {
              if(cu1->id > cu2->id) {
                swap(cu1, cu2);
              }
            }
          }
          if(s[i] == "first") {
            if(cu1->first > cu2->first) {
              swap(cu1, cu2);
              swapCount = 1;
            }
            if(cu1->first == cu2->first) {
              if(cu1->id > cu2->id) {
                swap(cu1, cu2);
              }
            }
          }
          if(s[i] == "last") {
            if(cu1->last > cu2->last) {
              swap(cu1, cu2);
              swapCount = 1;
            }
            if(cu1->last == cu2->last) {
              if(cu1->id > cu2->id) {
                swap(cu1, cu2);
              }
            }
          }
          if(s[i] == "GPA") {
            if(cu1->gpa > cu2->gpa) {
              swap(cu1, cu2);
              swapCount = 1;
            }
            if(cu1->gpa == cu2->gpa) {
              if(cu1->id > cu2->id) {
                swap(cu1, cu2);
              }
            }
          }
        }
        cu1 = cu2;
        cu2 = cu2->next;
      }
    }
  
}
void record::swap(info* a, info*b) {

    info* temp = new info;
    temp->id = a->id;
    temp->first = a->first;
    temp->last = a->last;
    temp->dob = a->dob;
    temp->gpa = a->gpa;

    a->id = b->id;
    a->first = b->first;
    a->last = b->last;
    a->dob = b->dob;
    a->gpa = b->gpa;

    b->id = temp->id;
    b->first = temp->first;
    b->last = temp->last;
    b->dob = temp->dob;
    b->gpa = temp->gpa;
  
}
