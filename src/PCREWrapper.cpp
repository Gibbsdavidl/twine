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
    //printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
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
    case PCRE_ERROR_NOMATCH: break;
    default:  break; //printf("Matching error %d\n", rc);
    }
    return -1;
  }
  return(rc);
}


int PCREWrapper::match(string & txt, vector<string> & res0)
{
  text = txt;
  int rc = exec(0);  
  if (rc > 0) {
    for (int i = 0; i < rc; i++){
      string s(text.data()+ovector[i*2], 
	       text.data()+ovector[i*2+1]); 
      res0.push_back(s);
    }
  } else {
    res0.push_back("");
  }
  return ovector[1];
}


int PCREWrapper::locate(string & txt, vector<int> & res0)
{
  text = txt;
  int rc = exec(0);  
  if (rc > 0) {
    for (int i = 0; i < rc; i++){
      res0.push_back(ovector[i*2]+1);
    }
  } else {
    res0.push_back(0);
  }
  return ovector[1];
}


int PCREWrapper::locate_all(string & txt, vector<vector<int> > & res0) 
{
  text = txt;
  int offset = 0;
  int rc = exec(offset);  
  while(rc > 0) {
    vector<int> res1;
    for (int i = 0; i < rc; i++) {
      res1.push_back(ovector[i*2]+1);
    }
    res0.push_back(res1);
    offset = ovector[1];
    rc = exec(offset);  
  }
  return offset;
}





int PCREWrapper::detect(string & txt, vector<bool> & res0)
{
  text = txt;
  int rc = exec(0);  
  if (rc > 0) {
    for (int i = 0; i < rc; i++){
      res0.push_back(true);
    }
  } else {
    res0.push_back(false);
  }
  return ovector[1];
}

// starting with a list of strings.
// one line gets sent here.
// repeatedly match on this line.
// each match, push a T

int PCREWrapper::detect_all(string & txt, vector<vector<bool> > & res0) 
{
  text = txt;
  int offset = 0;
  int rc = exec(offset);  
  while(rc > 0) {
    vector<bool> res1;
    for (int j = 0; j < rc; j++) {
      res1.push_back(true);
    }
    res0.push_back(res1);
    offset = ovector[1];
    rc = exec(offset);  
  }
  return offset;
}



int  PCREWrapper::split(string & txt, vector<string> & res0)
{
  text = txt;
  int offset = 0;
  const char * start = text.data();

  while(exec(offset) > 0) {  
    string s(start, text.data()+ovector[0]);
    res0.push_back(s);
    start = text.data()+ovector[1];
    offset = ovector[1];
  }

  string s(start, text.data()+text.size());
  res0.push_back(s);
  return offset;
}

