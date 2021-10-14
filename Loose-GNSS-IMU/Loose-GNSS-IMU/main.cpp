// Loose-GNSS-IMU.cpp : Traditional integration strategy for GNSS-IMU, loosely coupled.
// Author: Aaron Boda

#include "pch.h"
#include "Loosely.h"
#include <chrono>
#include <thread>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

// The program starts and ends inside main.
int main()
{
	struct timeval start, end;

	

	// *** Input/Output file path
	string filePathGNSS = "Input/GNSS.txt";
	string filePathIMU = "Input/IMU.txt";
	string filePathOUT = "Output/LOOSE-GNSS-IMU.txt";

	gettimeofday(&start, NULL);

	// *** Loosely-coupled integration of GNSS-IMU
	Loosely(filePathGNSS, filePathIMU, filePathOUT);

	gettimeofday(&end, NULL);

	double time_taken = end.tv_sec + end.tv_usec / 1e6 -
						start.tv_sec - start.tv_usec / 1e6; // in seconds
// *** Time elapsed
	printf("time program took %f seconds to execute\n", time_taken);

	

	return 0;
}

