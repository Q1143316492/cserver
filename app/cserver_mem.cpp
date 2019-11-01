#ifndef _CSERVER_MEMERY_H_
#define _CSERVER_MEMERY_H_

#include "cserver_memery.h"

CMemeryPools::CMemeryPools()
{

}

CMemeryPools::~CMemeryPools()
{

}

// void* CMemeryPools::newMemery(int size, bool ismemset = false)
// {
// 	void *tmpData = (void*)new char[size];
//     if(ismemset) {
// 	    memset(tmpData, 0, size);
//     }
// 	return tmpData;
// }
	
// void CMemeryPools::deleteMemery(void *point)
// {
//     delete [] ((char*)point);
// }

#endif