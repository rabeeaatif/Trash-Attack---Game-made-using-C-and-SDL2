#include "Object.hpp"

class Plant : public Object
{
protected:
    bool is_watered;
    int level;

public:
    Plant();
    ~Plant();
    void move();
};