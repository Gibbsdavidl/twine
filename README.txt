*********************************************************************

twine - the fast string processing library using PCRE and Rcpp.
author: David L Gibbs <gibbsdavidl@gmail.com>

*********************************************************************

Fresh source files from the git repo
git clone git@github.com:Gibbsdavidl/twine.git

**********************************************************************

and from the directory above twine/

R CMD build twine
R CMD check twine_0.1.tar.gz
R CMD INSTALL twine_0.1.tar.gz

**********************************************************************

Lastly, start up R and try out some commands!

library(twine)
?twmatch
?twdetect
?twlocate
?twlen
?twtoUpper
?twtoLower

*********************************************************************
// -----------------------------------------------------------------------
// REGEXP SYNTAX:
//
// This module is part of the pcre library and hence supports its syntax
// for regular expressions.
//
// The syntax is pretty similar to Perl's.  For those not familiar
// with Perl's regular expressions, here are some examples of the most
// commonly used extensions:
//
//   "hello (\\w+) world"  -- \w matches a "word" character
//   "version (\\d+)"      -- \d matches a digit
//   "hello\\s+world"      -- \s matches any whitespace character
//   "\\b(\\w+)\\b"        -- \b matches empty string at a word boundary
//   "(?i)hello"           -- (?i) turns on case-insensitive matching
//   "/\\*(.*?)\\*/"       -- .*? matches . minimum no. of times possible
//
// -----------------------------------------------------------------------
