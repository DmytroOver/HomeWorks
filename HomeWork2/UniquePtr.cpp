#include "UniquePtr.h"

UniquePtr::UniquePtr(int* data): m_data(data)
{}

UniquePtr::UniquePtr(int data): m_data(new int{data})
{}

UniquePtr::~UniquePtr()
{
	delete m_data;
}

bool UniquePtr::isValid() const
{
	return m_data != nullptr;
}

UniquePtr::operator bool() const
{
	return isValid();
}

int& UniquePtr::operator*() const
{
	return *m_data;
}

int* UniquePtr::operator->() const
{
	return m_data;
}

int* UniquePtr::get() const
{
	return m_data;
}

void UniquePtr::reset(int* data)
{
	if (data != m_data)
	{
		delete m_data;
		m_data = data;
	}
}

int* UniquePtr::release()
{
	int* tmp = m_data;
	m_data = nullptr;
	return tmp;
}