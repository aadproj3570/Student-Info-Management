#include <iostream>
#include <vector>
using namespace std;

struct info {
  string id, first, last, dob, gpa;
  info *next;
};

class record {
private:
      info *list = new info;
      info *head;
      info *next;
public:
      record() { 
      head = nullptr;
      }
      info *gethead() {
        return head;
      }
      bool listElements() {
        if(head == nullptr) {
          return true;
        }
      }
      void addatbeg(string, string, string, string, string);
      void print(ostream &out);
      void deleteatbeg(string);
      void bubbleSort(string);
      void swap(info *a, info *b);
};
