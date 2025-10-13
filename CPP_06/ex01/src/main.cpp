#include "../includes/Serializer.hpp"

int main()
{
    Data *d;
    d->index = 0;
    uintptr_t ptr = Serializer::serialize(d);
}
