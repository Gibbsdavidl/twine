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
  textLength=0;
}

PCREWrapper::PCREWrapper(char* ptn, char* txt) 
{
  pattern.assign(ptn);
  text.assign(txt);
  textLength = text.size();
}


PCREWrapper::~PCREWrapper()
{
  if (re != NULL) {
    free(re);
  }
}


bool PCREWrapper::setPattern(char* ptrn) 
{
  const char *error;
  int erroffset;
  pattern = ptrn;
  re = pcre_compile(ptrn,       /* the pattern */
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


void PCREWrapper::match(bool single, vector<string> res0)
{

}

void PCREWrapper::locate(bool single, vector<int> res0); 
{

}
