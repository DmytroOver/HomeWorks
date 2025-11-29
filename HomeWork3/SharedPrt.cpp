#include "SharedPtr.h"

SharedPtr::SharedPtr(int* data): m_data(data), m_count(nullptr)
{
	if (m_data)
	{
		m_count = new size_t(1);
	}
}

SharedPtr::SharedPtr(const SharedPtr& other): m_data(other.m_data), m_count(other.m_count)
{
	if (m_count)
	{
		++(*m_count);
	}
}

SharedPtr& SharedPtr::operator=(const SharedPtr& other)
{
	if (this == &other) return *this;
	release();
	m_data = other.m_data;
	m_count = other.m_count;
	if (m_count)
	{
		++(*m_count);
	}
	return *this;
}

SharedPtr::~SharedPtr()
{
	release();
}

void SharedPtr::release()
{
	if (m_count && --(*m_count) == 0)
	{
		delete m_data;
		delete m_count;
	}
	m_data = nullptr;
	m_count = nullptr;
}

bool SharedPtr::isValid() const
{
	return m_data != nullptr;
}

SharedPtr::operator bool() const
{
	return isValid();
}

int& SharedPtr::operator*() const
{
	return *m_data;
}

int* SharedPtr::operator->() const
{
	return m_data;
}

int* SharedPtr::get() const
{
	return m_data;
}

void SharedPtr::reset(int* data)
{
	if (data != m_data)
	{
		m_data = data;
		if (m_count)
		{
			--(*m_count);
		}
		m_count = new size_t(1);
	}
}

size_t SharedPtr::useCount() const
{
	return m_count ? *m_count : 0;
}
