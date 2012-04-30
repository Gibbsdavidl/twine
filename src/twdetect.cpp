#include "twmatch.h"
#include <vector>
#include <stdlib.h>
#include <string>
#include <pcrecpp.h>
#include <iostream>
//#include <pcre.h>

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;

 
// SEXP is a pointer to an SEXPREC object:

RcppExport SEXP twdetect(const SEXP v, const SEXP r, const SEXP b) {
    BEGIN_RCPP
    vector<string> text = as< vector<string> >(v);
    vector<bool> res1(text.size());
    string pattern = as<string>(r);
    int fullmatch = as<int>(b);
    vector<bool> results;
    pcrecpp::RE re(pattern, pcrecpp::UTF8());
    vector<string>::iterator textIterator;

    if (fullmatch == 1) {
      for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
	results.push_back(re.FullMatch(*textIterator));
      }
    } else {
      for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
      	results.push_back(re.PartialMatch(*textIterator));
	//transform(text.begin(), text.end(), res1.begin(), re.PartialMatch());
      }
    }
    return(Rcpp::wrap(results));
    END_RCPP
}
