#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include "config.h"
#include "spin.h"
#include "data_work.h"
// #include "output_data.h"      
#include <filesystem>


inline int get_random_spin()
{
	return (rand() % 2 == 0) ? 1 : -1; 
}

double get_energy_two_spin(const spin& sp_1, const spin& sp_2)
{
    return (-J*(sp_1.z * sp_2.z));
}

double get_energy_neighbors(spin const *const *const sp, int const& i, int const& j) noexcept
{
	double energy = 0;
	energy += get_energy_two_spin(sp[i][j], sp[(i - 1 + L) % L][j]);
	energy += get_energy_two_spin(sp[i][j], sp[(i + 1) % L][j]);
	energy += get_energy_two_spin(sp[i][j], sp[i][(j - 1 + L) % L]);
	energy += get_energy_two_spin(sp[i][j], sp[i][(j + 1) % L]);
	return energy;
}

double get_total_energy(spin** lattice) {
	double total_energy = 0;
	for (int i = 0; i < L; i++){
		for (int j = 0; j < L; j++){
		 total_energy += get_energy_neighbors(lattice, i, j);
		}
	}
	return total_energy / 2.0; 
}

void algoritm_Metropolis()
{
	std::vector<output_data> data_for_file(maxMCS);


	for (int step = 0; step < static_configuration; ++step)
	{

		    spin** lattice = new spin*[L];
    for (int i = 0; i < L; ++i) {
        lattice[i] = new spin[L];
    }



		//std::string filename = "data/energy_step_" + std::to_string(step) +".txt";
		//Data_work::init(filename);
	     
		for(int mcs = 0; mcs < maxMCS; mcs++){
			for (int n = 0; n < L * L; n++){
				int i = rand() % L;
				int j = rand() % L;
			
				spin selected_spin = lattice[i][j];
				double E1 = get_energy_neighbors(lattice, i, j);

				lattice[i][j].z = get_random_spin();
				double E2 = get_energy_neighbors(lattice, i, j);
				
				double dE = E2 - E1;
				double r = (double)rand() / RAND_MAX;
				
				if (dE > 0 && r >= exp(-dE / T)) {
					lattice[i][j] = selected_spin;
				}
			}	
			double total_E = get_total_energy(lattice);
			Data_work::update_output_data(lattice, data_for_file[mcs]);
		} 		
		//Data_work::close();

		    for (int i = 0; i < L; ++i) {
        delete[] lattice[i];
    }
    delete[] lattice;
	}


	Data_work::data_output(&data_for_file);


}

int main()
{
	srand(time(0));



    // for (int i = 0; i < L; ++i) {
    //     for (int j = 0; j < L; ++j) {
    //         lattice[i][j].z = +1;
    //     }
    // }

    // std::cout << "Test energy: " << get_energy_neighbors(lattice, 0, 0) << '\n';

    // for (int i = 0; i < L; ++i) {
    //     for (int j = 0; j < L; ++j) {
    //         lattice[i][j].z = get_random_spin();
    //     }
    // }

    std::cout << "Starting simulation..." << std::endl;
    algoritm_Metropolis();
    std::cout << "Done!" << std::endl;



	return 0;
}
