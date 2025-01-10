#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
  Intern someRandomIntern;
  {
    AForm *rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    Bureaucrat tuta("Tuta", 1);
    rrf->beSigned(tuta);
    rrf->execute(tuta);
    delete rrf;
  }
  {
    AForm *rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    Bureaucrat tuta("Tuta", 1);
    rrf->beSigned(tuta);
    rrf->execute(tuta);
    delete rrf;
  }
  {
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat tuta("Tuta", 1);
    rrf->beSigned(tuta);
    rrf->execute(tuta);
    delete rrf;
  }
  {
    AForm *rrf;
    rrf = someRandomIntern.makeForm("asdf", "Bender");
    if (!rrf)
      return 1;
    Bureaucrat tuta("Tuta", 1);
    rrf->beSigned(tuta);
    rrf->execute(tuta);
    delete rrf;
  }
  return 0;
}
