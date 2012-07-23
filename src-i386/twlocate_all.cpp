#include "twlocate_all.h"
#include <vector>
#include <string>
#include "PCREWrapper.h"

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twlocate_all(const SEXP v, const SEXP r) {
    BEGIN_RCPP
    vector<string>        text = as< vector<string> >(v);
    string                pattern = as<string>(r);
    vector<vector<vector<int> > > results;
    PCREWrapper           p(pattern);
    
    for (vector<string>::iterator t=text.begin(); t != text.end(); t++) {
      vector<vector<int> > res0;
      p.locate_all(*t, res0);
      results.push_back(res0);
    }

    return(Rcpp::wrap(results));
    END_RCPP
}
