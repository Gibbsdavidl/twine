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

twdetect <- function
### Takes a vector of strings, and a regular expression,
### and returns a list of booleans for each potential match.
### Captured sub-strings are detected as well.

(v,          ##<< the vector of strings
 pattern     ##<< a regular expression.
 ) {

    ## Make the call...
    val <- .Call("twdetect",
                 as.character(v),
                 as.character(pattern),
                 PACKAGE="twine")

    val
    ### returns a list of boolean vectors
  }


twdetect_all <- function
### Takes a vector of strings, and a regular expression,
### and returns a list of booleans for each potential match.
### Captured sub-strings are detected as well.

(v,          ##<< the vector of strings
 pattern     ##<< a regular expression.
 ) {

    ## Make the call...
    val <- .Call("twdetect_all",
                 as.character(v),
                 as.character(pattern),
                 PACKAGE="twine")

    val
    ### returns a list of boolean vectors
  }
