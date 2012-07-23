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

twupper <- function
### Takes a vector of strings and transforms them to upper case.
(vec ##<< the string vector
 ) {

    ## Make the call...
    val <- .Call("twtoUpper",
                 vec,
                 PACKAGE="twine")

    val
    ### returns character vectors
  }


twlower <- function
### Takes a vector of strings and transforms them to upper case.
(vec ##<< the string vector
 ) {

    ## Make the call...
    val <- .Call("twtoLower",
                 vec,
                 PACKAGE="twine")

    val
    ### returns character vectors
  }

