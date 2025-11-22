#pragma once

class UniquePtr
{
	int* m_data = nullptr;
public:
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr(UniquePtr&&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;
	UniquePtr&& operator=(UniquePtr&&) = delete;

	UniquePtr(int* data = nullptr);
	UniquePtr(int data);
	~UniquePtr();

	bool isValid() const;
	operator bool() const;

	int& operator*() const;
	int* operator->() const;
	int* get() const;

	void reset(int* data = nullptr);
	int* release();
};
