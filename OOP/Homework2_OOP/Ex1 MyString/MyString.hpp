
class MyString {
private:
    char* content;
public:
    MyString();
    MyString(const char* input);

    MyString(const MyString& from);

    MyString& operator=(const MyString& from);

    friend std::ostream& operator<<(std::ostream& out, MyString& str);
    friend std::istream& operator>>(std::istream& in, MyString& str);

    ~MyString();

    void append(char to_append);
    void print();
};