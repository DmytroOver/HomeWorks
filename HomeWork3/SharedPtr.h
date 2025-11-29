class SharedPtr
{
	int* m_data = nullptr;
	size_t* m_count = nullptr;
	void release();
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
};