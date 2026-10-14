/* user_settings_rsa_pub_dsa.h
 *
 * Copyright (C) 2006-2026 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

/* wolfCrypt only: RSA public-key operations (no RSA private key) plus DSA,
 * with SP math all and no ECC or DH.
 *
 * DSA still needs modular exponentiation with a secret exponent, prime
 * testing and the multi-init helper, which SP math would otherwise leave out
 * of an RSA public-only build. CI builds this config to keep that combination
 * linking and constant-time.
 *
 * Build and test:
 * cp ./examples/configs/user_settings_rsa_pub_dsa.h user_settings.h
 * ./configure --enable-usersettings --disable-examples
 * make
 * ./wolfcrypt/test/testwolfcrypt
 *
 * Add CPPFLAGS=-DSP_WORD_SIZE=32 on a 64-bit host to build the 32-bit SP code
 * (sp_c32.c) used on 32-bit targets such as RISC-V rv32im.
 */

#ifndef WOLFSSL_USER_SETTINGS_H
#define WOLFSSL_USER_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------- */
/* Platform */
/* ------------------------------------------------- */
#define WOLFCRYPT_ONLY /* No TLS, wolfCrypt only */
#define SINGLE_THREADED
#define NO_FILESYSTEM

/* ------------------------------------------------- */
/* Math */
/* ------------------------------------------------- */
#define WOLFSSL_SP_MATH_ALL
#define SP_INT_BITS 3072

/* ------------------------------------------------- */
/* RSA: public-key operations only */
/* ------------------------------------------------- */
#define WOLFSSL_HAVE_SP_RSA
#define WOLFSSL_RSA_PUBLIC_ONLY

/* ------------------------------------------------- */
/* DSA stays enabled (NO_DSA not defined); no DH or ECC */
/* ------------------------------------------------- */
#define NO_DH
#undef HAVE_ECC

/* ------------------------------------------------- */
/* Symmetric, hashing and RNG */
/* ------------------------------------------------- */
#define HAVE_HASHDRBG
#define HAVE_AES_CBC
#define WOLFSSL_AES_DIRECT

/* ------------------------------------------------- */
/* Disabled algorithms */
/* ------------------------------------------------- */
#define NO_MD5
#define NO_DES3
#define NO_RC4
#define NO_PWDBASED

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_USER_SETTINGS_H */
