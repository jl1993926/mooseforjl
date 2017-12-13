#ifndef MOOSEFORJLAPP_H
#define MOOSEFORJLAPP_H

#include "MooseApp.h"

class mooseforjlApp;

template <>
InputParameters validParams<mooseforjlApp>();

class mooseforjlApp : public MooseApp
{
public:
  mooseforjlApp(InputParameters parameters);
  virtual ~mooseforjlApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEFORJLAPP_H */
