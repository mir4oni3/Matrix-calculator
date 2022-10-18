#include <iostream>
#include <vector>
using namespace std;

class Matrix {
	int width;
	int height;
	vector <double> elements;
public:
	Matrix(int width, int height) {
		this->width = width;
		this->height = height;
	}
	void setSize(int width, int height) {
		this->width = width;
		this->height = height;
	}
	int getWidth() { 
		return width;
	}
	int getHeight() {
		return height;
	}
	void addElement(double a) {
		elements.push_back(a);
	}
	double getElement(int index) {
		return elements.at(index);
	}
	void output() {
		for (int i = 0; i < width; i++) {
			cout << "|";
			for (int j = 0; j < height; j++) {
				cout << (this->getElement(width * i + j));
				if (j != (height - 1)) {
					cout << " ";
				}
			}
			cout << "|";
			cout << endl;
		}
	}
	void input() {
		double current;
		for (int i = 0; i < width * height; i++) {
			cout << "insert " << (i + 1) << " element of m1" << endl;
			cin >> current;
			this->addElement(current);
		}
	}

	void solve() {
		
	}

	Matrix multiply(Matrix m) {
		if (this->getWidth() != m.getHeight()) {
			cout << "can't multiply (columns of m1 != rows of m2)";
			return Matrix(0,0);
		}
		Matrix r = Matrix(height,m.getWidth());

		int j;
		double current;
		int j1;
		for (int k = 0; k < (this->getHeight())*this->getWidth(); k += this->getWidth()) {
			for (int j = 0; j < m.getWidth(); j++) {
				j1 = j;
				current = 0;
				for (int i = k; i < width+k; i++) {
					current += (this->getElement(i)) * m.getElement(j);
					j += m.getWidth();
				}
				j = j1;
				r.addElement(current);
			}
		}
		return r;
	}

	Matrix multiply(double num) {
		Matrix r = Matrix(this->getWidth(),this->getHeight());
		for (int i = 0; i < this->getWidth() * this->getHeight(); i++) {
			r.addElement(this->getElement(i)*num);
		}
		return r;
	}
	Matrix add(Matrix m) {
		if ((this->getWidth() != m.getWidth())||(this->getHeight()!=m.getHeight())) {
			cout << "matrices have to be same width and height" <<endl;
			return Matrix(0, 0);
		}
		Matrix r = Matrix(m.getWidth(), m.getHeight());
		for (int i = 0; i < m.getWidth() * m.getHeight(); i++) {
			r.addElement(this->getElement(i)+m.getElement(i));
		}
		return r;
	}
	Matrix subtract(Matrix m) {
		Matrix r = this->add(m.multiply(-1));
		return r;
	}
};

int main()
{
	cout << "operation(+,-,*): " << endl;
	char operation;
	cin >> operation;

	int mwidth, mheight;
	cout << "matrix 1 width and height: " << endl;
	cin >> mwidth >> mheight;
	Matrix m1 = Matrix(mwidth,mheight);
	m1.input();

	cout << "matrix 2 width and height: " << endl;
	cin >> mwidth >> mheight;
	Matrix m2 = Matrix(mwidth, mheight);
	m2.input();

	Matrix a = Matrix(0,0);
	switch (operation) {
	case '+':
		a = m1.add(m2);
		break;
	case '-':
		a = m1.subtract(m2);
		break;
	case '*':
		a = m1.multiply(m2);
		break;
	}
	a.output();
}