#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include "config.h"
#include <data_work.cpp>

/*			Конфиг
const int  l = 16;
const double t = 4.5;
const int j = -1;
const int maxmcs = 10000;
const int static_configuration = 100;
*/

inline spin get_random_spin()
{
	spin rundom_spin;

	rundom_spin.z = rund_z();

	return rundom_spin;
}



void full_random(std::vector<std::vector<int>>& lattice)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution coin (0.5);

	for (int i = 0; i < (int)lattice.size(); i++)
	{
		for (int j = 0; j < (int)lattice[i].size(); j++)
		{
			lattice[i][j] = +1;			
		}
	}



}


double sum_neighbors(const std::vector<std::vector<int>>& lattice, int i, int j) //Сделал граничные условия(периодические)
{
	int L = (int)lattice.size();
	double energy = 0;
	// int up     = lattice[(i - 1 + L) % L][j];
	// int down   = lattice[(i + 1) % L][j];
	// int left   = lattice[i][(j - 1 + L) % L];
	// int right  = lattice[i][(j + 1) % L];
	energy += get_energy_two_spin(lattice[i][j], lattice[(i - 1 + L) % L][j]);
	energy += get_energy_two_spin(lattice[i][j], lattice[(i + 1) % L][j]);
	energy += get_energy_two_spin(lattice[i][j], lattice[i][(j - 1 + L) % L]);
	energy += get_energy_two_spin(lattice[i][j], lattice[i][(j + 1) % L]);
	return energy;
}

double get_energy_two_spin()
{



}


void algoritm_Metropolis()
  {

	  for (int step = 0; step < static_configuration; ++step)
	  {

std::vector<std::vector<int>> lattice(L, std::vector<int>(L, 0));

spin** lattice = new spin* [L];
	for (int i = 0; i < L; i++)
	{
		lattice[i] = new spin* [L]
		for (int j = 0; j < L; j++)
		{
			lattice[i][j] = new spin[L];
		}
	}



full_random(lattice);

		  for (int mcs = 0; mcs < maxMCS; ++mcs)
		  {


			  for (int n = 0; n < L*L; ++n)
			  {
					 i = rund(1,L);
					 j = rund(1,L);

					 const spin selected_spin = lattice[i][j];
					 const double E1 = get_energy_neighbors(lattice[i][j], i, j);

					 lattice[i][j] = get_random_spin();
					 const double E2 = get_energy_neighbors(lattice[i][j], i, j);

					  if (E1>E2)
					  {
					  	spin = lattice[i][j];
					  }
					  else
					  {
						  const double Z = exp(-(E2-E1)/T); 
						  rund = rund(0,1);

					  if (Z < rund)
					  {
					  	lattice[i][j] = selected_spin;	
					  }
					  }
			  }

		  Data_work::updata_output_data();

		  }	




	  }

  }

void print (std::vector<std::vector<int>> const lattice)
{
	for(int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			std::cout << lattice[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
int main()
{
	
	              /*инициализация спинов*/
	//fill_random(lattice);
	//print(lattice);

	//Тест граничных условий
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < L; ++j)
			lattice[i][j] = +1;

	std::cout << sum_neighbors(lattice, 0, 0) << '\n';   
	std::cout << sum_neighbors(lattice, 0, 5) << '\n';   
	std::cout << sum_neighbors(lattice, 8, 8) << '\n';   	

	return 0;
}

