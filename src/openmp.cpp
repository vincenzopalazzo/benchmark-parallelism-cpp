//
// Created by https://github.com/vincenzopalazzo on 11/3/19.
//

#include "openmp.h"
#include <experimental/filesystem>
#include <assert.h>

using namespace Benchmark;
namespace fs = std::experimental::filesystem;

void OPENMPAlgorithms::run(std::string path) {
    assert(!path.empty());

    fs::path directoryBase(path);
    auto directoryDimension = 0;
    #pragma opm parallel for
    for(const auto& file : fs::directory_iterator(directoryBase)){
        auto err = std::error_code{};
        auto filesize = fs::file_size(file, err);
        #pragma opm atomic
        if(filesize != -1){
            directoryDimension += filesize;
        }
    }
    std::cout << "Dimension directory " << directoryDimension / 1000000 << " GB\n";
}
