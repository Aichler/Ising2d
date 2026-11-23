// #include "data_work.h"

// std::ofstream Data_work::outFile; 
// void Data_work::init(const std::string& filename) {
//     outFile.open(filename);
//     if (outFile.is_open()) {
//         outFile << "Step\tEnergy\n"; 
//     }
// }

void Data_work::norm_magnetization()
{



}

magnetization_output_data Data_work::culc_magmom(spin z_magnetizaion)
{


return data;
}


void Data_work::update_output_data(spin const *const *const sp, output_data &data_for_file) {

spin magnetizaion[N];

int N = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
        {
            magnetizaion[N].z += sp[i][j].z;
        }
        N ++;
    }
for (int i = 0; i < count; ++i)
{
    culc_magmom(magnetizaion[i]);
}


    



    // if (outFile.is_open()) {
    //     outFile << step << "\t" << energy << "\n";
    // }
}

void Data_work::data_output(std::vector<output_data>* data_for_file)
{
    // if (outFile.is_open()) {
    //     outFile << step << "\t" << energy << "\n";
    // }
}


// void Data_work::close() { 
//     if (outFile.is_open()) {
//         outFile.close();
//     }
// }
