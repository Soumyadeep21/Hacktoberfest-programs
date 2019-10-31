#include <iostream>

using namespace std;

int main()
{
    int x, y, z = 0;
    cout << "Enter two numbers : ";
    cin >> x >> y;
    if(x > y) swap(x,y);
    for(int i = x; i > 0; i--)
    {
        if(x % i == 0 && y % i == 0)
        {
            z = i;
            break;
        }
    }
    if (z == 0) cout << "Impossible";
    else cout << "The GCD is : " << z;
	return 0;
}
