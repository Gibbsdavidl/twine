#include "twdetect_all.h"
#include <vector>
#include <string>
#include "PCREWrapper.h"

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twdetect_all(const SEXP v, const SEXP r) {
    BEGIN_RCPP
    vector<string>        text = as< vector<string> >(v);
    string                pattern = as<string>(r);
    vector<vector<vector<bool> > > results;
    PCREWrapper           p(pattern);
    
    for (vector<string>::iterator t=text.begin(); t != text.end(); t++) {
      vector<vector<bool> > res0;
      p.detect_all(*t, res0);
      results.push_back(res0);
    }

    return(Rcpp::wrap(results));
    END_RCPP
}
