#include "PCREWrapper.h"
#include <vector>
#include <string>
#include <pcre.h>
#include <Rcpp.h>

using std::vector;
using std::string;
using std::cout;

 
PCREWrapper::PCREWrapper()
{
  pattern="";
  text="";
  re=NULL;
  ovector = NULL;
}


PCREWrapper::PCREWrapper(string & ptn)
{
  setPattern(ptn);
  text="";
  ovector = new int[OVECSIZE];
}


PCREWrapper::PCREWrapper(string & ptn, string & txt) 
{
  setPattern(ptn);
  text = txt;
  ovector = new int[OVECSIZE];
}


PCREWrapper::~PCREWrapper()
{
  if (re != NULL) {
    free(re);
  }
  if (ovector != NULL) {
    delete [] ovector;
  }
}


bool PCREWrapper::setPattern(string & ptrn) 
{
  const char *error;
  int erroffset;
  pattern = ptrn;
  re = pcre_compile(ptrn.data(),        /* the pattern */
		    0,                  /* default options */
		    &error,             /* for error message */
		    &erroffset,         /* for error offset */
		    NULL);              /* use default character tables */
  if (re == NULL) {
    printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
    return false;
  }
  return true;
}


bool PCREWrapper::setText(string & txt) 
{
  text = txt;
}


int PCREWrapper::exec(int offset)
{
  int rc = 0;
  rc = pcre_exec(
		 re,                   /* the compiled pattern */
		 NULL,                 /* no extra data - we didn't study the pattern */
		 text.data(),          /* the subject string */
		 text.size(),          /* the length of the subject */
		 offset,               /* start at offset 0 in the subject */
		 0,                    /* default options */
		 ovector,              /* output vector for substring information */
		 OVECSIZE);            /* number of elements in the output vector */
  if (rc < 0) {
    switch(rc) {
    case PCRE_ERROR_NOMATCH: printf("No match\n"); break;
    default: printf("Matching error %d\n", rc); break;
    }
    return -1;
  }  
  return(rc);
}


int PCREWrapper::match(bool single, vector<string> & res0)
{

  return 1;
}


int PCREWrapper::locate(bool single, vector<int> & res0)
{

  return 1;
}


int PCREWrapper::detect(bool single, string & txt, vector<bool> & res0)
{
  text = txt;
  int rc = exec(0);  
  printf("rc: %d\n", rc);
  if (rc > 0) {
    for (int i = 0; i < rc; i++){
      res0.push_back(true);
    }
  } else {
    res0.push_back(false);
  }
  return rc;
}
