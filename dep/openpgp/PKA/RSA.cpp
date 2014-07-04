#include "RSA.h"
std::vector <mpz_class> RSA_keygen(const unsigned int & bits){
    BBS((mpz_class) (int) now()); // seed just in case not seeded

	mpz_class p = 3, q = 3;
	while (p == q){
	    p.set_str(BBS().rand(bits), 2);
	    q.set_str(BBS().rand(bits), 2);
        mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
        mpz_nextprime(q.get_mpz_t(), q.get_mpz_t());
    }

	mpz_class n = p * q;
	mpz_class tot = (p - 1) * (q - 1);
	mpz_class e(BBS().rand(bits), 2);
	e += ((e & 1) == 0);
	mpz_class gcd = 0;
	while (gcd != 1){
        e += 2;
        mpz_gcd(gcd.get_mpz_t(), tot.get_mpz_t(), e.get_mpz_t());
    }
    mpz_class d;
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(), tot.get_mpz_t());
	return {e, n, d}; // split this into {e, n} and {d}
}

mpz_class RSA_encrypt(mpz_class & data, const std::vector <mpz_class> & pub){
    mpz_powm_sec(data.get_mpz_t(), data.get_mpz_t(), pub[1].get_mpz_t(), pub[0].get_mpz_t());
    return data;
}

mpz_class RSA_encrypt(const std::string & data, const std::vector <mpz_class> & pub){
    mpz_class out;
    mpz_powm_sec(out.get_mpz_t(), mpz_class(hexlify(data), 16).get_mpz_t(), pub[1].get_mpz_t(), pub[0].get_mpz_t());
    return out;
}

mpz_class RSA_decrypt(mpz_class & data, const std::vector <mpz_class> & pri, const std::vector <mpz_class> & pub){
    mpz_powm_sec(data.get_mpz_t(), data.get_mpz_t(), pri[0].get_mpz_t(), pub[0].get_mpz_t());
    return data;
}

mpz_class RSA_sign(mpz_class & data, const std::vector <mpz_class> & pri, const std::vector <mpz_class> & pub){
    return RSA_decrypt(data, pri, pub);
}

mpz_class RSA_sign(const std::string & data, const std::vector <mpz_class> & pri, const std::vector <mpz_class> & pub){
    mpz_class d(hexlify(data), 16);
    return RSA_decrypt(d, pri, pub);
}

bool RSA_verify(mpz_class & data, const std::vector <mpz_class> & signature, const std::vector <mpz_class> & pub){
    mpz_class in = signature[0];
    return (RSA_encrypt(in, pub) == data);
}

bool RSA_verify(const std::string & data, const std::vector <mpz_class> & signature, const std::vector <mpz_class> & pub){
    mpz_class in(hexlify(data), 16);
    return RSA_verify(in, signature, pub);
}
