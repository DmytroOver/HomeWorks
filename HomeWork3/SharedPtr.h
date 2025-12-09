#pragma once

class WeakPtr;

struct ControlBlock
{
	size_t m_refCount = 1;
	size_t m_weakCount = 1;
};

class SharedPtr
{
	int* m_ptr = nullptr;
	ControlBlock* m_control = nullptr;
	void release();
	SharedPtr(const WeakPtr&);
public:
	SharedPtr(int* data = nullptr);
	SharedPtr(const SharedPtr&);
	SharedPtr(SharedPtr&&) = delete;
	SharedPtr& operator=(const SharedPtr&);
	SharedPtr& operator=(SharedPtr&&) = delete;
	~SharedPtr();

	bool isValid() const;
	operator bool() const;

	int& operator*() const;
	int* operator->() const;
	int* get() const;

	void reset(int* data = nullptr);

	size_t useCount() const;

	friend class WeakPtr;
};