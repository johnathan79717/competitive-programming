# Time-stamp: </wrf/c/nearpt3/Makefile, Wed,  7 Dec 2005, 15:27:01 EST, http://wrfranklin.org/>

# Pick one
CXX=icc
CXX=g++
CXX=icpc

CC=$(CXX)

# Only the last setting counts.

CXXFLAGS1= -O3   #  g++
CXXFLAGS1= 
CXXFLAGS1= -g
CXXFLAGS1= -O3 -xB  -ip -ipo -unroll4 -parallel -wd1572  #  icpc
CXXFLAGS1= -O3 -xB  -ip -ipo -unroll4 -parallel -wd1572  -DSTATS #  icpc

# -fast not for the t43p.  no streaming simd.
#-axB affects time by 3/2.
# -fno-alias generates bad code
# -ansi-alias has no effect

# Make it possible for the program to print out how it was compiled.
CXXFLAGS =
CXXFLAGS = ${CXXFLAGS1}  -DFLAGS='"CXX=${CXX} CXXFLAGS=${CXXFLAGS1}"'

# Public files
F=   Makefile main7.cc main5.cc nearpt3.cc compcellsearchorder.cc makerandpts.cc splitfq.cc asc2binpts.cc printdist.cc cellsearchorder


main7.cc main5.cc :   nearpt3.cc 

cellsearchorder: 	compcellsearchorder
	compcellsearchorder > cellsearchorder

tar:
	tar cfvz nearpt3.tar.gz $F     # Public

clean:
	rm *.o main7 main5


