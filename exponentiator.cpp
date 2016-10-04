
#include "exponentiator.h"
#include <gmpxx.h>
#include "reverse.h"

namespace exponentiator
{
    std::string Exponentiator::run(unsigned long int val)
    {
        mpz_class retval;
        mpz_ui_pow_ui(retval.get_mpz_t(), val, m_modifier(val));
        return retval.get_str(10);
    }

    Exponentiator::Exponentiator(unsigned long (*modifier)(unsigned long)) {
        m_modifier = modifier;
    }
}

