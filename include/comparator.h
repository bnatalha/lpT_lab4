#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "header.h"

template <typename T>
int myCompare( const T &a, const T &b)
{
	if( a > b ) return 1;
	if( a < b ) return -1;
	return 0;
}

#endif