#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

struct interval
{
    int inceput;
    int sfarsit;
    int index;
};

bool comp(const interval a, const interval b)
{
    return b.inceput >= a.inceput;
}

int main()
{
    int n;
    f >> n;
    vector <interval> v;
    vector <interval> a[100];

    for (int i = 0; i < n; i++)
    {
        interval x;
        f >> x.inceput >> x.sfarsit;
        x.index = i+1;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), comp);

    int poz = 0;
    interval i = v[0];
	a[poz].push_back(i);

    for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= poz; ++j)
		{
			if (a[j][a[j].size() - 1].sfarsit <= v[i].inceput)
			{
				a[j].push_back(v[i]);
				j = poz+1;
			}
			else
			{
				poz++;
				a[poz].push_back(v[i]);
				j = poz+1;
			}
		}
	}
	g << poz+1 << endl;

	for (int i = 0; i <= poz; ++i)
		{
		    for (int j = 0; j < a[i].size(); ++j)
			    g << a[i][j].index << " ";
            g << endl;
		}

    f.close();
    g.close();
    return 0;
}

