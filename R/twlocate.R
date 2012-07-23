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

twlocate <- function
### Takes a vector of strings, and a regular expression,
### and returns a list of positions for each potential match.
### The positions of captured sub-strings is returned in vector
### positions > 1.

(v,          ##<< the string vector
 pattern     ##<< a regular expression.
 ) {

    ## Make the call...
    val <- .Call("twlocate",
                 as.character(v),
                 as.character(pattern),
                 PACKAGE="twine")

    val
    ### returns the vector of positions matched in the text.
  }


twlocate_all <- function
### Takes a vector of strings, and a regular expression,
### and returns a list of positions for each potential match.
### The positions of captured sub-strings is returned in vector
### positions > 1.

(v,          ##<< the string vector
 pattern     ##<< a regular expression.
 ) {

    ## Make the call...
    val <- .Call("twlocate_all",
                 as.character(v),
                 as.character(pattern),
                 PACKAGE="twine")

    val
    ### returns the vector of positions matched in the text.
  }
