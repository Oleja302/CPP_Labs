#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

int main()
{
	Vector* v = new Vector(18);
	Matrix* m = new Matrix(9, 2);

	v->InitializationVector();

	++*(v);
	(*(v))++;
	--* (v);
	(*(v))--;

	m->ConvertingVectorToMatrix(*v);

	++*(m);
	(*(m))++;
	--* (m);
	(*(m))--;

	v->PrintVector();
	cout << endl;
	cout << "===================================================================" << endl;
	m->PrintMatrix();

	delete m;
	delete v;
}