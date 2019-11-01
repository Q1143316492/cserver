#ifndef _CSERVER_MEMERY_H_
#define _CSERVER_MEMERY_H_

#include <bits/stdc++.h>

class CMemeryPools {
private:
    CMemeryPools();
public:
    ~CMemeryPools();
private:
    static CMemeryPools *m_instance;
    static std::mutex m_instance_mux;
public:
    static CMemeryPools* getInstance() {	
		if(m_instance == NULL) {
            std::unique_lock<std::mutex> uni_lok(m_instance_mux);
			if(m_instance == NULL) {					
				m_instance = new CMemeryPools();
			}
		}
		return m_instance;
	}

    void* newMemery(int memCount, bool ifmemset);
	
    void  deleteMemery(void *point);
    
};

#endif