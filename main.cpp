/*
Implement the X matrix type which contains integers. 
These are square matrices that can contain nonzero entries only in their two diagonals. 
Don't store the zero entries. Store only the entries that can be nonzero in a sequence. 
Implement as methods: 
1-getting the entry located at index (i, j), 
2-adding and multiplying two matrices, 
3-and printing the matrix (in a square shape).*/

#include <iostream>
#include <vector>

using namespace std;

int num = -1;
char choice;
int maxRow;
int maxCol;

class Matrix
{
private:
	vector<vector<int>> my_matrix;
	vector<vector<int>> my_matrix2;

public:
	
	void entryMatrix(int row, int col)
	{

		my_matrix.resize(maxRow, vector<int>(maxCol));
		my_matrix2.resize(maxRow, vector<int>(maxCol));

		cout << "which matrix do you want to enter to? 1/2"<<endl;
		cin >> choice;

		if (choice == '1')
		{
			cout << "matrix1[" << col << "]" << "[" << row << "] = ";

			cin >> num;
			my_matrix[row][col] = num;
		}

		if (choice == '2')
		{
			cout << "matrix2[" << col << "]" << "[" << row << "] = ";
			cin >> num;
			my_matrix2[row][col] = num;

		}
	}

	vector<vector<int>> addMatrix()
	{
		vector<vector<int>> m3;
		m3.resize(maxRow, vector<int>(maxCol));

		for (int i = 0; i < my_matrix.size(); i++)
		{
			for (int j = 0; j < my_matrix2.size(); j++)
			{
				m3[i][j] = my_matrix[i][j] + my_matrix2[i][j];
			}
		}
		return m3;
	}

	vector<vector<int>> multiplyMatrix()
	{
		vector<vector<int>> m3;
		m3.resize(maxRow, vector<int>(maxCol));

		for (int i = 0; i < my_matrix.size(); i++)
		{
			for (int j = 0; j < my_matrix2.size(); j++)
			{
				m3[i][j] = my_matrix[i][j] * my_matrix2[i][j];
			}
		}
		return m3;
	}

	void printMatrix()
	{
		cout << "which matrix do you want to print? (1/2): ";
		cin >> choice;

		if (choice == '1')
		{
			for (int i = 0; i < my_matrix.size(); i++)
			{
				for (int j = 0; j < my_matrix[i].size(); j++)
				{
					cout << my_matrix[i][j] << " ";
				}
				cout << endl;
			}
		}

		if (choice == '2')
		{
			for (int i = 0; i < my_matrix2.size(); i++)
			{
				for (int j = 0; j < my_matrix2.size(); j++)
				{
					cout << my_matrix2[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

};

int main()
{	
	Matrix my_matrix;

	cout << "welcome to matrix game" << endl;

	cout << "how many rows do you want your matrix to be? :";
	cin >> maxRow;

	cout << "how many columns do you want your matrix to be? :";
	cin >> maxCol;

	cout << "please make a choice" << endl;
	
	do
	{
		cout << "e - enter element to matrix" << endl;
		cout << "m - multiply element to matrix" << endl;
		cout << "a - add both matrix" << endl;
		cout << "p - print matrix" << endl;
		cout << "q - quit" << endl;

		cout << endl;

		cout << "choice: ";
		cin >> choice;

		cout << endl;

		if (choice == 'e')
		{
			int row, col, val;

			cout << "which row: ";
			cin >> row;
			if (row > maxRow) cout << "invalid input - out of bound" << endl;

			cout << "which column: ";
			cin >> col;
			if (col > maxCol) cout << "invalid input - out of bound" << endl;

			my_matrix.entryMatrix(row-1, col-1);

		}

		if (choice == 'm')
		{
			vector<vector<int>> result = my_matrix.multiplyMatrix();

			for (int i = 0; i < result.size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					cout << result[i][j] << " ";
				}
				cout << endl;
			}
		}

		if (choice == 'a')
		{
			vector<vector<int>> result = my_matrix.addMatrix();

			for (int i = 0; i < result.size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					cout << result[i][j] << " ";
				}
				cout << endl;
			}
		}

		if (choice == 'p')
			my_matrix.printMatrix();
		

	} while (choice != 'q');



}
