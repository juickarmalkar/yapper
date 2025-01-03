#include "YapperApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
YapperApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

YapperApp::YapperApp(InputParameters parameters) : MooseApp(parameters)
{
  YapperApp::registerAll(_factory, _action_factory, _syntax);
}

YapperApp::~YapperApp() {}

void
YapperApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<YapperApp>(f, af, s);
  Registry::registerObjectsTo(f, {"YapperApp"});
  Registry::registerActionsTo(af, {"YapperApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
YapperApp::registerApps()
{
  registerApp(YapperApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
YapperApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  YapperApp::registerAll(f, af, s);
}
extern "C" void
YapperApp__registerApps()
{
  YapperApp::registerApps();
}
