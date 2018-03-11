//problema 4 -> O(nlogn)
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

#define INFINIT 4e18

ifstream f("cmap.in");
ofstream g("cmap.out");

vector < pair <long long, long long> > aux, Ox, Oy;

pair<long long, long long> p1, p2;

long long Distanta(const pair <long long, long long>& a, const pair <long long, long long>& b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long long divide(int li, int ls)
{
    if (ls - li <=  1)
        return INFINIT;
    else
    if (ls - li == 2)
    {
        if (Oy[li] > Oy[li + 1])
            swap(Oy[li], Oy[li + 1]);
        p1.first = Oy[li].first;
        p1.second = Oy[li].second;
        p2.first = Oy[li + 1].first;
        p2.second = Oy[li + 1].second;
        return Distanta(Ox[li], Ox[li + 1]);
    }

    int mid = (li + ls) / 2;
    long long distanta = min(divide(li, mid), divide(mid, ls));

    merge(Oy.begin() + li, Oy.begin() + mid, Oy.begin() + mid, Oy.begin() + ls, aux.begin());
    copy(aux.begin(), aux.begin() + (ls - li), Oy.begin() + li);

    int poz = 0;
    for (int i = li; i < ls;  i++ )
        if (abs(Oy[i].second - Ox[mid].first) <= distanta)
            {
                aux[poz] = Oy[i];
                poz++;
            }

    for (int i = 0; i < poz - 1;  i++)
        for (int j = i + 1; j < poz && j - i < 8;  j++)
        {
            long long d = Distanta(aux[i], aux[j]);
            if (d < distanta)
            {
                distanta = d;
                p1.first = aux[i].first;
                p1.second = aux[i].second;
                p2.first = aux[j].first;
                p2.second = aux[j].second;
            }
        }

    return distanta;
}

int main()
{
    int n;
    f >> n;

    Ox.resize(n);
    Oy.resize(n);
    aux.resize(n);
    for (int i = 0; i < (int)Ox.size(); i++)
        f >> Ox[i].first >> Ox[i].second;

    sort(Ox.begin(), Ox.end());

    for (int i = 0; i < (int)Ox.size(); i++)
        Oy[i] = make_pair(Ox[i].second, Ox[i].first);

    g << "Distanta minima este: " << fixed << setprecision(6) << sqrt(divide(0,Ox.size())) << endl;
    g << "Punctele care dau dintanta minima sunt: " << "(" << p1.first << "," << p1.second << ")" << " " << "(" << p2.first << "," << p2.second << ")";

    f.close();
    g.close();
    return 0;
}
