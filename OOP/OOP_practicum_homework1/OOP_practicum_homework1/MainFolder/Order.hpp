
class Order
{
private:
	char* name;
	char* surname;
	char* phoneNumber;
	char* addressToDelivery;
	char* populatedPlace;
	char* email;
public:

	Order();
	Order(const char* name, const char* surname, const char* phone, const char* address, const char* populatedPlace, const char* email);
	Order(const Order& order);
	~Order();
	Order& operator=(const Order& order);
	bool operator==(const Order& order);

	void setName(char*);
	char* getName() const;
	void setSurname(char*);
	char* getSurname() const;
	void setPhoneNumber(char*);
	char* getPhoneNumber() const;
	void setAddressToDelivery(char*);
	char* getAddressToDelivery() const;
	void setPopulatedPlace(char*);
	char* getPopulatedPlace() const;
	void setEmail(char*);
	char* getEmail() const;

	void print();
};