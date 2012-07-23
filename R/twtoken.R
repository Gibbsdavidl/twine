## This file is part of strvec.
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
## along with strvec.  If not, see <http://www.gnu.org/licenses/>.

twtoken <- function
### Takes a vector of strings, and a collection of characters
### to split by, and returns a list of "tokenized" character vectors.

(v,   ##<< the string vector
 s    ##<< the elements to split by.
 ) {

    ## Make the call...
    val <- .Call("twtoken",
                 as.character(v),
                 as.character(s),
                 PACKAGE="twine")
    val
    ### returns the list of tokens
  }
