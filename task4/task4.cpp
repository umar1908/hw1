#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void sort(std::vector < int > & v)
{
	for (std::size_t i = 0; i < v.size() - 1; ++i)
	{
		for (std::size_t j = i + 1; j < v.size(); ++j)
		{
			if (v[i] > v[j])
			{
				std::swap(v[i], v[j]);
			}
		}
	}
}

int main()
{
	const auto size = 10000U;

	std::vector < int > v(size, 0);

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		v[i] = v.size() - i;
	}

	auto v_1 = v;
	auto v_2 = v;
	auto start =chrono::steady_clock::now();
	sort(v_1);
	auto stop= chrono::steady_clock::now();
	auto elapsed_1=chrono::duration_cast<chrono::milliseconds>(stop-start);
	start=chrono::steady_clock::now();
	std::sort(v_2.begin(), v_2.end());
	stop=chrono::steady_clock::now();
	auto elapsed_2=chrono::duration_cast<chrono::milliseconds>(stop-start);
	cout<<elapsed_1.count()<<endl<<elapsed_2.count()<<endl;
	// system("pause");

	return EXIT_SUCCESS;
}
