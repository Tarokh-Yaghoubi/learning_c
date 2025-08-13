

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


int main() {

	// Never mix and match byte-oriented functions like "fprintf" with wide-oriented functions like fwprintf()
	// Decide if a stream will be byte-oriented or wide-oriented and stick with those types of I/O functions.
	
	// In more details: streams can be either byte-oriented or wide-oriented. when a stream is first created,
	// it has no orientation, but the first read/write will set the orientation.
	
	// If you first use a wide operation like fwprintf(), it will orient the stream wide. 
	// If you first use a byte operation like fprintf(), it will orient the stream by bytes.
	
	// You can manually set an unoriented stream one way or the other with a call to fwide(). You can use that same function 
	// to get the orientation of a stream.
	
	// If you need to change the orientation mid-flight, you can do it with freopen().
	
	/*
	 
	   I/O Functions
	   include stdio.h and wchar.h

	return EXIT_SUCCESS;
}
