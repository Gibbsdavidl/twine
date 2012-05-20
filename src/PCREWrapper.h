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
  int  match(string & txt, vector<string> & res0);
  int  locate(string & txt, vector<int> & res0); 
  int  detect(string & txt, vector<bool> & res0);
  int  split(string & txt, vector<string> & res0);
};

#endif

//R> suppressMessages(library(inline))
//R> src <- 'Rcpp::NumericVector v(4);
//+         v[0] = R_NegInf;  // -Inf
//+         v[1] = NA_REAL;   // NA
//+         v[2] = R_PosInf;  // Inf
//+         v[3] = 42;        // see the Hitchhiker Guide
//+         return Rcpp::wrap(v);'
//R> fun <- cxxfunction(signature(), src, plugin="Rcpp")
//R> fun()
//[1] -Inf   NA  Inf   42
//R> 
