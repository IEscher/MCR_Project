//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_SORTINGHANDLER_H
#define MCR_COR_SORTINGHANDLER_H

#include "../Request.h"
#include "../AbstractHandler.h"
#include "../ProcessingRequest.h"
class SortingHandler : public AbstractHandler<ProcessingRequest> {
public:
   SortingHandler() = default;
   void handle(ProcessingRequest *request) override;
};


#endif //MCR_COR_SORTINGHANDLER_H
