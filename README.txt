*********************************************************************

twine - the fast string processing library using PCRE and Rcpp.
author: David L Gibbs <gibbsdavidl@gmail.com>

*********************************************************************

First you need to get and build PCRE, the regular expression library.
http://www.pcre.org/

*********************************************************************
PCRE build on linux:

I think just sudo apt-get install PCRE or the equivalent command.
---------------------------------------------------------------------
---------------------------------------------------------------------
PCRE build on a mac:
In order to build PCRE with both i386 and x86_64 libraries:

sudo env CXXFLAGS="-arch i386 -arch x86_64" \
    CFLAGS="-arch i386 -arch x86_64" \
    LDFLAGS="-arch i386 -arch x86_64" \
    ./configure --disable-dependency-tracking --enable-utf8 --enable-jit
sudo make
sudo make install

You can check that the build went OK:

%lipo -info /usr/local/lib/libpcre.a
Architectures in the fat file: /usr/local/lib/libpcre.a are: i386 x86_64

**********************************************************************

THEN you can check out the source from the git repo
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
