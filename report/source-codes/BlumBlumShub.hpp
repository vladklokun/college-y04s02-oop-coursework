#include <iostream>
#include <random> // std::random_device

#include <gmp.h>
#include <gmpxx.h>

#include <inttypes.h>

#include "modulo.h"
#include "intpow.h"

class BlumBlumShub
{
	private:
		mpz_class m_seed;
		mpz_class m_xi, m_xi1; /* x_i, x_{i+1} */
		mpz_class m_modulo;
	public:
		BlumBlumShub(); // default class constructor
		~BlumBlumShub();
		mpz_class getSeed(void); // encapsulation to access seed value if needed
		int getRandBit(void);
		int getRandInt(void);
		void performIteration(void);
		uint16_t printModulo(void);
};
