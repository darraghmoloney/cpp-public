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

	int *points = getThirdPoints(lengthA, lengthB, lengthC);

	std::cout << "1st co-ords: " << 0 << " " << 0 << "\n";
	
	std::cout << "2nd co-ords: " << lengthB << " " << 0 << "\n";

	std::cout << "3rd co-ords: ";
	displayVector(points);

	std::vector<int> triangleCoords {0, 0, lengthB, 0, points[0], points[1], 0, 0};

	for (auto i: triangleCoords) {
		std::cout << i << " ";
	}
	std::cout << "\n";

}

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
