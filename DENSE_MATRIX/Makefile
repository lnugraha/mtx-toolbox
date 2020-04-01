make:
	g++ -std=c++11 -I/usr/include/gsl -I./include/ \
	./src/DenseMatrix.cpp ./src/Timer.cpp main.cpp -o main -lm -lgsl -lgslcblas

mkl:
	g++ -std=c++11 -I./include/ ./src/DenseMatrix.cpp ./src/Timer.cpp intmkl.cpp \
	-L${MKLROOT}/lib -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 \
	-lpthread -lm -ldl -o intmkl

clear:
	rm main; rm intmkl;
