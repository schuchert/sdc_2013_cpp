#ifndef SLIMUTILS_H
#define SLIMUTILS_H
char * CSlim_BuyBuf(char const*, int);
char * CSlim_BuyString(char const*);
int CSlim_IsCharacter(unsigned char const* byte);

typedef struct MapStringInt
{
	const char* string;
	int n;
} MapStringInt;

int CSlim_MapToIntFrom(MapStringInt*, const char*);
const char* CSlim_MapToStringFrom(MapStringInt*, int);
#endif
