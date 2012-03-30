cc = g++
compileFlag = $(cc) -Wall -fPIC -c sharedlibProj/*.cc -lcurl
compileLibFlag = $(cc) -shared -Wl,-soname,libATwit.so.1 -o libATwit.so.1.0   sharedlibProj/*.o
compileApp = $(cc) -Wall -I./sharedlibProj/ -L/lib  tweetPeak/main.cpp -lATwit -lcurl -o tweetPeak/TwitPeek

all:linkedlib tweetpeak 

linkedlib: 
	cd sharedlibProj; 
	$(compileFlag);
	$(compileLibFlag);
	mv libATwit.so.1.0 /lib;
	ln -sf /lib/libATwit.so.1.0 /lib/libATwit.so.1; 
	cd .. 
tweetpeak:
	$(compileApp)


	

