#include "twsplit.h"
#include <vector>
#include <string>
#include <pcrecpp.h>

using Rcpp::as;
using std::vector;
using std::string;
using std::cout;
 
RcppExport SEXP twsplit(const SEXP v, const SEXP r) {
    BEGIN_RCPP
    vector<string> text = as< vector<string> >(v);
    string pattern = as<string>(r);
    vector<string>::iterator textIterator;
    vector<string> results; 
    char* start = 0;
    char* end = 0;
    string s;
    bool flag = true;
    pcrecpp::RE re(pattern);

    for (textIterator=text.begin(); textIterator != text.end(); textIterator++) {
      pcrecpp::StringPiece input(*textIterator);
      start = (char*)input.data();
      while(flag) {
	flag = re.FindAndConsume(&input, &s);
	if(flag) {
	  end = (char*)input.data();
	  string abit(start, end-s.size());
	  results.push_back(abit);
	  start = end;
	}	
      }
      //textIterator=text.end();
      string abit(end, end+text.size());
      results.push_back(abit);
    }

    return(Rcpp::wrap(results));
    END_RCPP
}

