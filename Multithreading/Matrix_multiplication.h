// Matrix_multiplication.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <chrono>

extern bool ignore;



namespace mat_math {

	class Matrix {
	public:

		std::vector<std::vector<int>> values;
		std::vector<std::vector<int>> values_trans;

		Matrix() = default;

		Matrix(int N, int M) {
			height = N;
			width = M;
			std::vector<std::vector<int>> m_temp(height, std::vector<int>(width, 0));
			std::vector<std::vector<int>> m_temp_trans(width, std::vector<int>(height, 0));
			values = m_temp;
			values_trans = m_temp_trans;
			set_values();
		}
		/*
		getter to return matrix values
		*/
		std::vector<std::vector<int>> get_values();

		void set_values();


		void print_values(bool ignore);

		int get_width();

		int get_height();
		

		

		

	private:
		int height{ 1 };
		int width{ 1 };

	};


	void sing_thrd_multi(Matrix& mat1, Matrix& mat2);

	void mult_thrd_multi(Matrix& mat1, Matrix& mat2);



}



