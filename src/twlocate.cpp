#include "twlocate.h"
#include <vector>
#include <string>
#include <pcrecpp.h>

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twlocate(const SEXP v, const SEXP r) {
    BEGIN_RCPP
    vector<string> text = as< vector<string> >(v);
    string pattern = as<string>(r);
    vector<string>::iterator textIterator;
    vector<int> results; 
    char* start = 0;
    char* end = 0;
    string s;
    
    pcrecpp::RE re(pattern);

    for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
      pcrecpp::StringPiece input(*textIterator);
      start = (char*)input.data();
      re.FindAndConsume(&input, &s);
      end = (char*)input.data();
      results.push_back(end-start-s.size()+1);
    }

    return(Rcpp::wrap(results));
    END_RCPP
}

