#include "twmatch.h"
#include <vector>
#include <string>
#include <pcrecpp.h>

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;

 
RcppExport SEXP twmatch(const SEXP v, const SEXP r, const SEXP b) {
    BEGIN_RCPP
    vector<string> text = as< vector<string> >(v);
    string pattern = as<string>(r);
    int fullmatch = as<int>(b);
    vector<string>::iterator textIterator;
    vector<string> results; 
    string s;
    
    pcrecpp::RE re(pattern);
    if (fullmatch == 1) {
      for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
	s = "";
	re.FullMatch(*textIterator, &s);
	results.push_back(s);
      }
    } else { // if fullmatch == 0
      for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
	s = "";
	re.PartialMatch(*textIterator, &s);
	results.push_back(s);
      }
    }

    return(Rcpp::wrap(results));
    END_RCPP
}
