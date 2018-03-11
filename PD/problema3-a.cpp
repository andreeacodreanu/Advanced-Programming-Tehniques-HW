///problema 4
#include<iostream>
#include <fstream>
#include <mem.h>
#include <string>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int Count(string str)
{
    int n = str.length();
    int pd[n][n];
    memset(pd, 0, sizeof(pd));

    bool P[n][n];
    memset(P, false, sizeof(P));

    for (int i = 0; i < n; i++)
        P[i][i] = true;

    /** Marchez in matricea P secventele in care se repeta aceeasi litera
    si in matricea pd lungimea subsecventei palindrom. */
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            P[i][i + 1] = true;
            pd[i][i + 1] = 1 ;
        }
    }

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = gap + i;

            if (str[i] == str[j] && P[i + 1][j - 1])
                P[i][j] = true;

            if (P[i][j] == true) ///actualizez matricea pd
                pd[i][j] = pd[i][j - 1] + pd[i + 1][j] + 1 - pd[i + 1][j - 1];
            else
                pd[i][j] = pd[i][j - 1] + pd[i + 1][j] - pd[i + 1][j - 1];
        }
    }

    return pd[0][n - 1];
}

int main()
{
    string str;
    f >> str;
    g << Count(str);

    f.close();
    g.close();
    return 0;
}
