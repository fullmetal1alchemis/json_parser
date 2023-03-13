
COMPILEOPT := -Wall -std=c++17

test: clean
	clang++ test.cpp -o test ${COMPILEOPT}

.PHONY:clean

clean:
	rm -f test
	
	
