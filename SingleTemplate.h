#pragma once
#include<mutex>

#define DECLARE_SINGLEON(Obj) friend class SingleTemplate<Obj>  

template<class T>

class SingleTemplate
{	
	
public:
	static T* getInstance() {
		if (!instance) {
			std::unique_lock<std::mutex>lock(m_mutex);
			if (!instance) {
				instance = new T();
			}
		}
		return instance;
	};
	static void release() {
		std::unique_lock<std::mutex>lock(m_mutex);
		if (instance) {
			delete instance;
			instance = nullptr;
		}
	};
	
private:
	SingleTemplate() {};
	virtual ~SingleTemplate() {}

	static T* instance;
	static std::mutex  m_mutex;
};

template<class T>
T* SingleTemplate<T>::instance = nullptr;

template<class T>
std::mutex SingleTemplate<T>::m_mutex;