// <Your name>
// Main file for Part 2.1 of Homework 3.

#include "sequence_map.h"
#include "avl_tree.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

namespace {

// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &dbx_filename, TreeType &a_tree) {
  // Code for running Part 2.1
string db_line;
  string a_reco_seq;
  string an_enz_acro;
ifstream inputfle;
inputfle.open(dbx_filename);

for(int i=0; i<10;i++)
{
  getline(inputfle,db_line); // skips the first 10 lines 
}

// Read the file line-by-line:
while (getline(inputfle, db_line)) 
{
stringstream inpt_srm(db_line); // string stream takes a line and puts it into the ostream/ instream of the stream
  // Get the first part of the line:
getline(inputfle,an_enz_acro,'/'); // get line gets the enzyme acroynm from file 

while(getline(inputfle,a_reco_seq,'/'))
{
  SequenceMAP new_sequence_map(a_reco_seq,an_enz_acro);
  a_tree.insert(new_sequence_map);
}

}

inputfle.close(); // make sure to close file or seg fault 

string querals;
 while (cin >> querals) 
 {
        SequenceMAP query{querals, ""}; 
        if (a_tree.contains(query)) 
        {
            a_tree.printEnzm(query);
        }
        else{
            cout << "Not here" << endl;
            } 
        
        // You can use public functions of TreeType. For example:
      //a_tree.insert();
      //a_tree.printTree();
 }
}
}// namespace

int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  cout << "Input filename is " << dbx_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMAP> a_tree;
  QueryTree(dbx_filename, a_tree);
  return 0;
}
