//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_MAKETOOLSHANDLER_H
#define MCR_COR_MAKETOOLSHANDLER_H
#include "../Request.h"
#include "../AbstractHandler.h"
#include "../ProcessingRequest.h"
class MakeToolsHandler : public AbstractHandler<ProcessingRequest>{
public:
   MakeToolsHandler() = default;
   void handle(ProcessingRequest *request) override;
};


#endif //MCR_COR_MAKETOOLSHANDLER_H
