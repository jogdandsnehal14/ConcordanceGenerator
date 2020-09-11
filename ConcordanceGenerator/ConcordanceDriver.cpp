// -------------------------------------------------------------------------- -
// File: ConcordanceDriver.cpp
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// The concordance generator program will read a text corpus from a file 
// and output its concordance in KWIC format (excluding the specified set 
// of stop words from stopwords.txt file). Every non-stop word in the entry 
// is treated as a key and five words of context before and after for KWIC 
// output (unless the word is so close to the beginning or end of the corpus 
// that there aren’t five words before or after it).
//---------------------------------------------------------------------------
// ASSUMPTIONS:
//    Input:
//       The program would read an input file provided as an argument to the program. 
//       Example:
//       ./main corpus.txt
//       The stop words are provided in stopwords.txt file(casing is important).
//       The file is in the same directory as the program, with one stop word per line.
//       Following constraints are applied to a key in corpus in addition to stop words being excluded :
//          * Words are bounded by white space.A punctuation isn’t considered as a word.
//          * Leadingand trailing punctuation at the beginningand /or end of a “word” are ignored.
//    Exiting Program:
//       Program will exit after printing the output.
//    Output:
//       The program will output its concordance in KWIC format
//---------------------------------------------------------------------------

#include <iostream>
#include "ConcordanceGenerator.h"

using namespace std;

//----------------------------------------------------------------------------
// main
// The main function to execute the Concordance Generator program
int main(int argc, char** argv)
{
   if (argc <= 1)
   {
      cout << "Corpus file name should be provided as a command line param." << endl;
      return -1;
   }

   ConcordanceGenerator generator;
   if (generator.generate(argv[1], "stopwords.txt")) 
      generator.print();
   else 
      cout << "Error generating the concordance.";

   return -1;
}