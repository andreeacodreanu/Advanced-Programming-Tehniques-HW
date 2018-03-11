//problema 2 -> O(kn)
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
ifstream f("z.in");
ofstream g("z.out");

int parcurgere(int n, int x, int y)
{
    n = n/2;
    if (n == 0)
        return 1;
    else if (x <= n && y <= n)
        return parcurgere(n, x, y); //1
    else if (x <= n && y > n)
        return pow(n,2) + parcurgere(n, x, y-n); //2
    else if (x > n && y <= n)
        return 2*pow(n,2) + parcurgere(n, x-n, y); //3
    else
        return 3*pow(n,2) + parcurgere(n, x-n, y-n); //4

}

int main()
{
    int n, k;

    f >> n >> k;
    n = (1 << n);

    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        f >> x >> y;
        g << parcurgere(n, x, y) << endl;
    }
	f.close();
	g.close();
    return 0;
}
