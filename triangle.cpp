/* This program takes in 3 inputs from the user
* which are line lengths of a polygon and tells
* the user if the line lengths can make a valid
* triangle shape or not.
*
* It then returns three co-ordinates to map
* the triangle shape, with the first point
* set to the origin, (0,0).
*/

#include <iostream>
#include <cmath>
#include <vector>


bool checkTriangle(int a, int b, int c);
void promptTriangle();
int* getThirdPoints(int lengthA, int lengthB, int lengthC);
void displayVector(int *vec);

bool checkTriangle(int a, int b, int c) {
	
	if ((a+b)>c && ((b+c)>a) && ((a+c)>b)) {
		return true;
	}
	return false;
}

void promptTriangle() {
	
	int lengthA{};
	std::cout << "Enter the length of line A: ";
	std::cin >> lengthA;
	std::cin.clear();

	int lengthB{};
	std::cout << "Enter the length of line B: ";
	std::cin >> lengthB;
	std::cin.clear();

	int lengthC{};
	std::cout << "Enter the length of line C: ";
	std::cin >> lengthC;
	std::cin.clear();

	bool isTriangle = checkTriangle(lengthA, lengthB, lengthC);

	if (isTriangle) {
		std::cout << lengthA << ", " << lengthB << " and "
			<< lengthC << " can make a triangle.\n";
	} else {
		std::cout << lengthA << " " << lengthB << " and "
			<< lengthC << " cannot make a triangle.\n";
	}
	//the third points must be calculated - first is origin,
	//second can be inferred from length
	int *points = getThirdPoints(lengthA, lengthB, lengthC);
	
	//setting the first point to (0,0) - arbitrary
	std::cout << "1st co-ords: " << 0 << " " << 0 << "\n";
	
	//the second point is set to a line along the x-axis, so
	//it is equal to the length of the line and zero (len, 0)
	std::cout << "2nd co-ords: " << lengthB << " " << 0 << "\n";

	std::cout << "3rd co-ords: ";
	displayVector(points);

	std::vector<int> triangleCoords {0, 0, lengthB, 0, points[0], points[1], 0, 0};

	for (auto i: triangleCoords) {
		std::cout << i << " ";
	}
	std::cout << "\n";

}

//returns an array, which is technically an int pointer
//in C++
int* getThirdPoints (int lengthA, int lengthB, int lengthC) {

	static int pointC[] {};	

	if (lengthA > 0) {
		pointC[1] = (lengthA*lengthA + lengthC*lengthC - lengthB*lengthB) / (2*lengthA);
		pointC[0] = sqrt(lengthC*lengthC - pointC[1]*pointC[1]);
	}
	
	return pointC;

}

void displayVector(int *vec) {
	for (int i{0}; i < 2; ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}


int main() {





	promptTriangle();







	return 0;
}
