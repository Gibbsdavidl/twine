## This file is part of twine.
##
## This is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## This is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with twine.  If not, see <http://www.gnu.org/licenses/>.

twmatch <- function
### Takes a vector of strings, and a regular expression,
### and returns a list of character vectors. Each match is
### returned, and after the first match, captured sub-strings
### are listed.

(v,         ##<< the string vector
 pattern    ##<< a regular expression.
 ) {

    ## Make the call...
    val <- .Call("twmatch",
                 as.character(v),
                 as.character(pattern),
                 PACKAGE="twine")

    val
    ### returns the vector of matched strings
  }
