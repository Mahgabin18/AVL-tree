// <Your name>
// Main file for Part 2.2 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <string>
#include <math.h>

#include <fstream>
#include <sstream>
using namespace std;

namespace {

// @dbx_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.

template <typename TreeType>
void TestTree(const string &dbx_filename, const string &seq_filename, TreeType &a_tree)
 {
  // Code for running Part 2.2

int nodecounter = a_tree.counted();
cout << "(2):" << nodecounter << endl;


float average_depth = a_tree.inter()/a_tree.counted();
cout << "(3a):" << average_depth << endl;


cout << "(3b):" << (average_depth/log2(nodecounter)) << endl;

nodecounter = a_tree.counted();
cout << "(6a):" << nodecounter << endl;

average_depth = a_tree.inter()/a_tree.counted();
cout << "(6b):" << average_depth << endl;
cout << "(6c):" << (average_depth/log2(nodecounter)) << endl;

 }

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << dbx_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<int> a_tree;
  TestTree(dbx_filename, seq_filename, a_tree);

  return 0;
}
