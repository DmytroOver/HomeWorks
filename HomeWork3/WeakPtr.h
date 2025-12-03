#pragma once
#include "SharedPtr.h"

class WeakPtr
{
	int* m_ptr = nullptr;
	ControlBlock* m_control = nullptr;
	void release();
public:
	WeakPtr();
	WeakPtr(const WeakPtr&);
	WeakPtr(const SharedPtr&);
	WeakPtr(WeakPtr&&) = delete;
	WeakPtr& operator=(const WeakPtr&);
	WeakPtr& operator=(const SharedPtr&);
	WeakPtr& operator=(WeakPtr&&) = delete;
	~WeakPtr();

	bool expired() const;
	SharedPtr lock() const;
	size_t useCount() const;

	friend class SharedPtr;
};