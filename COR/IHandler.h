//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_IHANDLER_H
#define MCR_COR_IHANDLER_H

#include <string>
#include "Request.h"
#include <memory>
/**
 * The IHandler interface declares a method for building the chain of handlers.
 * It also declares a method for executing a request.
 * /!\ Type of return value of Handle() and the type of the parameter might change
 */
template <typename T>
class IHandler {
public:
   virtual IHandler<T> *setNext(IHandler<T>* handler) = 0;
   virtual void handle(T *request) = 0;
   virtual ~IHandler()= default;
};



#endif //MCR_COR_IHANDLER_H
