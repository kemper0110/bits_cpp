#include <iostream>

template <class T>
T input() {
    T t;
    std::cin >> t;
    return t;
}

int main()
{
    /*Написать программу, которая будет считывать с клавиатуры 4 десятичных числа x, y, m, n. 
    В числе x младшие m бит  заменить на старшие m бит из числа y, потом инвертировать n младших бит в числе y. 
    Все смещения бит указываются начиная с младшего (нулевого) бита. Программа должна выводить исходные данные в десятичном виде,
    а  полученные значения x, y вывести в двоичном виде в табличной форме, 
    напротив двоичного числа выведите имя соответствующей переменной.*/

    uint16_t x = input<int>(); // 28
    uint16_t y = input<int>(); // 32
    uint16_t m = input<int>(); // 2
    uint16_t n = input<int>(); // 3

    uint16_t ys = y;
    uint16_t c(0);
    for(c; ys > 0; c++)
        ys >>= 1;
    uint16_t xo = ((x >> m) << m) | (y >> (c - m));
    uint16_t yo = ~(((65535 >> n) << n) | y - ((y >> n) << n)) | ((y >> n) << n);

    std::cout << x << std::endl;
    std::cout << "changed x::" << xo << std::endl;
    std::cout << y << std::endl;
    std::cout << "changed y::" << yo << std::endl;
}
