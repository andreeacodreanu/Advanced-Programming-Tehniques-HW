#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

void citire(vector <int> l[100], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x, y;
        f >> x >> y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
}

void cauta_frunza(vector <int> l[100], int n, set <int>& v, set <int>& s)
{
    for (int i = 1; i <= n; i++)
    {
        if (l[i].size() == 1)
        {
            s.insert(i);
            v.erase(i);
            v.erase(l[i][0]);
        }
    }
}

int main()
{
    int n;
    vector <int> l[100];
    f >> n;
    citire(l, n);

    set <int> v, s;
    set <int>::iterator it;

    for (int i = 1; i <= n; ++i)
        v.insert(i);

    while(v.size() > 1)
        cauta_frunza(l, n, v, s);

    if (v.size() == 1)
    {
        it = v.begin();
        s.insert(*it);
        v.clear();
    }

    g << s.size() << endl;
    for (it = s.begin(); it != s.end(); ++it)
        g << *it << " ";

    f.close();
    g.close();
    return 0;
}
