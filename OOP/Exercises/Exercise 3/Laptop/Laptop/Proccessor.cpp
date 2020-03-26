#include <iostream>
#include "Proccessor.hpp"

using namespace std;



Proccessor::Proccessor()
{
	this->cacheMemory = 0;
	this->countCores = 0;
	this->frequency = 0;
}
Proccessor::Proccessor(double frequency, int countCores, int cacheMemory)
{
	this->cacheMemory = cacheMemory;
	this->countCores = countCores;
	this->frequency = frequency;
}

void Proccessor::setFrequency(int frequency)
{
	this->frequency = frequency;

}
double Proccessor::getFrequency()
{
	return this->frequency;
}

void Proccessor::setCountCores(int cores)
{
	this->countCores = countCores;

}
int Proccessor::getCountCores()
{
	return this->countCores;
}

void Proccessor::setCacheMemory(int cacheMemory)
{
	this->cacheMemory = cacheMemory;

}
int Proccessor::getCacheMemory()
{
	return this->cacheMemory;
}

void Proccessor::Print()
{
	cout << "Frequency: "<<this->frequency<<" Ghz"<<endl;
	cout << "Cores: " << this->countCores << endl;
	cout << "Cash memory: " << this->cacheMemory << " MB" << endl;


}