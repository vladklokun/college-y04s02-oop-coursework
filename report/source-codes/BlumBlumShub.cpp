#ifndef BLUMBLUMSHUB_HPP
#define BLUMBLUMSHUB_HPP

#include "BlumBlumShub.hpp"

#endif

BlumBlumShub::BlumBlumShub()
{
	std::random_device rd;	
	gmp_randstate_t randState;
	gmp_randinit_mt(randState);
	gmp_randseed_ui(randState, rd());

	mpz_urandomb(m_seed.get_mpz_t(), randState, 1024);

	m_modulo = MODULO;
	m_xi = m_seed;

	gmp_randclear(randState);
}

BlumBlumShub::~BlumBlumShub()
{
}

mpz_class BlumBlumShub::getSeed(void)
{
	return m_seed;
}

void BlumBlumShub::performIteration(void)
{
	mpz_class two;
	two = 2;

	mpz_powm_sec(m_xi1.get_mpz_t(), m_xi.get_mpz_t(), two.get_mpz_t(), m_modulo.get_mpz_t());


	m_xi = m_xi1;

}

int BlumBlumShub::getRandBit(void)
{
	performIteration();
	return mpz_tstbit(m_xi1.get_mpz_t(),0);
}

int BlumBlumShub::getRandInt(void) /* essentially returns an 8-bit signed int */
{
	int res = 0;
	for (int i = 0; i < 8; ++i) {
		res += getRandBit() * intPow(2, i);
	}

	return res;
}

uint16_t BlumBlumShub::printModulo(void)
{
	std::cout << "N: " << m_modulo;
	
	return 0;
}

