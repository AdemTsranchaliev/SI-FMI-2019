

class Order
{
private:
	int id;
	char* name;
	char* surname;
	char* phoneNumber;
	char* addressToDelivery;
	char* populatedPlace;
	char* email;
	bool isConfirmed;

	ShoppingCart orderedProducts;
	User user;
public:

	Order();
	Order(int id,const char* name, const char* surname, const char* phone, const char* address, const char* populatedPlace, const char* email);
	Order(const Order& order);
	~Order();
	Order& operator=(const Order& order);


	void setId(int);
	int getId() const;
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
	void printDetail();
};