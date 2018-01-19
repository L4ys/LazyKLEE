#include <string.h>

unsigned char xkey[17] = { 0x6E, 0xC2, 0xE1, 0x2D, 0x05, 0xF8, 0x68, 0x71, 0xAF, 0x76, 0x68, 0xFD, 0xF8, 0x76, 0xA3, 0x82, 0x00 };
int seed = 0x1337;

int rand()
{
      seed = 214013 * seed + 0x269EC3;
      return (seed >> 16) & 0x7FFF;
}

unsigned int rol(unsigned char a1, char a2)
{
  return (a1 << a2) | ((unsigned int)a1 >> (8 - a2));
}

int ror(unsigned int a1, char a2)
{
  return (a1 >> a2) | (a1 << (32 - a2));
}

int main(int argc, char *argv[])
{
    unsigned char input[16];
    klee_make_symbolic(input, sizeof(input), "input");

    for ( int i = 0; i < 16; ++i )
        input[i] ^= xkey[i];

    int v6 = 0x12345678;
    for ( int i = 0; i < 13; ++i ) {
        input[i] = rol(input[i], 3);
        *(unsigned int*)&input[i] ^= v6;
		int v8 = ror(v6, 5);
		v6 = rand() % 13371337 ^ v8;
	}
    if ( !memcmp("0p3n5354m3...=.=", input, 16) )
		klee_assert(0);
    
    return 0;
}
