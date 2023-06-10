//
// Created by Jarod on 05/06/2023.
//

#include "MeltingHandler.h"
#include <iostream>
void MeltingHandler::handle(ProcessingRequest *r) {

   //TODO If material can be melted, melt it

   std::cout << "Melting handler " << std::endl;
   //Call next handler
   AbstractHandler<ProcessingRequest>::handle(r);
}