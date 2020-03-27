#pragma once
class Proccessor
{
private:
	double frequency;
	int countCores;
	int cacheMemory;
public:

	Proccessor();
	Proccessor(double frequency,int countCores,int cacheMemory);
	~Proccessor()=default;

	void setFrequency(int frequency);
	double getFrequency();

	void setCountCores(int cores);
	int getCountCores();

	void setCacheMemory(int cacheMemory);
	int getCacheMemory();

	void Print();

};

