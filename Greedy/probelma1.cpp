#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream f("date.in");

struct mutare
{
    int val;
    char dir;
};

void joc(int a, int n, vector<int> v, vector<mutare> &p1, vector<mutare> &p2,
          int &s1, int &s2)
{
    int x = 0, y = n-1;
    while (x < y)
    {
        if (x%2 == a)
        {
            s1 = s1+v[x];
            mutare A;
            A.val = v[x];
            A.dir = 'S';
            p1.push_back(A);
            x++;
        }
        else if (y%2 == a)
        {
            s1 = s1+v[y];
            mutare A;
            A.val = v[y];
            A.dir = 'D';
            p1.push_back(A);
            y--;
        }
        char a;
        cout << "mutarea: ";
        cin >> a;
        if (a == 'S')
        {
            s2 = s2+v[x];
            mutare A;
            A.val = v[x];
            A.dir = 'S';
            p2.push_back(A);
            x++;
        }
        else if (a == 'D')
        {
            s2 = s2+v[y];
            mutare A;
            A.val = v[y];
            A.dir = 'D';
            p2.push_back(A);
            y--;
        }
        else
        {
            cout << "Mutare incorecta" << endl;
            return;
        }
    }
}

int main()
{
    int sp = 0, si = 0, n, s1 = 0, s2 = 0;
    vector<mutare> p1, p2;
    vector<int> v;
    f >> n;

    cout << "Tabla de joc: ";

    for (int i = 0; i < n; i++)
    {
        int x;
        f >> x;
        v.push_back(x);
        cout << v[i] << " ";
        if (i%2 == 0)
            sp = sp+v[i];
        else
            si = si+v[i];
    }
    cout << endl << "S -> primul numar" << endl << "D -> ultimul numar";
    cout << endl;

    if (sp >= si)
        joc(0, n, v, p1, p2, s1, s2);
    else if (sp < si)
        joc(1, n, v, p1, p2, s1, s2);

    cout << "Suma obtinuta de primul jucator: " << s1 << endl;
    cout << "Suma obtinuta de al doilea jucator: " << s2 << endl << endl;
    cout << "Secventa de mutari a primului jucator: ";
    for (int i = 0; i < p1.size(); i++)
        cout << p1[i].dir << " ";
    cout << endl;
    cout << "Secventa de mutari a celui de-al doilea jucator: ";
    for (int i = 0; i < p2.size(); i++)
        cout << p2[i].dir << " ";
    cout << "\n\n*******JOCUL S-A TERMINAT*******\n";

    f.close();
    return 0;
}
