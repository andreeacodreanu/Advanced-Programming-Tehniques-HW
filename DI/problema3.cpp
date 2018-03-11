//problema 3 ->O(nlogn)
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int merge_count (vector <int> v, int li, int mid, int ls)
{
    int i, j;
    int nr = 0;

    i = li;
    j = mid;
    while ((i <= mid ) && (j <= ls))
    {
        if (v[i] <= 2*v[j])
            i++;
        else
        {
            j++;
            nr = nr + (mid - i);
        }
    }
    return nr;
}

int count_inv (vector <int> v, int li, int ls)
{
    int mid, i = 0;
    if (ls > li)
    {
        mid = (ls + li)/2;
        int left = count_inv (v, li, mid);
        int right = count_inv (v, mid + 1, ls);
        int split = merge_count (v, li, mid + 1, ls);
        return left + right + split;
    }
    return i;
}

int main()
{
    int n;
    vector <int> v;
    f >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        f >> x;
        v.push_back(x);
    }

    g << count_inv(v, 0, n - 1);

    f.close();
    g.close();

    return 0;
}
