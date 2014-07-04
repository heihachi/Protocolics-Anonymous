/*
encrypt.h
Function to encrypt data with a PGP public key

Copyright (c) 2013 Jason Lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __PGPENCRYPT__
#define __PGPENCRYPT__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <gmpxx.h>

#include "Hashes/Hashes.h"
#include "PKA/PKA.h"
#include "cfb.h"
#include "PGP.h"
#include "PKCS1.h"
#include "revoke.h"

Tag6 * find_encrypting_key(PGP & k);
std::vector <mpz_class> pka_encrypt(const uint8_t pka, mpz_class data, const std::vector <mpz_class> & pub);
std::vector <mpz_class> pka_encrypt(const uint8_t pka, const std::string & data, const std::vector <mpz_class> & pub);

// Encrypt data
PGP encrypt(const std::string & data, PGP & pub, bool hash = true, uint8_t sym_alg = 9);
#endif
