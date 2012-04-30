#include "twdetect.h"
#include <vector>
#include <string>
#include <pcrecpp.h>

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twdetect(const SEXP v, const SEXP r, const SEXP b) {
    BEGIN_RCPP
    vector<string> text = as< vector<string> >(v);
    string pattern = as<string>(r);
    int fullmatch = as<int>(b);
    vector<bool> results;
    pcrecpp::RE re(pattern); // need to be pcrecpp::UTF8() as an option?
    vector<string>::iterator textIterator;

    if (fullmatch == 1) {
      for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
	results.push_back(re.FullMatch(*textIterator));
      }
    } else {
      for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
      	results.push_back(re.PartialMatch(*textIterator));
      }
    }
    return(Rcpp::wrap(results));
    END_RCPP
}
