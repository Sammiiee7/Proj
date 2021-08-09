#FILE NAME: Makefile
#
#DESCRIPTION: Makefile for Polynomial Program
#
#PURPOSE: Build a program execuatble on linux
#
#MODIFICATION HISTORY:
#
#Author          Date           Modification History
#-------------   --------       -------------------
#Samuel Ayeju   2018-03-25     Version 1.0
#--------------------------------------------------

# This is our original generic makefile command that will build
# any stand alone " .cpp" source file.
# Usage: e.g., make hello
    

.cpp :
	g++ -o $* $*.cpp -std=c++11

#	This will use the object files required for "poly_class" and link
#	them into a single executable.
# 	Usage: make poly_class

poly_class: Polynomial.o poly_class.o
	g++ -o $@ $@.o 	Polynomial.o -std=c++11

#	This will build the two object files required for "poly_class"
#	which are dependent on Polynomial.h

poly_class.o : Polynomial.h
Polynomial.o : Polynomial.h
