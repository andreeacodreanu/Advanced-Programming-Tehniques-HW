#include<iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");

int min(int a, int b, int c)
{
    return std::min( std::min(a, b), c );
}

void Colt_stanga(int M[20][20], int R, int C, int K)
{
    int i,j;
    int S[R][C];
    int val_max, poz_i, poz_j;

    /** Initializeaza prima coloana din S. */
    for(i = 0; i < R; i++)
        S[i][0] = M[i][0];

    /** Initializeaza prima linie din S. */
    for(j = 0; j < C; j++)
        S[0][j] = M[0][j];

    /** Construieste matricea S. */
    for(i = 1; i < R; i++)
    {
        for(j = 1; j < C; j++)
        {
            if(M[i][j] == 0)
                S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
            else
                S[i][j] = 0;
        }
    }

    /** Cauta in S valoarea maxima, reprezentand coltul din dreapta jos al
    patratului si gaseste coltul din stanga sus. */

    val_max = S[0][0];
    poz_i = 0;
    poz_j = 0;

    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
        {
            if(val_max < S[i][j])
            {
                val_max = S[i][j];
                poz_i = i;
                poz_j = j;
            }
        }

   /*cout << endl;
    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        cout << S[i][j] << " ";
        cout << endl;
    }*/

    /*cout << "*" << S[poz_i - 1][poz_j] << endl;
    cout << S[poz_i][poz_j - 1] << endl;
    cout << S[poz_i - 1][poz_j - 1] << "*" << endl;
    cout << poz_i << " " << poz_j;*/

    if (S[poz_i - 1][poz_j] == val_max || S[poz_i][poz_j - 1] == val_max || S[poz_i - 1][poz_j - 1] == val_max)
    {
        val_max++;
        poz_i--;
        poz_j--;
    }

    cout << val_max << endl;
    cout << poz_i - val_max + 2 << " " << poz_j - val_max + 2 << endl;

    /** Cautam toate patratele. */
    int nr = 0;
    nr = (val_max - 1) * (val_max - 1) + 1;
    //cout << nr;
    for(i = R - 1; i >= 0; i--)
    {
        for(j = C - 1; j >= 0; j--)
        {
            if (S[i][j] == S[i-1][i] - 1 && S[i][j] == S[i][j-1] - 1)
                nr++;
        }
    }
    cout << nr;
}

int main()
{
    int n, m, k;
    f >> n >> m;
    int M[20][20];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            f >> M[i][j];
    f >> k;

    Colt_stanga(M, n, m, k);

    f.close();
    return 0;
}
