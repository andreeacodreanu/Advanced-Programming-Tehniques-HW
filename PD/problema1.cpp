///problema 2
#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int Traseu(int mat[20][20], int n, int m)
{
	/** Prima coloana ramane neschimbata.
	Incepem de la primul element de pe a 2-a coloana.
	In fiecare celula a matricei facem suma dintre valoarea initiala si maximul
	dintre cei trei(doi, in cazul primei sau ultimei linii) vecini ai sai
	de pe coloana anterioara. */
	int res;
	for (int j = 1; j < m; j++)
    {
		res = -1;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && i < n - 1)
                mat[i][j] += max(mat[i - 1][j - 1], max(mat[i][j - 1], mat[i + 1][j - 1]));

			else if (i > 0) ///ultima linie
				mat[i][j] += max(mat[i][j - 1], mat[i - 1][j - 1]);

			else if (i < n - 1) ///prima linie
				mat[i][j] += max(mat[i][j - 1], mat[i + 1][j - 1]);

			res = max(mat[i][j], res);
		}
	}
	return res;
}

int main()
{
	int n, m, mat[20][20];
	f >> n >> m;

	for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            f >> mat[i][j];

	g << Traseu(mat, n, m);

	f.close();
	g.close();
	return 0;
}
