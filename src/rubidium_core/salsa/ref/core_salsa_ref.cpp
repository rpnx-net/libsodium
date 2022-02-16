
#include <stdint.h>
#include <stdlib.h>

#include "rubidium_core_salsa20.h"
#include "rubidium_core_salsa2012.h"
#include "rubidium_core_salsa208.h"
#include "private/common.h"

static void
rubidium_core_salsa(unsigned char *out, const unsigned char *in,
                  const unsigned char *k, const unsigned char *c,
                  const int rounds)
{
    uint32_t x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14,
        x15;
    uint32_t j0, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14,
        j15;
    int i;

    j0  = x0  = 0x61707865;
    j5  = x5  = 0x3320646e;
    j10 = x10 = 0x79622d32;
    j15 = x15 = 0x6b206574;
    if (c != NULL) {
        j0  = x0  = load32_le(c + 0);
        j5  = x5  = load32_le(c + 4);
        j10 = x10 = load32_le(c + 8);
        j15 = x15 = load32_le(c + 12);
    }
    j1  = x1  = load32_le(k + 0);
    j2  = x2  = load32_le(k + 4);
    j3  = x3  = load32_le(k + 8);
    j4  = x4  = load32_le(k + 12);
    j11 = x11 = load32_le(k + 16);
    j12 = x12 = load32_le(k + 20);
    j13 = x13 = load32_le(k + 24);
    j14 = x14 = load32_le(k + 28);

    j6  = x6  = load32_le(in + 0);
    j7  = x7  = load32_le(in + 4);
    j8  = x8  = load32_le(in + 8);
    j9  = x9  = load32_le(in + 12);

    for (i = 0; i < rounds; i += 2) {
        x4  ^= std::rotl<std::uint32_t>(x0  + x12, 7);
        x8  ^= std::rotl<std::uint32_t>(x4  + x0, 9);
        x12 ^= std::rotl<std::uint32_t>(x8  + x4, 13);
        x0  ^= std::rotl<std::uint32_t>(x12 + x8, 18);
        x9  ^= std::rotl<std::uint32_t>(x5  + x1, 7);
        x13 ^= std::rotl<std::uint32_t>(x9  + x5, 9);
        x1  ^= std::rotl<std::uint32_t>(x13 + x9, 13);
        x5  ^= std::rotl<std::uint32_t>(x1  + x13, 18);
        x14 ^= std::rotl<std::uint32_t>(x10 + x6, 7);
        x2  ^= std::rotl<std::uint32_t>(x14 + x10, 9);
        x6  ^= std::rotl<std::uint32_t>(x2  + x14, 13);
        x10 ^= std::rotl<std::uint32_t>(x6  + x2, 18);
        x3  ^= std::rotl<std::uint32_t>(x15 + x11, 7);
        x7  ^= std::rotl<std::uint32_t>(x3  + x15, 9);
        x11 ^= std::rotl<std::uint32_t>(x7  + x3, 13);
        x15 ^= std::rotl<std::uint32_t>(x11 + x7, 18);
        x1  ^= std::rotl<std::uint32_t>(x0  + x3, 7);
        x2  ^= std::rotl<std::uint32_t>(x1  + x0, 9);
        x3  ^= std::rotl<std::uint32_t>(x2  + x1, 13);
        x0  ^= std::rotl<std::uint32_t>(x3  + x2, 18);
        x6  ^= std::rotl<std::uint32_t>(x5  + x4, 7);
        x7  ^= std::rotl<std::uint32_t>(x6  + x5, 9);
        x4  ^= std::rotl<std::uint32_t>(x7  + x6, 13);
        x5  ^= std::rotl<std::uint32_t>(x4  + x7, 18);
        x11 ^= std::rotl<std::uint32_t>(x10 + x9, 7);
        x8  ^= std::rotl<std::uint32_t>(x11 + x10, 9);
        x9  ^= std::rotl<std::uint32_t>(x8  + x11, 13);
        x10 ^= std::rotl<std::uint32_t>(x9  + x8, 18);
        x12 ^= std::rotl<std::uint32_t>(x15 + x14, 7);
        x13 ^= std::rotl<std::uint32_t>(x12 + x15, 9);
        x14 ^= std::rotl<std::uint32_t>(x13 + x12, 13);
        x15 ^= std::rotl<std::uint32_t>(x14 + x13, 18);
    }
    store32_le((out + 0), (x0 + j0));
    store32_le((out + 4), (x1 + j1));
    store32_le((out + 8), (x2 + j2));
    store32_le((out + 12), (x3 + j3));
    store32_le((out + 16), (x4 + j4));
    store32_le((out + 20), (x5 + j5));
    store32_le((out + 24), (x6 + j6));
    store32_le((out + 28), (x7 + j7));
    store32_le((out + 32), (x8 + j8));
    store32_le((out + 36), (x9 + j9));
    store32_le((out + 40), (x10 + j10));
    store32_le((out + 44), (x11 + j11));
    store32_le((out + 48), (x12 + j12));
    store32_le((out + 52), (x13 + j13));
    store32_le((out + 56), (x14 + j14));
    store32_le((out + 60), (x15 + j15));
}

int
rubidium_core_salsa20(unsigned char *out, const unsigned char *in,
                    const unsigned char *k, const unsigned char *c)
{
    rubidium_core_salsa(out, in, k, c, 20);
    return 0;
}

size_t
rubidium_core_salsa20_outputbytes(void)
{
    return rubidium_core_salsa20_OUTPUTBYTES;
}

size_t
rubidium_core_salsa20_inputbytes(void)
{
    return rubidium_core_salsa20_INPUTBYTES;
}

size_t
rubidium_core_salsa20_keybytes(void)
{
    return rubidium_core_salsa20_KEYBYTES;
}

size_t
rubidium_core_salsa20_constbytes(void)
{
    return rubidium_core_salsa20_CONSTBYTES;
}

#ifndef MINIMAL
/* LCOV_EXCL_START */
int
rubidium_core_salsa2012(unsigned char *out, const unsigned char *in,
                      const unsigned char *k, const unsigned char *c)
{
    rubidium_core_salsa(out, in, k, c, 12);
    return 0;
}

size_t
rubidium_core_salsa2012_outputbytes(void)
{
    return rubidium_core_salsa2012_OUTPUTBYTES;
}

size_t
rubidium_core_salsa2012_inputbytes(void)
{
    return rubidium_core_salsa2012_INPUTBYTES;
}

size_t
rubidium_core_salsa2012_keybytes(void)
{
    return rubidium_core_salsa2012_KEYBYTES;
}

size_t
rubidium_core_salsa2012_constbytes(void)
{
    return rubidium_core_salsa2012_CONSTBYTES;
}

int
rubidium_core_salsa208(unsigned char *out, const unsigned char *in,
                     const unsigned char *k, const unsigned char *c)
{
    rubidium_core_salsa(out, in, k, c, 8);
    return 0;
}

size_t
rubidium_core_salsa208_outputbytes(void)
{
    return rubidium_core_salsa208_OUTPUTBYTES;
}

size_t
rubidium_core_salsa208_inputbytes(void)
{
    return rubidium_core_salsa208_INPUTBYTES;
}

size_t
rubidium_core_salsa208_keybytes(void)
{
    return rubidium_core_salsa208_KEYBYTES;
}

size_t
rubidium_core_salsa208_constbytes(void)
{
    return rubidium_core_salsa208_CONSTBYTES;
}
/* LCOV_EXCL_END */
#endif
