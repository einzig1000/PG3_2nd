#pragma once

template <typename T1, typename T2>
class Compare
{
public:
	T1 a;
	T2 b;

	Compare(T1 first, T2 second) : a(first), b(second) {}

	auto Min();
	auto Max();

};

template<typename T1, typename T2>
inline auto Compare<T1, T2>::Min()
{
	return (a < b) ? a : b;
}

template<typename T1, typename T2>
inline auto Compare<T1, T2>::Max()
{
	return (a > b) ? a : b;
}