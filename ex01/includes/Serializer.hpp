#include <iostream>


typedef struct Data {
    std::string name;
    int         user_id;

}   Data;

class Serializer {
    private:
        Serializer();
        Serializer(Serializer &copy);
        ~Serializer();
    public:
        Serializer &operator=(const Serializer &Serializer);
        static __intptr_t serialize(Data* ptr);
        static Data *deserialize(__intptr_t raw);

};