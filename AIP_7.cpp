#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int ex_1();
float phi_t(float t);
float phi_x(float j, float k,float t);

int ex_2();
int side(int a, int b);
int P(int a, int b);
int S(int a, int b);

int ex_3();
int Moores_law(long long N0, long long N);
void date_calc(int& days, int& months, int& years);

int main()
{
	srand(time(0));
	//ex_1();
	//ex_2();
	ex_3();
}

//////////////////////////////////////////////////////////////////////////////////

int ex_1() {
	cout << "Ex 1" << endl;

	int M = -10, N = 20;
	float t, j = 3., k = 2.;
	
	t = float(M + rand() % N);
	cout << "t = " << t << endl;
	t = phi_t(t);
	cout << "phi(t) = " << t << endl;
	cout << "phi(x) = " << phi_x(j, k, t) << endl;

	return 0;
}

float phi_t(float t) {
	if (t < 0 or 10 <= t) t = pow(t, 2);
	if (3 < t and t < 5) t = sqrt(t);
	if (5 <= t and t < 10) t = exp(t);
	return t;
}

float phi_x(float j, float k, float t) {
	return pow(t, j / k);
}

/////////////////////////////////////////////////////////////////////////////////

int ex_2() {
	cout << endl << "Ex 2" << endl;

	int x1, x2, y1, y2, a, b, P1, S1;

	x1 = rand() % 10;
	x2 = rand() % 10;
	y1 = rand() % 10;
	y2 = rand() % 10;

	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y1 = " << y1 << endl; 
	cout << "y2 = " << y2 << endl;

	a = side(x1, x2);
	b = side(y1, y2);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	P1 = P(a, b);
	S1 = S(a, b);
	cout << "P = " << P1 << endl;
	cout << "S = " << S1 << endl;
	return 0;
}

int side(int a, int b) {
	int c;
	c = abs(a - b);
	return c;
}

int P(int a, int b) {
	int c;
	c = 2 * (a + b);
	return c;
}

int S(int a, int b) {
	int c;
	c = a * b;
	return c;
}

/////////////////////////////////////////////////////////////////////////////////

int ex_3() {
	long long N0 = 300e6 , N = 3e14;
	int days, months = 0, years = 0;

	days = Moores_law(N0, N);
	date_calc(days, months, years);
	cout << years << "y ";
	cout << months << "m ";
	cout << days << "d ";

	return 0;
}

int Moores_law(long long N0, long long N) 
{
	long long temp = N0, mod, differ, daily_gain;
	int time, doubling = 0;


	while (temp < N) {
		doubling += 730;
		mod = temp;
		temp *= 2;
	}

	time = doubling - 730; // Время до последнего полного удвоения
	differ = N - mod; // Сколько не хватило до 3*10^14
	daily_gain = mod / 30; // Дневной прирость в последнее 24 месяца
	time += differ / daily_gain; //Количетво дней до достижения 3*10^14
	return time;
}

void date_calc(int& days, int& months, int& years)
{
	years = days / (12 * 30);
	months = (days % (12 * 30)) / 30;
	days = (days % (12 * 30)) % 30;
}