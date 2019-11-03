/**
   benchmark-parallelism-cpp (c) by Vincenzo Palazzo vincenzopalazzodev@gmail.com
    benchmark-parallelism-cpp  is licensed under a
    Creative Commons Attribution-ShareAlike 4.0 International License.
    You should have received a copy of the license along with this
    work.  If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.
 */
#include "seq.h"
#include <experimental/filesystem>
#include <assert.h>

using namespace Benchmark;

using namespace std;
namespace fs = std::experimental::filesystem;

void SEQAlgorithms::run(std::string path) {
    assert(!path.empty());

    fs::path directoryBase(path);
    auto directoryDimension = 0;
    for(const auto& file : fs::directory_iterator(directoryBase)){
        auto err = std::error_code{};
        auto filesize = fs::file_size(file, err);
        if(filesize != -1){
            directoryDimension += filesize;
        }
    }
    std::cout << "Dimension directory " << directoryDimension / 1000000 << " GB\n";
}
