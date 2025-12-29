#include "FileCounter.h"
#include <iostream>

CountSize& CountSize::operator+=(const CountSize& rhs)
{
	count += rhs.count;
	size += rhs.size;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const CountSize& countSize)
{
	os << countSize.count << " (" << countSize.size << " bytes)";
	return os;
}

FileCounter::FileCounter(std::initializer_list<std::string_view> keys)
{
	for (const auto& key : keys)
	{
		m_mapCount.emplace(key, (0, 0));
	}
}

void FileCounter::add(std::string_view key, size_t size)
{
	auto it = m_mapCount.find(key);
	if (it != m_mapCount.end())
	{
		it->second.count++;
		it->second.size += size;
	}
	else
	{
		m_otherCount.count++;
		m_otherCount.size += size;
	}
}

CountSize FileCounter::getCountSize(std::string_view key) const
{
	try
	{
		return m_mapCount.at(key);
	}
	catch (...)
	{
		return { 0, 0 };
	}
}

CountSize FileCounter::getCountSize(std::initializer_list<std::string_view> keys) const
{
	CountSize sum;
	for (const auto& key : keys)
	{
		try
		{
			sum += m_mapCount.at(key);
		}
		catch (...) {}
	}
	return sum;
}

CountSize FileCounter::getCountSize() const
{
	return m_otherCount;
}
