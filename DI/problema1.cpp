//problema 1
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int divide(vector <int> &v, int li, int ls)
{
    if (li == ls - 1)
        return v[li];
    else
    {
        if (v[li] < v[li+1])
            divide(v, ++li, ls);
        else if (v[ls] > v[ls-1])
            divide(v, li, --ls);
    }
}

int main()
{
    int n;
    f >> n;
    vector <int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        f >> x;
        v.push_back(x);
    }
    g << divide(v, 0, n-1);
    f.close();
    g.close();
    return 0;
}
