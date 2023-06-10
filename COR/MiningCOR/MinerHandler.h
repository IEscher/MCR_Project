//
// Created by Jarod on 07/06/2023.
//

#ifndef MCR_COR_MINERHANDLER_H
#define MCR_COR_MINERHANDLER_H

#include "../AbstractHandler.h"
#include "../MiningRequest.h"
class MinerHandler : public AbstractHandler<MiningRequest> {
public:
   MinerHandler() = default;
   void handle(MiningRequest *request) override;
};


#endif //MCR_COR_MINERHANDLER_H
