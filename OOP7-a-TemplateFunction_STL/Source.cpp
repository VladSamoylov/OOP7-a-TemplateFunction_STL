#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\033[32m"
#define ANSI_COLOR_RED "\033[31m"

using namespace std;

template <typename T> void CheckData(T&, T&, T&);

class Vector3D {
private:
	vector<int> vector3d;

public:
	Vector3D() { this->vector3d.resize(3, 0); }
	template <class T> Vector3D(const T&, const T&, const T&);
	template <class T> void SetVector(const T&, const T&, const T&);
	void Show();
	template <typename T> bool Find(const T&);
	void Sort();
	Vector3D Subtraction(Vector3D&);
	void Addition(Vector3D&, Vector3D&);
	void LenghtVector();
	~Vector3D() { cout << "Clear by destructor" << endl; }
};

/**
 * @brief Параметричний шаблоний конструктор 
 * @tparam T Заповнювач типу даних
 * @param x Координата по х
 * @param y Координата по у
 * @param z Координата по z
*/
template <class T>
Vector3D::Vector3D(const T& x, const T& y, const T& z) {
	
	this->vector3d.push_back(static_cast<int>(x));
	this->vector3d.push_back(static_cast<int>(y));
	this->vector3d.push_back(static_cast<int>(z));
}

/**
 * @brief Шаблоний метод-сеттер внесення координат в вектор
*/
template <class T>
void Vector3D::SetVector(const T& x, const T& y, const T& z) {

	this->vector3d.clear();
	this->vector3d.push_back(static_cast<int>(x));
	this->vector3d.push_back(static_cast<int>(y));
	this->vector3d.push_back(static_cast<int>(z));
}

/**
 * @brief Метод, який відображає вектор
*/
void Vector3D::Show() {

	cout << "Output vector data by index: " << endl;
	for (int i = 0; i < this->vector3d.size(); i++) {
		cout << vector3d[i] << ' ';
	}cout << endl;
	cout << "Output vector data by iterator: " << endl;
	vector<int>::const_iterator it = this->vector3d.begin();
	while (it != this->vector3d.end()) {
		cout << *it << ' ';
		it++;
	}cout << endl;
}

/**
 * @brief Шаблоний метод, для пошуку елемента в векторі
 * @tparam T Заповнювач типу даних
 * @param x Елеммент для пошуку
 * @return true - елемент знайдено, інакше false
*/
template <typename T>
bool Vector3D::Find(const T& x) {

	vector<int>::const_iterator it = find(this->vector3d.begin(), this->vector3d.end(), x);
	if (it != this->vector3d.end()) return true;
	else return false;
}

void Vector3D::Sort() {

	sort(this->vector3d.begin(), this->vector3d.end());
}

/**
 * @brief Метод, який виконує складання двох векторів
 * @param obj1 Перший вектор
 * @param obj2 Другий вектор
*/
void Vector3D::Addition(Vector3D& obj1, Vector3D& obj2) {

	int i = 0;
	vector<int>::iterator it = this->vector3d.begin();
	while (it != this->vector3d.end()) {
		*it = obj1.vector3d[i] + obj2.vector3d[i];
		it++; i++;
	}
}

/**
 * @brief Метод, який виконує віднімання координат вектора obj1 від координат вектора, для якого викликається метод
 * @param obj1 Вектор, який потрібно відняти
 * @return Новий об'єкт Vector3D, який містить в собі результат віднімання
*/
Vector3D Vector3D::Subtraction(Vector3D& obj1) {
	
	Vector3D tmp;
	for (int i = 0; i < this->vector3d.size(); i++) {
		tmp.vector3d[i] = this->vector3d[i] - obj1.vector3d[i];
	}

	return tmp;
}

/**
 * @brief Метод, який обчислює довжинну вектора, для якого викликається метод
*/
void Vector3D::LenghtVector() {
	
	double lenght = 0;
	vector<int>::iterator it = this->vector3d.begin();
	while (it != vector3d.end()){
		lenght += pow(*it, 2);
	}
	lenght = sqrt(lenght);
	cout << "Lenght of vector - " << lenght << endl;
}

/**
 * @brief Шаблона функція, яка перевіряє коректне введення координат вектора
 * @param x Координата х
 * @param y Координата у
 * @param z Координата z
*/
template <typename T>
void CheckData(T& x, T& y, T& z) {

	constexpr auto max = numeric_limits<T>::max();
	constexpr auto min = numeric_limits<T>::min();
	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			if (x > max || x < min || y > max || y < min || z > max || z < min) {
				cout << "Output for a range of values for " << typeid(x).name() << "(" << min << " - " << max << ")" << endl;
				cout << "Enter vector coordinate - ";
				cout << "x y z: ";
				cin >> x >> y >> z;
			}
			else {
				cerr << "You enter wrong data! Please enter correct data: \n";
				cout << "Enter vector coordinate - ";
				cout << "x y z: ";
				cin >> x >> y >> z;
			}
			cin.ignore(666, '\n');
		}
		else break;
	}
}

int main() {
	
	int work = 1;
	char x, y, z;
	Vector3D a, b('s', 'm', '$'), c(true, false, true), d;


	while (work != 0) {
		cout << ANSI_COLOR_GREEN << "Vector a: \n" << ANSI_COLOR_RESET; a.Show();
		cout << "Find 'c' in vector a: " << a.Find('c') << endl;
		cout << "Find 0 in vector a: " << a.Find(0) << endl;
		cout << ANSI_COLOR_GREEN << "Vector b: \n" << ANSI_COLOR_RESET; b.Show();
		cout << ANSI_COLOR_GREEN << "Vector c: \n" << ANSI_COLOR_RESET; c.Show();
		cout << "Enter x / y / z: "; cin >> x >> y >> z; CheckData(x, y, z); d.SetVector(x, y, z);
		cout << ANSI_COLOR_GREEN << "Vector d: \n" << ANSI_COLOR_RESET; d.Show();
		cout << ANSI_COLOR_BLUE << "Sort Vector d: \n" << ANSI_COLOR_RESET; d.Sort(); d.Show();

		if (work) {
			cout << "\n------Retry? 1 - Yes / 0 - No------\n";
			cin >> work;
			CheckData(work, work, work);
		}
	}
	
	return 0;
}