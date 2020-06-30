#include "AutoService.h"

bool AutoService::isThereCapacity(int problemSeriosity)
{
	if (this->points+points>10)
	{
		return false;
	}

	return true;
	
}

void AutoService::AddNewVechicle(Vechicle* vechicle)
{
	if (isThereCapacity(vechicle->getSeriousOfProblem()))
	{
		this->vechicles.push_back(vechicle);
	}
	else
	{
		std::cout << "There are no space for your car, try next time!"<<endl;
	}
}

Vechicle* AutoService::getVechicle(int position)
{
	if (this->vechicles.size()<10)
	{
		return this->vechicles[position];
	}
	else
	{
		cout << "Invalid index";
	}
}

int AutoService::getPointBySeriousOfProblem(int problemCode)
{
	if (problemCode==1)
	{
		return 1;
	}
	else if (problemCode==2)
	{
		return 3;
	}
	else if (problemCode==3)
	{
		return 5;
	}
	else
	{
		return -1;
	}
}
