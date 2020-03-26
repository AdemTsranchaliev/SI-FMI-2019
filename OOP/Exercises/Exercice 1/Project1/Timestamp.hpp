
class Timestamp
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Timestamp();
	void SetTimeBySeconds(int seconds);
	void Print();
	int ConvertToSeconds();
	void SumWith(const Timestamp& time);
};

