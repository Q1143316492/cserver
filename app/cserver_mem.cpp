#include "cserver_memery.h"

CMemeryPools* CMemeryPools::m_instance = nullptr;

std::mutex CMemeryPools::m_instance_mux;

CMemeryPools::CMemeryPools()
{

}

CMemeryPools::~CMemeryPools()
{

}

void* CMemeryPools::newMemery(int size, bool ismemset = false)
{
	void *tmpData = (void*)new char[size];
    if(ismemset) {
	    memset(tmpData, 0, size);
    }
	return tmpData;
}
	
void CMemeryPools::deleteMemery(void *point)
{
    delete [] ((char*)point);
}
