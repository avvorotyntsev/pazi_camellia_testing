#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camellia.h"

#define KEYSIZE 128

int main()
{
  KEY_TABLE_TYPE round_keys;
  u8 inputKey[KEYSIZE / 8];
  int i;
  for(i = 0; i < KEYSIZE / 8; i++)
    inputKey[i] = rand();
    
  u8 data[16];
  memset(data, 0, sizeof(u8)*16);
  int round = Camellia_Ekeygen(KEYSIZE, inputKey, round_keys); // количество
  u8 out[16];
  int j;
  
  int files_count = round == 3 ? 22 : 34;
  FILE** files = malloc(sizeof(FILE*) * files_count);
    
  char filename[12]; //round_xx.bin

  for(i = 0; i < files_count; i++)
  {
    sprintf(filename, "round_%02d.bin", i);
    files[i] = fopen(filename, "ab");
  }
  
  for(i = 0; i < 32*1024*1024/16; i++)
  {
      Camellia_EncryptBlock(KEYSIZE, data, round_keys, out, files);
      ++data[15];
      j = 15;
      while(j > 0 && data[j] == 0)
        ++data[--j];
  }
  
  for(int i = 0; i < files_count; i++)
    fclose(files[i]);
    
  free(files);
  
  return 0;
}
