#include "twlocate.h"
#include <vector>
#include <string>
#include "PCREWrapper.h"

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twlocate(const SEXP v, const SEXP r) {
    BEGIN_RCPP
    vector<string> text = as<vector<string> >(v);
    string         pattern = as<string>(r);
    vector<vector <int> >    results; 
    PCREWrapper    p(pattern);
    
    for (vector<string>::iterator t=text.begin(); t != text.end(); t++) {
      vector<int> res0;
      p.locate(*t, res0);
      results.push_back(res0);
    }

    return(Rcpp::wrap(results));
    END_RCPP
}
