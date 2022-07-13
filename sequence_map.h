//Mahgabin Khanom
//This class (which is non-templated) will be used in the following programs. First test it with your own test functions to make sure that it operates correctly
#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include "dsexceptions.h"
#include <array>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class SequenceMAP // no type
{
public:
~SequenceMAP() = default; 
//destructor

SequenceMAP() = default; 
// constructor / zero parameter 

SequenceMAP(const SequenceMAP & rhs) = default;
 // from book page 35 (copy constructor)

SequenceMAP& operator=(const SequenceMAP & rhs) = default; 
// copy assignment 

SequenceMAP(SequenceMAP && rhs) = default; 
// move constructor

SequenceMAP& operator=(SequenceMAP&&) = default; 
//move assignment 


SequenceMAP(const string &a_rec_seq, const string &an_enz_acro) //constructs a SequenceMap from two strings
{
    recognition_sequence_= a_rec_seq; // sets the private string to the parameterized string 
    enzyme_acronyms_.push_back(an_enz_acro); // since the private string is a vector, we push it in through the back for each string that was in the parameter (setter once again)
}
 
bool operator<(const SequenceMAP &rhs) const // use the operator that was provided (<) to make comparison from lhs to rhs values
{
   return rhs.recognition_sequence_ > recognition_sequence_;
}

friend ostream &operator<<(ostream &out, const SequenceMAP &a_output)
{
    for (std::size_t i=0; i<a_output.enzyme_acronyms_.size(); i++)
    {
        out << a_output.enzyme_acronyms_[i]<< endl;
    }
return out;
}

void Merge(const SequenceMAP &other_sequence)
{
    if (recognition_sequence_ != other_sequence.recognition_sequence_)
    {
        return;
    } // edge case

    for (std::size_t i = 0; i < other_sequence.enzyme_acronyms_.size(); i++) 
    {
    enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);  // going through the entire length of the vector, we merge in (or concatenate) the values of other sequence acronyms inside the actual private vector
    }
}

private:
string recognition_sequence_;
vector<string> enzyme_acronyms_;

};
#endif
