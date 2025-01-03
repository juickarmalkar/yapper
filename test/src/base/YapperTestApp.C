//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "YapperTestApp.h"
#include "YapperApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
YapperTestApp::validParams()
{
  InputParameters params = YapperApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

YapperTestApp::YapperTestApp(InputParameters parameters) : MooseApp(parameters)
{
  YapperTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

YapperTestApp::~YapperTestApp() {}

void
YapperTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  YapperApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"YapperTestApp"});
    Registry::registerActionsTo(af, {"YapperTestApp"});
  }
}

void
YapperTestApp::registerApps()
{
  registerApp(YapperApp);
  registerApp(YapperTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
YapperTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  YapperTestApp::registerAll(f, af, s);
}
extern "C" void
YapperTestApp__registerApps()
{
  YapperTestApp::registerApps();
}
