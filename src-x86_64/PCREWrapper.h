#ifndef _twine_PCREWRAPPER_H
#define _twine_PCREWRAPPER_H
#include <Rcpp.h>
#include <vector>
#include <string>
#include <pcre.h>

using std::vector;
using std::string;
using std::cout;

#define OVECCOUNT 128

class PCREWrapper
{
 private:
  string pattern;
  string text;
  pcre* re;
  int textLength;

 public:
  PCREWrapper();
  PCREWrapper(char* pattern, char* text, int txtlen);
  ~PCREWrapper();
  bool setPattern(char* pattern); 
  void match(int times, vector<string> res0);

};

#endif
