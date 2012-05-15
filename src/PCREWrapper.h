#ifndef _twine_PCREWRAPPER_H
#define _twine_PCREWRAPPER_H
#include <Rcpp.h>
#include <vector>
#include <string>
#include <pcre.h>

using std::vector;
using std::string;
using std::cout;

#define OVECSIZE 128

class PCREWrapper
{
 private:
  string pattern;
  string text;
  pcre* re;
  int textLength;
  int* ovector;

 public:
  PCREWrapper();
  PCREWrapper(string pattern, string text);
  ~PCREWrapper();
  bool setPattern(string pattern); 
  bool setText(string txt); 
  int  exec(int offset);
  void match(bool single, vector<string> res0);
  void locate(bool single, vector<int> res0); 
  void detect(bool single, vector<bool> res0);


};

#endif
