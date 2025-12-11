#include "WeakPtr.h"

WeakPtr::WeakPtr()
{}

WeakPtr::WeakPtr(const WeakPtr& other): m_ptr(other.m_ptr), m_control(other.m_control)
{
	if (m_control)
	{
		m_control->m_weakCount++;
	}
}

WeakPtr::WeakPtr(const SharedPtr& other) : m_ptr(other.m_ptr), m_control(other.m_control)
{
	if (m_control)
	{
		m_control->m_weakCount++;
	}
}

WeakPtr::WeakPtr(WeakPtr&& other) noexcept : m_ptr(other.m_ptr), m_control(other.m_control)
{
	other.m_ptr = nullptr;
	other.m_control = nullptr;
}

WeakPtr& WeakPtr::operator=(const WeakPtr& other)
{
	if (this == &other) return *this;
	release();
	m_ptr = other.m_ptr;
	m_control = other.m_control;
	if (m_control)
	{
		m_control->m_weakCount++;
	}
	return *this;
}

WeakPtr& WeakPtr::operator=(WeakPtr&& other) noexcept
{
	if (this == &other) return *this;
	release();
	m_ptr = other.m_ptr;
	m_control = other.m_control;
	other.m_ptr = nullptr;
	other.m_control = nullptr;
	return *this;
}

WeakPtr& WeakPtr::operator=(const SharedPtr& other)
{
	release();
	m_ptr = other.m_ptr;
	m_control = other.m_control;
	if (m_control)
	{
		m_control->m_weakCount++;
	}
	return *this;
}

WeakPtr::~WeakPtr()
{
	release();
}

void WeakPtr::release()
{
	if (m_control)
	{
		m_control->m_weakCount--;
	}
	m_ptr = nullptr;
	m_control = nullptr;
}

bool WeakPtr::expired() const
{
	return m_control ? m_control->m_refCount == 0 : true;
}

SharedPtr WeakPtr::lock() const
{
	if (expired())
		return SharedPtr();
	return SharedPtr(*this);
}

size_t WeakPtr::useCount() const
{
	return m_control ? m_control->m_refCount : 0;
}