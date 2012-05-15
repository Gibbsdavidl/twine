#include "twsplit.h"
#include <vector>
#include <string>
#include <pcre.h>

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;

#define OVECCOUNT 1024
 
RcppExport SEXP twsplit(const SEXP v, const SEXP r) {
    BEGIN_RCPP
    vector<string> text = as<vector<string> >(v);
    string pattern = as<string>(r);
    vector<string>::iterator textIterator;
    vector<string> results;

    const char* error; int erroffset;
    const char *substring_start;
    int substring_length;
    pcre *re;
    int rc; int i;
    int ovector[OVECCOUNT];
    re = pcre_compile(pattern.data(),       /* the pattern */
		      0,                    /* default options */
		      &error,               /* for error message */
		      &erroffset,           /* for error offset */
		      NULL);                /* use default character tables */


    for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
      rc = pcre_exec(
		     re,                   /* the compiled pattern */
		     NULL,                 /* no extra data - we didn't study the pattern */
		     (*textIterator).data(),  /* the subject string */
		     (*textIterator).size(),  /* the length of the subject */
		     0,                    /* start at offset 0 in the subject */
		     0,                    /* default options */
		     ovector,              /* output vector for substring information */
		     OVECCOUNT);           /* number of elements in the output vector */

      if (rc < 0) {
	// error!
	printf("Error!\n");
      } else if (rc == 0) {
	// the ovector wasn't big enough
	printf("matching vector not big enough!\n");
      } else {
	// we have matches.
	for (i = 0; i < rc; i++)
	  {
	    substring_start = (*textIterator).data() + ovector[2*i];
	    substring_length = ovector[2*i+1] - ovector[2*i];
	    printf("%2d: %.*s\n", i, substring_length, substring_start);
	  }

      }
      //results.push_back(abit);
    }
    pcre_free(re);     /* Release memory used for the compiled pattern */
    return(Rcpp::wrap(results));
    END_RCPP
}

