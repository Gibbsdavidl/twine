#include "twcases.h"
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace Rcpp;

// SEXP is a pointer to an SEXPREC object:

RcppExport SEXP twtoUpper(SEXP v) {
    BEGIN_RCPP
    StringVector text(v);
    std::transform(text.begin(), text.end(), text.begin(), make_string_transformer(toupper));    
    return(text);
    END_RCPP
}


RcppExport SEXP twtoLower(SEXP v) {
    BEGIN_RCPP
    StringVector text(v);	
    std::transform(text.begin(), text.end(), text.begin(), make_string_transformer(tolower));          
    return(text);
    END_RCPP
}
