#include <iostream>

int sum(int a, int b);

int main()
{
    int x, y;
    std::cout << "x + y ? " << std::endl;
    std::cout << "x : ";
    std::cin >> x;
    std::cout << "y : ";
    std::cin >> y;
    std::cout << "x + y = " << x << " + " << y << " = " << sum(x, y) << std::endl;
    return 0;
}

int sum(int a, int b)
{
    int res;
    res = a + b;
    return res;
}
