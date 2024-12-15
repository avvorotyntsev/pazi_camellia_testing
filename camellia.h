#ifndef OSSL_CRYPTO_CAMELLIA_CMLL_LOCAL_H
# define OSSL_CRYPTO_CAMELLIA_CMLL_LOCAL_H

#include <stdio.h>

#  define CAMELLIA_TABLE_BYTE_LEN 272
#  define CAMELLIA_TABLE_WORD_LEN (CAMELLIA_TABLE_BYTE_LEN / 4)

typedef unsigned int KEY_TABLE_TYPE[CAMELLIA_TABLE_WORD_LEN];

typedef unsigned int u32;
typedef unsigned char u8;

int Camellia_Ekeygen(int keyBitLength, const u8 *rawKey,
                     KEY_TABLE_TYPE keyTable);
void Camellia_EncryptBlock_Rounds(int grandRounds, const u8 plaintext[],
                                  const KEY_TABLE_TYPE keyTable,
                                  u8 ciphertext[], FILE** files);
void Camellia_EncryptBlock(int keyBitLength, const u8 plaintext[],
                           const KEY_TABLE_TYPE keyTable, u8 ciphertext[], FILE** files);
                           
#endif

