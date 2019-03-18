/*
 * Date: March 18, 2019
 * Perform CPU benchmarking by multiplying two double-precision random square matrices with various size
 * Giga Floating-Point Operation Per Second (GFLOPS) will be used to gauge CPU performance 
 */

#include <iostream>

int main(int argc, char *argv[]){

    if (argc != 2){
        std::cout << "Usage: " << argv[0] << " matrix-size" << std::endl;
    }

    int size = stoi(argv[1]); // convert the second argument to matrix size
    // Put an error handler here

    return 0;  
}
