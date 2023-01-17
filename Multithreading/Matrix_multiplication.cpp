
#include "Matrix_multiplication.h"



std::vector<std::vector<int>> mat_math::Matrix::get_values()
{
	return values;
}

void mat_math::Matrix::set_values() {


	for (int i = 0; i < values.size(); i++) {
		for (int j = 0; j < values[i].size(); j++) {
			values[i][j] = (std::rand() % 9) + 1;
		}
	}
}



void mat_math::Matrix::print_values(bool ignore) {

	if (!ignore) {
		for (int i = 0; i < values.size(); i++) {
			for (int j = 0; j < values[i].size(); j++) {
				std::cout << values[i][j] << ",";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

int mat_math::Matrix::get_width()
{
	return width;
}

int mat_math::Matrix::get_height()
{
	return height;
}



void mat_math::sing_thrd_multi(Matrix& mat1, Matrix& mat2)
{

	if (mat1.get_width() != mat2.get_height())
	{
		std::cout << "Matrix Dimensions Invalid " << mat1.get_width() << " Not equal to " << mat2.get_height() << std::endl;
	}

	Matrix output(mat1.get_height(), mat2.get_width());

	auto start = std::chrono::high_resolution_clock::now();

	int M = mat1.get_height();
	int N = mat2.get_width();
	int K = mat1.get_width();

	int i, j, k, sum;

		for (i = 0; i < M; ++i) 
		{
			for (j = 0; j < N; ++j)
			{
				sum = 0;
				for (k = 0; k < K; ++k)
				{

					 sum += mat1.values[i][k] * mat2.values[k][j];

				}
				output.values[i][j] =  sum;
				
			}
		}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "millliseconds to multiply with one thread: " << duration.count() << std::endl;

	if (!ignore) {
		std::cout << "Matrix Product output is: " << std::endl;
		output.print_values(ignore);
	}

}

void mat_math::mult_thrd_multi(Matrix& mat1, Matrix& mat2)
{

	if (mat1.get_width() != mat2.get_height())
	{
		std::cout << "Matrix Dimensions Invalid " << mat1.get_width() << " Not equal to " << mat2.get_height() << std::endl;
	}

	Matrix output(mat1.get_height(), mat2.get_width());

	auto start = std::chrono::high_resolution_clock::now();

	int M = mat1.get_height();
	int N = mat2.get_width();
	int K = mat1.get_width();


	int i, j, k, sum;
	#pragma omp parallel for private(i,j,k, sum) shared(mat1,mat2,output)
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			sum = 0;
			for (k = 0; k < K; ++k)
			{

				sum += mat1.values[i][k] * mat2.values[k][j];

			}
			output.values[i][j] = sum;

		}
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "millliseconds to multiply with " << omp_get_max_threads() << " one thread : " << duration.count() << std::endl;

	if (!ignore) {
		std::cout << "Matrix Product output is: " << std::endl;
		output.print_values(ignore);
	}
}




