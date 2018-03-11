///problema 5
#include<fstream>
#include<iostream>
#define NMax 2005

using namespace std;

ifstream f("joculet.in");
ofstream g("joculet.out");

int n;
long long joc[NMax];
long long aux[3][NMax];

/**Muta toate elementele de pe a 2-a linie pe prima si cele de pe a 3-a pe a 2-a.*/
void Move()
{
    for(int i = 1; i <= n; i++)
    {
        aux[0][i] = aux[1][i];
        aux[1][i] = aux[2][i];
    }
}

/**Calculam toate diferentele posibile si le retinem in matricea aux.
La final solutia se va gasi pe ultima linie si prima coloana a matricei*/
int Solve()
{
    for(int step = 1 ; step < n; step++)
    {
        for(int i = 1 ; i <= n - step; i++)
        {
            int j = i + step;
            aux[2][i] = max( max(joc[i] - aux[1][i+1], joc[j] - aux[1][i]), joc[i] + joc[j] - aux[0][i+1] );
        }
        /*for (int k = 0; k < 3; k++)
            for (int j = 1; j <= n; j++)
            cout << aux[k][j] << "  ";
        cout << endl;*/
        Move();
    }
    return aux[2][1];
}

int main()
{
    f >> n;

    for(int i = 1 ; i <= n; ++i)
    {
        f >> joc[i];
        aux[1][i] = joc[i];
    }
    g << Solve();

    f.close();
    g.close();
    return 0;
}
