// -------------------------------------------------------------------------- -
// File: ConcordanceGenerator.cpp
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// ConcordanceGenerator: 
//  The cpp file for Concordance Generator class
//  Provides the set of variables and functions to generate 
//  a Concordance
//---------------------------------------------------------------------------

#include "ConcordanceGenerator.h"
#include <sstream>
#include <unordered_set>
#include <queue>

using namespace std;

/** The default constructor
*/
ConcordanceGenerator::ConcordanceGenerator()
{
   tree = new BSTree();
}

/** Sets the corpus from the given input file
    @pre  None.
    @return  true if the file is successfully read
    */
bool ConcordanceGenerator::setCorpus(string corpusFile)
{
   ifstream corpusFileStream;

   corpusFileStream.open(corpusFile);
   if (corpusFileStream.is_open())
   {
      char chr;
      while (!corpusFileStream.eof())
      {
         chr = corpusFileStream.get();
         corpus += tolower(chr);
      }

      corpusFileStream.close();
      return true;
   }

   return false;
}

/** Sets the stop words from the given input file
    @pre  None.
    @return  true if the file is successfully read
    */
bool ConcordanceGenerator::setStopWords(string stopWordsFile)
{
   ifstream stopWordsFileStream;

   stopWordsFileStream.open(stopWordsFile);
   if (stopWordsFileStream.is_open())
   {
      string stopword;
      while (!stopWordsFileStream.eof())
      {
         stopWordsFileStream >> stopword;
         stopwords.insert(stopword);
      }

      stopWordsFileStream.close();
      return true;
   }

   return false;
}

/** Generates the binary search tree from the given input files
    @pre  None.
    @param corpusFile  The input corpus file
    @param stopWordsFile  The input stop words file
    @return true if the corpus is successfully generated
    or a null pointer. */
bool ConcordanceGenerator::generate(string corpusFile, string stopWordsFile)
{
   if (!setCorpus(corpusFile))
   {
      cout << "Error reading the corpus file." << endl;
      return false;
   }

   if (!setStopWords(stopWordsFile))
   {
      cout << "Error reading the stop words file." << endl;
      return false;
   }

   istringstream wordStream(corpus);
   string word;
   while (wordStream >> word)
   {
      string cleanWord = getCleanKeyword(word);
      if (cleanWord.size() > 0) corpusQueue.push_back(word);
   }

   for (int i = 0; (size_t) i < corpusQueue.size(); i++) {
      string preContext = "";
      string postContext = "";

      // get pre context (previous 5 words)
      for (int j = i - 5; j < i && j >= 0; j++) preContext += corpusQueue[j] + " ";

      // get post context (next 5 words)
      for (int j = i + 1; j <= i + 5 && (size_t) j < corpusQueue.size(); j++) postContext += corpusQueue[j] + " ";

      // remove trailing and leading punctuations 
      // all characters other than a to z are ignored
      string keyword = getCleanKeyword(corpusQueue[i]);
      if (!isStopWord(keyword))
      {
         // not stopword, insert into BST
         tree->insert(keyword, preContext, postContext);
      }
   }

   return true;
}

/** Prints the concordance generated output.
   */
void ConcordanceGenerator::print()
{
   tree->print();
}

/** Cleans the given keyword and removes all trailing and leading 
    invalid characters
    note: all characters other than a to z are considered invalid
    @pre  None.
    @param word  The word to be cleaned
    @return  the cleaned word
    */
string ConcordanceGenerator::getCleanKeyword(string word)
{
   int start = 0;
   int end = word.length();
   for (int i = 0; (size_t) i < word.length(); i++)
   {
      if (word[i] < 'a' || word[i] > 'z') start++;
      else break;
   }

   for (int i = word.length(); i > 0; i--)
   {
      if (word[i] < 'a' || word[i] > 'z') end--;
      else break;
   }

   return word.substr(start, end - start + 1);
}

/** Checks if the given word is a stop word
    @pre  None.
    @param word  The word to be cleaned
    @return  true if is a stop word
    */
bool ConcordanceGenerator::isStopWord(string keyword)
{
   return stopwords.find(keyword) != stopwords.end();
}

/** The desctructor
   */
ConcordanceGenerator::~ConcordanceGenerator()
{
   if (tree != nullptr) delete tree;
}