//
// Created by Jarod on 05/06/2023.
//

#include "SortingHandler.h"
#include <iostream>
void SortingHandler::handle(ProcessingRequest *r) {

   bool isTrash = false;
   std::cout << "Sorting handler " << std::endl;
   if(isTrash){
      //TODO put material in trash
   }else {
      //Call next handler
      AbstractHandler<ProcessingRequest>::handle(r);
   }


}
