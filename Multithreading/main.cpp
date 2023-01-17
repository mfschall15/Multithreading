// Multithreading.cpp : Defines the entry point for the application.
//

#include "Matrix_multiplication.h"

// set this to true to print matrix and confirm correct.
bool ignore = true;

int main()
{
	
	srand(time(NULL));

	//set create matrix objext with height and width. Generates with random values
	mat_math::Matrix mat1(1024, 1024);
	mat_math::Matrix mat2(1024, 1024);
	if (!ignore) {
		std::cout << "mat1 values: " << std::endl;
		mat1.print_values(ignore);
		std::cout << "mat2 values: " << std::endl;
		mat2.print_values(ignore);
	}
	
	// multiplies 
	mat_math::sing_thrd_multi(mat1, mat2);
	mat_math::mult_thrd_multi(mat1, mat2);

	

	
	return 0;
}
