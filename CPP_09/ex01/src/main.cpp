#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error : Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        rpn.processExpressionRPN(std::string(av[1]));
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;       
    }
    return 0;
}
