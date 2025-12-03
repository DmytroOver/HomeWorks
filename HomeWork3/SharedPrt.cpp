#include "SharedPtr.h"
#include "WeakPtr.h"

SharedPtr::SharedPtr(int* data): m_ptr(data), m_control(nullptr)
{
	if (m_ptr)
	{
		m_control = new ControlBlock();
	}
}

SharedPtr::SharedPtr(const SharedPtr& other): m_ptr(other.m_ptr), m_control(other.m_control)
{
	if (m_control)
	{
		m_control->m_refCount++;
	}
}

SharedPtr& SharedPtr::operator=(const SharedPtr& other)
{
	if (this == &other) return *this;
	release();
	m_ptr = other.m_ptr;
	m_control = other.m_control;
	if (m_control)
	{
		m_control->m_refCount++;
	}
	return *this;
}

SharedPtr::~SharedPtr()
{
	release();
}

void SharedPtr::release()
{
	if (m_control)
	{
		m_control->m_refCount--;
		if (m_control->m_refCount == 0)
		{
			m_control->m_weakCount--;
			delete m_ptr;
		}
		if (m_control->m_weakCount == 0)
		{
			delete m_control;
		}
	}
	m_ptr = nullptr;
	m_control = nullptr;
}

bool SharedPtr::isValid() const
{
	return m_ptr != nullptr;
}

SharedPtr::operator bool() const
{
	return isValid();
}

int& SharedPtr::operator*() const
{
	return *m_ptr;
}

int* SharedPtr::operator->() const
{
	return m_ptr;
}

int* SharedPtr::get() const
{
	return m_ptr;
}

void SharedPtr::reset(int* data)
{
	if (data != m_ptr)
	{
		m_ptr = data;
		if (m_control)
		{
			m_control->m_refCount--;
		}
		m_control = new ControlBlock();
	}
}

size_t SharedPtr::useCount() const
{
	return m_control ? m_control->m_refCount : 0;
}

SharedPtr::SharedPtr(const WeakPtr& other) : m_ptr(other.m_ptr), m_control(other.m_control)
{
	if (m_control)
	{
		m_control->m_refCount++;
	}
}
