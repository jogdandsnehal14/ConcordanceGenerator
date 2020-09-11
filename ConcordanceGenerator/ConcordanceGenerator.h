// -------------------------------------------------------------------------- -
// File: ConcordanceGenerator.h
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// ConcordanceGenerator: 
//  The header file for Concordance Generator class
//  Provides the set of variables and functions to generate 
//  a Concordance
//---------------------------------------------------------------------------

#ifndef CONCORDANCE_GENERATOR_
#define CONCORDANCE_GENERATOR_

//---------------------------------------------------------------------------
// ConcordanceGenerator:
//  The header file for Concordance Generator class
//  Provides the set of variables and functions to generate 
//  a Concordance
//---------------------------------------------------------------------------

#include <istream>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <queue>
#include "BSTree.h"

using namespace std;

class ConcordanceGenerator
{
private:
   string corpus;
   deque<string> corpusQueue;
   unordered_set<string> stopwords;
   BSTree* tree;

   bool setCorpus(string corpusFile);
   bool setStopWords(string stopWordsFile);
   string getCleanKeyword(string word);
   bool isStopWord(string keyword);
public:
   ConcordanceGenerator();
   ~ConcordanceGenerator();
   bool generate(string corpusFile, string stopWordsFile);
   void print();
};
#endif