#ifndef MOOSEFORJLTESTAPP_H
#define MOOSEFORJLTESTAPP_H

#include "MooseApp.h"

class mooseforjlTestApp;

template <>
InputParameters validParams<mooseforjlTestApp>();

class mooseforjlTestApp : public MooseApp
{
public:
  mooseforjlTestApp(InputParameters parameters);
  virtual ~mooseforjlTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEFORJLTESTAPP_H */
