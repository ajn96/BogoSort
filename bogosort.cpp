//testing bogosort

#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <atomic>

int bogoSort(std::vector<int> data, std::atomic_int & threadedCount);

int main()
{
	int numFind;
	int factorial;
	int average;
	std::atomic_int threadedCount;
	srand(time(NULL));
	std::vector<int> data;
	while (true)
	{
		factorial = 1;
		threadedCount = 0;
		data.clear();
		std::cout << "Enter the number you want to find the factorial of: ";
		std::cin >> numFind;
		for (int i = 0; i < numFind; i++)
		{
			data.push_back(i);
		}
		for (int i = 1; i <= numFind; i++)
		{
			factorial = factorial * i;
		}
		std::cout << "Factorial of " << numFind << ": " << factorial << '\n';
		std::cout << "Approximation from one sort: " << threadedCount << '\n';
		for (int i = 0; i < 2; i++)
		{
			std::thread t1(bogoSort, data, threadedCount);
			std::thread t2(bogoSort, data, threadedCount);
			std::thread t3(bogoSort, data, threadedCount);
			std::thread t4(bogoSort, data, threadedCount);

			t1.join();
			t2.join();
			t3.join();
			t4.join();
		}
		average = threadedCount / 10;
		std::cout << "Approximation from ten sorts: " << average << '\n';
		for (int i = 0; i < 90; i++)
		{
		}
		average = threadedCount / 100;
		std::cout << "Approximation from one hundred sorts: " << average << '\n';
	}
	return 0;
}

int bogoSort(std::vector<int> data, std::atomic_int & threadedCount)
{
	std::vector<int> indexValues;
	int randomIndex;
	int loopCount = 0;
	int randomValue;
	std::vector<int> sortedData;
	bool isSorted = false;

	while (!isSorted)
	{
		loopCount++;
		for (uint32_t i = 0; i < data.size(); i++)
		{
			indexValues.push_back(i);
		}

		for (uint32_t i = 0; i < data.size(); i++)
		{
			randomIndex = rand() % indexValues.size();
			randomValue = indexValues[randomIndex];
			indexValues.erase(indexValues.begin() + randomIndex);
			sortedData.push_back(data[randomValue]);
		}
		isSorted = true;
		for (uint32_t i = 1; i < data.size(); i++)
		{
			if (sortedData[i - 1] > sortedData[i])
			{
				isSorted = false;
			}
		}
		sortedData.clear();
	}
	return loopCount;
}