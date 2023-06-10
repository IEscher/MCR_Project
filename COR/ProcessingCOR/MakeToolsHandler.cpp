//
// Created by Jarod on 05/06/2023.
//

#include "MakeToolsHandler.h"
#include <iostream>
void MakeToolsHandler::handle(ProcessingRequest *r) {

   //TODO  Check if there is enough material to craft a new tool with it
   //TODO only craft new tools if stock of tools is below a certain level
   // if material is used to craft the tools, don't call next handler
   std::cout << "Transport handler " << std::endl;
   //if(materialIsNotUsed){
   AbstractHandler::handle(r);
   //}
}