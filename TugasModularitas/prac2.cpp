#include <iostream>

void happy_face();
void sad_face();

int main()
{
    char x;
    while (std::cin >> x)
    {
        if (x == ')')
        {
            happy_face();
        }
        else if (x == '(')
        {
            sad_face();
        }
        else if (x == 'q' or x == 'Q')
        {
            break;
        }
    }
    return 0;
}

void happy_face()
{
    std::cout << ":) :)" << std::endl;
}

void sad_face()
{
    std::cout << ":( :(" << std::endl;
}
