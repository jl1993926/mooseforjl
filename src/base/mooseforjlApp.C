#include "mooseforjlApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<mooseforjlApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

mooseforjlApp::mooseforjlApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  mooseforjlApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  mooseforjlApp::associateSyntax(_syntax, _action_factory);
}

mooseforjlApp::~mooseforjlApp() {}

void
mooseforjlApp::registerApps()
{
  registerApp(mooseforjlApp);
}

void
mooseforjlApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
mooseforjlApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
mooseforjlApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
mooseforjlApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
mooseforjlApp__registerApps()
{
  mooseforjlApp::registerApps();
}

extern "C" void
mooseforjlApp__registerObjects(Factory & factory)
{
  mooseforjlApp::registerObjects(factory);
}

extern "C" void
mooseforjlApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  mooseforjlApp::associateSyntax(syntax, action_factory);
}
