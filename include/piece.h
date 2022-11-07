#pragma once

#include<iostream>
#include<stdint.h>
#define MaxAttributeNumber 100
#define PieceSize (sizeof(int64_t)*(1+MaxAttributeNumber))
typedef struct Piece {
	int64_t lineNum;
	int64_t arrtibute[MaxAttributeNumber];
}Piece;
