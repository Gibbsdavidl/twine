#ifndef _twine_TWDETECT_H
#define _twine_TWDETECT_H
#include <Rcpp.h>
/*
* note : RcppExport is an alias to ‘extern ”C”‘ defined by Rcpp. *
* It gives C calling convention to the rcpp hello world function so that
* it can be called from .Call in R. Otherwise, the C++ compiler mangles the
* name of the function and .Call can’t find it. *
* It is only useful to use RcppExport when the function is intended to be called
* by .Call. See the thread http://thread.gmane.org/gmane.comp.lang.r.rcpp/649/focus=672
* on Rcpp-devel for a misuse of RcppExport */
RcppExport SEXP twdetect(const SEXP vec, const SEXP regex, const SEXP fullmatch) ;
#endif
