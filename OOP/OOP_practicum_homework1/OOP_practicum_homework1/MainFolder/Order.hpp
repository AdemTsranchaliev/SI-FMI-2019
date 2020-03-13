
class Order
{
private:
	char name[50];
	char surname[50];
	char phoneNumber[15];
	char addressToDelivery[200];
	char populatedPlace[100];
	char email[100];
public:

	Order();
	Order(char* name,char* surname,char* phone,char* address,char* populatedPlace,char* email);

	void setName(char*);
	char* getName();
	void setSurname();
	char* getSurname();
	void setPhoneNumber();
	char* getPhoneNumber();
	void setAddressToDelivery();
	char* getAddressToDelivery();
	void setPopulatedPlace();
	char* getPopulatedPlace();
	void setEmail();
	char* getEmail();


};