/*
Input data should already be formatted and ready for hashing
*/

#ifndef __DSA__
#define __DSA__

#include <vector>
#include <iostream>

#include <gmpxx.h>

#include "../common/cryptomath.h"
#include "../common/includes.h"
#include "../RNG/RNG.h"
#include "../pgptime.h"

// Generate new set of parameters
std::vector <mpz_class> new_DSA_public(const uint32_t & L = 2048, const uint32_t & N = 256);

// Generate new keypair with parameters
std::vector <mpz_class> DSA_keygen(std::vector <mpz_class> & pub);

// Sign hash of data
std::vector <mpz_class> DSA_sign(const mpz_class & data, const std::vector <mpz_class> & pri, const std::vector <mpz_class> & pub, mpz_class k = 0);
std::vector <mpz_class> DSA_sign(const std::string & data, const std::vector <mpz_class> & pri, const std::vector <mpz_class> & pub, mpz_class k = 0);

// Verify signature on hash
bool DSA_verify(const mpz_class & data, const std::vector <mpz_class> & sig, const std::vector <mpz_class> & pub);
bool DSA_verify(const std::string & data, const std::vector <mpz_class> & sig, const std::vector <mpz_class> & pub);
#endif
