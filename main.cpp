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


void fill_random(std::vector<std::vector<int>>& lattice)
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

int sum_neighbors(const std::vector<std::vector<int>>& lattice, int i, int j) //Сделал граничные условия(периодические)
{
	int L = (int)lattice.size();
	int up     = lattice[(i - 1 + L) % L][j];
	int down   = lattice[(i + 1) % L][j];
	int left   = lattice[i][(j - 1 + L) % L];
	int right  = lattice[i][(j + 1) % L];

	return up + down + left + right;
}

void algoritm_Metropolis()
  {

	  for (int step = 0; step < static_configuration; ++step)
	  {

std::vector<std::vector<int>> lattice(L, std::vector<int>(L, 0));

fill_random(lattice);

		  for (int mcs = 0; mcs < maxMCS; ++mcs)
		  {


			  for (int n = 0; n < L*L; ++n)
			  {
					  i = rund(1,L);
					  j = rund(1,L);

					  spin = E1;
					  
					  E2 = lattice[i][j];

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
					  spin = lattice[i][j];	
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

