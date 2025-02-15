#ifndef rubidium_hash_H
#define rubidium_hash_H

/*
 * WARNING: Unless you absolutely need to use SHA512 for interoperability,
 * purposes, you might want to consider rubidium_generichash() instead.
 * Unlike SHA512, rubidium_generichash() is not vulnerable to length
 * extension attacks.
 */

#include <cstddef>

#include "rubidium_hash_sha512.h"
#include "export.h"



#define rubidium_hash_BYTES rubidium_hash_sha512_BYTES

size_t rubidium_hash_bytes(void);


int rubidium_hash(unsigned char *out, const unsigned char *in,
                std::size_t inlen) __attribute__ ((nonnull(1)));

#define rubidium_hash_PRIMITIVE "sha512"

const char *rubidium_hash_primitive(void)
            __attribute__ ((warn_unused_result));



#endif
