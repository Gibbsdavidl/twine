#include "twmatch.h"
#include <vector>
#include <stdlib.h>
#include <string>
#include <pcrecpp.h>
#include <pcre.h>

// SEXP is a pointer to an SEXPREC object:

RcppExport SEXP twmatch(const SEXP v, SEXP r) {
    using namespace Rcpp;
    BEGIN_RCPP
      
    std::string pattern = Rcpp::as<std::string>(r);
    std::vector<string> text = Rcpp::as< std::vector<string> >(v);
    std::vector<bool> results(text.size());
    pcrecpp::RE re(pattern);

    for (int i=0; i<text.size(); ++i) {
      results[i] = re.FullMatch(text[i]);
    }

    return(wrap(results));
    END_RCPP
}
