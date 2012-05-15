#include "twdetect.h"
#include <vector>
#include <string>
#include "PCREWrapper.h"

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twdetect(const SEXP v, const SEXP r, const SEXP b) {
    BEGIN_RCPP
    vector<string>        text = as< vector<string> >(v);
    string                pattern = as<string>(r);
    vector<vector<bool> > results;
    PCREWrapper           p(pattern);
    
    for (vector<string>::iterator t=text.begin(); t != text.end(); t++) {
      vector<bool> res0;
      p.detect(true, *t, res0);
      results.push_back(res0);
    }

    return(Rcpp::wrap(results));
    END_RCPP
}
