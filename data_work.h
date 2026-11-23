#include <fstream>
#include <string>

#include "./output_data.h"

class Data_work {
// private:
//     static std::ofstream outFile;
public:
    //static void init(const std::string& filename);
    static void update_output_data(spin const *const *const sp, output_data &data);
    static void data_output(std::vector<output_data>* data_for_file);
    static void close(); 

};
 #include "./data_work.cpp"
