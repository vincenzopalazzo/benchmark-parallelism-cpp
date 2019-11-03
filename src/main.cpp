//
// Created by https://github.com/vincenzopalazzo on 11/3/19.
//
#include <iostream>

#include "stl.h"
#include "openmp.h"
#include "seq.h"
#include <chrono>
#include <ctime>

void runTest();

int main(int argc, char* argv[])
{
    runTest();
}

void runTest(){
    Benchmark::STLAlgorithms stl;
    Benchmark::OPENMPAlgorithms openmp;
    Benchmark::SEQAlgorithms seq;

    auto start = std::chrono::system_clock::now();
    stl.run("");
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished STL computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::system_clock::now();
    openmp.run("/media/vincenzo/Maxtor/BitcoinCore/block_json");
    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished OPENMP  computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::system_clock::now();
    seq.run("/media/vincenzo/Maxtor/BitcoinCore/block_json");

    end = std::chrono::system_clock::now();
    elapsed_seconds = end-start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished SEQ computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    // Some computation here


}

