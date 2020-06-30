#include <cstring>

template <class T>
class JSONArray {
private:
    JSONObject<T>* array;
    int size;
    int capacity;

    void resize();
public:
    JSONArray();
    JSONArray(const JSONArray& from);

    JSONArray& operator= (const JSONArray& from);

    ~JSONArray();

    JSONObject<T> operator[] (const int& pos) const;
    void insert(const char* key, T value);

    T get_value(const char* key) const;

    int get_size() const;
};
template <class T>
void JSONArray<T>::resize()
{
    this->capacity *= 2;
    JSONObject<T>* new_array = new JSONObject<T>[this->capacity];

    for (int i = 0; i < this->size; i++)
    {
        new_array[i] = this->array[i];
    }

    delete[] this->array;
    this->array = new_array;
}
template <class T>
JSONArray<T>::JSONArray()
{
    this->array = new JSONObject<T>[1];
    this->size = 0;
    this->capacity = 1;
}

template <class T>
JSONArray<T>::JSONArray(const JSONArray& from)
{
    this->array = new JSONObject<T>[from.capacity];
    this->size = from.size;
    this->capacity = from.capacity;

    for (int i = 0; i < this->size; i++)
    {
        this->array[i] = from.array[i];
    }
}

template <class T>
JSONArray<T>& JSONArray<T>::operator= (const JSONArray& from)
{
    if (this != &from)
    {
        delete[] this->array;

        this->array = new JSONObject<T>[from.capacity];
        this->size = from.size;
        this->capacity = from.capacity;

        for (int i = 0; i < this->size; i++)
        {
            this->array[i] = from.array[i];
        }
    }
    return *this;
}

template <class T>
JSONArray<T>::~JSONArray<T>()
{
    delete[] this->array;
}

template <class T>
JSONObject<T> JSONArray<T>::operator[] (const int& pos) const
{
    return this->array[pos];
}

template <class T>
void JSONArray<T>::insert(const char* key, T value)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }
    JSONObject<T>* temp = new JSONObject<T>();
    temp->set_key(key);
    temp->set_value(value);

    this->array[this->size] = *temp;
    this->size++;
}

template <class T>
T JSONArray<T>::get_value(const char* key) const
{
    for (int i = 0; i < this->size; i++)
    {
        if (strcmp(key, this->array[i].get_key()) == 0)
        {
            return this->array[i].get_value();
        }
    }
    std::cout << "key not found"; // Exception ?
    return T();
}

template <class T>
int JSONArray<T>::get_size() const
{
    return this->size;
}
