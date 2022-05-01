#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ArgumentManager.h"
#include "record.h"
using namespace std;

// worked with Joseph Jophy, Brody Pen, and Maximus Furtado
 
int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string ifile = am.get("input"); //get the filename of argument name "input"
    string ofile = am.get("output"); //get the filename of argument name "output"
    string sfile = am.get("sort"); // this is going to be sort
    ifstream input(ifile);
    ofstream output(ofile);
    ifstream sort(sfile);
    output << "";

    vector<string>sortData;
    string s, data, first, last, dob, gpa, id;
    record object;
  
    while(getline(input, data)) {
      if(data[0] == 'd') {
        object.deleteatbeg(data.substr(7,7));
        continue;
      }
      id = data.substr(data.find("id:") + 3, data.find(',') - 4);
      data = data.substr(data.find(',') + 1);
      first = data.substr(data.find("first:") + 6, data.find(',') - 6);
      data = data.substr(data.find(',') + 1);
      last = data.substr(data.find("last:") + 5, data.find(',') - 5);
      data = data.substr(data.find(',') + 1);
      dob = data.substr(data.find(":") + 1, data.find(',') - 4);
      data = data.substr(data.find(',') + 1);
      gpa = data.substr(data.find("gpa:") + 1, 7);
      //gpa = data.substr(data.find("gpa:") + 4, data.find(',') - 4);
      data = data.substr(data.find(',') + 1);
      data = "";
      object.addatbeg(id, first, last, dob, gpa);
    }
    while(!sort.eof()) {
      getline(sort, s);
      if(s.empty()) {
        continue;
      }
      sortData.push_back(s);
    }
    object.bubbleSort(sortData);
    object.print(output);
  
  return 0;
}
