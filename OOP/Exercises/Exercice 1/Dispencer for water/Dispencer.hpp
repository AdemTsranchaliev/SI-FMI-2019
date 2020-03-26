#pragma once
class Dispencer
{
private:
	double capacity;
	double quantity;
public:

	Dispencer(double capacity,double quantity);

	double getCapacity() const;
	double getQuantity() const;

	void FillWithWater(double waterToFill);
	void DrainWater(double waterToDrain);




};

