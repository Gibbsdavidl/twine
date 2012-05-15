#ifndef _twine_PCREWRAPPER_H
#define _twine_PCREWRAPPER_H
#include <Rcpp.h>
#include <vector>
#include <string>
#include <pcre.h>

using std::vector;
using std::string;
using std::cout;

#define OVECSIZE 768 // == 3 * 256

class PCREWrapper
{
 private:
  string pattern;
  string text;
  pcre* re;
  int* ovector;
  
 public:
  PCREWrapper();
  PCREWrapper(string & pattern);
  PCREWrapper(string & pattern, string & text);
  ~PCREWrapper();

  bool setPattern(string & pattern); 
  bool setText(string & txt); 
  int  exec(int offset);
  int  match(bool single, vector<string> & res0);
  int  locate(bool single, vector<int> & res0); 
  int  detect(bool single, string & txt, vector<bool> & res0);
};

#endif
