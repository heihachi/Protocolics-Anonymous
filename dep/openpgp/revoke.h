/*
revoke.h
Functions to revoke PGP keys

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

#ifndef __REVOKE__
#define __REVOKE__

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <gmpxx.h>

#include "PGP.h"
#include "PKCS1.h"
#include "sign.h"
#include "verify.h"

bool check_revoked(const std::vector <Packet *> & packets, const std::string & keyid);
bool check_revoked(PGP & key, const std::string & keyid);

// main function to revoke a primary key
Tag2 * revoke_primary_key_cert(PGP & pri, const std::string & passphrase, const uint8_t code, const std::string & reason = "");
// packages certification into a key
PGP revoke_primary_key_cert_key(PGP & pri, const std::string & passphrase, const uint8_t code, const std::string & reason = "");

// main function to revoke a subkey
Tag2 * revoke_subkey_cert(PGP & pri, const std::string & passphrase, const uint8_t code, const std::string & reason = "");
// packages certification into a key
PGP revoke_subkey_cert_key(PGP & pri, const std::string & passphrase, const uint8_t code, const std::string & reason = "");

// 0x30
PGP revoke_uid(PGP & pub, PGP & pri, const std::string passphrase, const uint8_t code, const std::string & reason = "");

// Directly Revoke Something
PGP revoke_key(PGP & pri, const std::string & passphrase, const uint8_t code, const std::string & reason = "");
PGP revoke_subkey(PGP & pri, const std::string & passphrase, const uint8_t code, const std::string & reason = "");

// Revoke with certificate
PGP revoke_with_cert(PGP & pub, PGP & revoke);

#endif
