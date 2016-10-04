#ifndef EXPONENTIATOR_EXPONENTIATOR_H
#define EXPONENTIATOR_EXPONENTIATOR_H

#include <string>

namespace exponentiator
{
    class Exponentiator
    {
    public:
        Exponentiator(unsigned long int (*)(unsigned long int));
        std::string run(unsigned long int val);
    private:
        unsigned long int (*m_modifier)(unsigned long int);
    };
}

#endif //EXPONENTIATOR_EXPONENTIATOR_H
