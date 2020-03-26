class Date
{
private:
	int day;
	int month;
	int year;
	char dayName[50];
public:
	void setDate(int day, int month, int year);
	void setDayName(char* name);
	void displayA() const; //dd/mm/yyyy
	void displayB() const;
	void displayC() const;
};