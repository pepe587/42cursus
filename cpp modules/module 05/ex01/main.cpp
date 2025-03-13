#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
    Form        Contract("Contract", 60, 50);
    Bureaucrat  Tess("Tess", 10);
    Bureaucrat  Ash("Ash", 60);
    Bureaucrat  Dony("Dony", 120);

    std::cout << std::endl << "-------------------------------" << std::endl;

    Tess.signForm(Contract);
    Ash.signForm(Contract);
    Dony.signForm(Contract);

    Contract.beSigned(Tess);
    Contract.beSigned(Ash);
    Contract.beSigned(Dony);

    Tess.signForm(Contract);
    Contract.beSigned(Tess);

    Ash.signForm(Contract);
    Contract.beSigned(Ash);

    Dony.signForm(Contract);
    Contract.beSigned(Dony);
    std::cout << "-------------------------------" << std::endl;

    std::cout << Tess << std::endl << std::endl;
    return 0;
}