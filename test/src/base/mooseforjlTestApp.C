#include "mooseforjlTestApp.h"
#include "mooseforjlApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<mooseforjlTestApp>()
{
  InputParameters params = validParams<mooseforjlApp>();
  return params;
}

mooseforjlTestApp::mooseforjlTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  mooseforjlApp::registerObjectDepends(_factory);
  mooseforjlApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  mooseforjlApp::associateSyntaxDepends(_syntax, _action_factory);
  mooseforjlApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    mooseforjlTestApp::registerObjects(_factory);
    mooseforjlTestApp::associateSyntax(_syntax, _action_factory);
  }
}

mooseforjlTestApp::~mooseforjlTestApp() {}

void
mooseforjlTestApp::registerApps()
{
  registerApp(mooseforjlApp);
  registerApp(mooseforjlTestApp);
}

void
mooseforjlTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
mooseforjlTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
mooseforjlTestApp__registerApps()
{
  mooseforjlTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
mooseforjlTestApp__registerObjects(Factory & factory)
{
  mooseforjlTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
mooseforjlTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  mooseforjlTestApp::associateSyntax(syntax, action_factory);
}
