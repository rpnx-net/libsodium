#ifndef rubidium_scalarmult_curve25519_H
#define rubidium_scalarmult_curve25519_H

#include <cstddef>

#include "export.h"



#define rubidium_scalarmult_curve25519_BYTES 32U

size_t rubidium_scalarmult_curve25519_bytes(void);

#define rubidium_scalarmult_curve25519_SCALARBYTES 32U

size_t rubidium_scalarmult_curve25519_scalarbytes(void);

/*
 * NOTE: Do not use the result of this function directly for key exchange.
 *
 * Hash the result with the public keys in order to compute a shared
 * secret key: H(q || client_pk || server_pk)
 *
 * Or unless this is not an option, use the rubidium_kx() API instead.
 */

int rubidium_scalarmult_curve25519(unsigned char *q, const unsigned char *n,
                                 const unsigned char *p)
            __attribute__ ((warn_unused_result)) __attribute__ ((nonnull));


int rubidium_scalarmult_curve25519_base(unsigned char *q,
                                      const unsigned char *n)
            __attribute__ ((nonnull));



#endif
