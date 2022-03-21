#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int table[7][9] =  { { 1,0,0,1,0,1,1,0,1 },{ 1,0,0,0,1,0,1,0,1 },{ 0,1,0,0,0,1,1,0,0 },{ 0,1,1,0,1,0,0,1,0 },{ 1,0,1,1,1,0,0,0,0 },{ 1,0,0,0,0,1,0,1,0 },{ 0,0,1,1,0,0,0,0,1 } };
int a[7] = { 3,1,2,3,2,2,1 };
bool funct(int *k, int n) {
	int sum[9];
	int rez = 0;
	bool t;
	int price = 0;
	for (int j = 0; j < 9; ++j) {
		sum[j] = 0;
	}
	for (int j = 0; j < 9; ++j) {
		for (int i = 0; i < n; ++i) {
			sum[j] += table[k[i] - 1][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		price += a[k[i] - 1];
	}
	for (int j = 0; j < 9; ++j) {
		if (sum[j] > 0) {
			rez++;
		}
	}
	if (rez == 9) {
		t = true;
		cout << "+";
		cout << price << endl;
	}
	else {
		t = false;
		cout << "-" << endl;
	}
	return t;



}

bool funct2(int *add, int p) {
	if (p <= 2) {
		return false;
	}
	add[p - 2] = add[p - 1];
	int sum[9];
	int rez = 0;
	bool t;
	int price = 0;
	for (int j = 0; j < 9; ++j) {
		sum[j] = 0;
	}
	for (int j = 0; j < 9; ++j) {
		for (int i = 0; i < p - 1; ++i) {
			sum[j] += table[add[i] - 1][j];
		}
	}
	for (int i = 0; i < p - 1; ++i) {
		price += a[add[i] - 1];
	}
	for (int j = 0; j < 9; ++j) {
		if (sum[j] > 0) {
			rez++;
		}
	}
	for (int i = 0; i < p - 1; ++i) {
		if (add[i] == 1) {
			cout << "A";
		}
		else {
			if (add[i] == 2) {
				cout << "B";
			}
			else {
				if (add[i] == 3) {
					cout << "C";
				}
				else {
					if (add[i] == 4) {
						cout << "D";
					}
					else {
						if (add[i] == 5) {
							cout << "E";
						}
						else {
							if (add[i] == 6) {
								cout << "F";
							}
							else {
								if (add[i] == 7) {
									cout << "G";
								}
							}
						}
					}
				}
			}
		}
	}
	if (rez == 9) {
		t = true;
		cout << "+";
		cout << price;
		cout << endl;
	}
	else {
		cout << "-";
		cout << endl;
		t = false;
	}
	return t;
}



int main(void)

{
	setlocale(LC_ALL, "");
	for (int i = 0; i < 7; i++)
	{
		cout << (char)(-64 + i)<<" ";
		for  (int j = 0; j < 7;j++)
		{
			cout << table[i][j]<<" ";
		}
		cout <<" "<< a[i];
		cout << endl;
	}
	int y = 1;
	int *k;
	int x = 1;
	k = new int[7];
	for (int i = 0; i < 7; i++) {
		k[i] = i + 1;
	}
	while (1) {
		if (((k[x - 1] > 7) && (k[x - 2] >= 7)) || ((k[x - 1] >= 7) && (k[x - 2] >= 7))) {
			y++;
			for (int i = 0; i < 7; i++) {
				k[i] = i + y;
			}
			x = 1;
		}
		else {
			for (int i = 0; i < x; ++i) {
				if (k[i] == 1) {
					cout << "A";
				}
				else {
					if (k[i] == 2) {
						cout << "B";
					}
					else {
						if (k[i] == 3) {
							cout << "C";
						}
						else {
							if (k[i] == 4) {
								cout << "D";
							}
							else {
								if (k[i] == 5) {
									cout << "E";
								}
								else {
									if (k[i] == 6) {
										cout << "F";
									}
									else {
										if (k[i] == 7) {
											cout << "G";
										}
									}
								}
							}
						}
					}
				}
			}
			if (k[0] == 7) {
				break;
			}
			if (funct(k, x)) {
				int *add;
				int l = x;
				add = new int[7];

				for (int i = 0; i < 7; ++i) {
					add[i] = k[i];
				}
				while (1) {
					if (funct2(add, l)) {
						l--;
					}
					else {
						break;
					}
				}
				if (k[x - 1] < 7) {
					k[x - 1]++;
					if (k[x] < 7) {
						k[x]++;
					}
				}
				else {
					y++;
					for (int i = 0; i < 7; i++) {
						k[i] = i + y;
					}
					x = 1;
				}
			}
			else {
				x++;
			}


		}
	}
	return 0;
}

