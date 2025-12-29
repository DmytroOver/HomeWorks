#pragma once

#include <map>
#include <string_view>

struct CountSize {
	size_t count = 0;
	size_t size = 0;
	CountSize& operator+=(const CountSize& rhs);

	friend std::ostream& operator<<(std::ostream& os, const CountSize& countSize);
};

class FileCounter {
	std::map<std::string_view, CountSize> m_mapCount;
	CountSize m_otherCount;

public:
	FileCounter() = default;
	FileCounter(std::initializer_list<std::string_view> keys);
	void add(std::string_view key, size_t size);
	CountSize getCountSize(std::string_view key) const;
	CountSize getCountSize(std::initializer_list<std::string_view> keys) const;
	CountSize getCountSize() const;
};