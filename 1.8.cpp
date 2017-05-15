#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

void rot4(int& v0, int& v1, int& v2, int& v3) {
	int tmp = v3;
	v3 = v2;
	v2 = v1;
	v1 = v0;
	v0 = tmp;
}

void zero_row_col(int** m, const int nRows, const int nCols) {
	bool zeroRows[nRows] = {0};
	bool zeroCols[nCols] = {0};
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (m[row][col] == 0) {
				zeroRows[row] = true;
				zeroCols[col] = true;
			}
		}
	}
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (zeroRows[row] || zeroCols[col]) {
				m[row][col] = 0;
			}
		}
	}
}

int main(int argc, char** argv) {
	int** mat = new int*[4]{
		new int[4]{ 0,  1,  2,  3  },
		new int[4]{ 4,  5,  6,  7  },
		new int[4]{ 8,  9,  10, 11 },
		new int[4]{ 12, 13, 14, 15 }
	};

	zero_row_col(mat, 4, 4);
	printf("%i\t%i\t%i\t%i\n", mat[0][0], mat[0][1], mat[0][2], mat[0][3]);
	printf("%i\t%i\t%i\t%i\n", mat[1][0], mat[1][1], mat[1][2], mat[1][3]);
	printf("%i\t%i\t%i\t%i\n", mat[2][0], mat[2][1], mat[2][2], mat[2][3]);
	printf("%i\t%i\t%i\t%i\n", mat[3][0], mat[3][1], mat[3][2], mat[3][3]);
}
