#include "main.h"
#include "CRat0.h"
#include "CRat1.h"
#include "Autotest.h"
int NOD(int n, int nn)
{
	int n1 = abs(n);
	int n2 = abs(nn);
	int div;
	if (n1 == n2)  return n1;
	int d = n1 - n2;
	if (d < 0) {
		d = -d;  div = NOD(n1, d);
	}
	else
		div = NOD(n2, d);
	return div;
}


void parallel(int arr_size, size_t nn);

int main(void) {


	//const char fname[] = "1.txt";

	int one, two;
	cout << "Enter array size and number of numbers" << endl;

	cin >> one >> two;

	parallel(one, two);
	return 0;
	if (autotest()) {
		cout << "test pass" << endl;
	}
	else {
		cout << "test didn't pass";
	}


	int len;
	int I;
	fr* buff;
	const string infile_name = "1.txt";
	string line;
	string outfile;
	int size = 0;

	ifstream infile;
	infile.open(infile_name);
	while (getline(infile, line))
		size++;
	infile.close();
	CRat** arr = (CRat**)malloc(sizeof(CRat*) * size);
	if (arr == NULL) { perror("malloc"); return 993; }
	int i = 0;
	infile.open(infile_name);
	while (!infile.eof())
	{
		infile >> I;
		infile >> outfile;
		infile >> len;
		buff = (fr*)malloc(sizeof(fr) * len);

		for (int i = 0; i < len; i++) {
			infile >> buff[i].p;
			infile >> buff[i].q;
		}


		if (I == 0)
			arr[i++] = new CRat0(len, buff, outfile);

		else if (I == 1)
			arr[i++] = new CRat1(len, buff, outfile);

		free(buff);
	}

	for (int i = 0; i < size; i++) {
		arr[i]->output();
		free(arr[i]);
	}
	
	infile.close();

	return 0;
}