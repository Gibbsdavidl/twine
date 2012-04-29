
#include "twtoken.h"
#include <string.h>



SEXP tokenizer(char* vec, char* s) {
    // split each character string here    
    Rcpp::StringVector sv;
    char* tok;
    int n = strlen(vec);
    char cutter[n];
    strncpy(cutter, vec, n);
    tok = strtok(cutter, s);
    while (tok != NULL) {
	sv.push_back(tok);
	tok = strtok(NULL, s);
    }
    return(sv);
}

RcppExport SEXP twtoken(SEXP v, SEXP s) {
    using namespace Rcpp;
    BEGIN_RCPP
    StringVector orig(v);		// creates Rcpp string vector from SEXP
    StringVector splstr(s);
    List list(orig.size());
    for (int i = 0; i < orig.size(); ++i) {
	list[i] = tokenizer(orig[i], splstr[0]);
    }
    return(list);
    END_RCPP
}
