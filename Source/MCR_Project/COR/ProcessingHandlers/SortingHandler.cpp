// Fill out your copyright notice in the Description page of Project Settings.


#include "SortingHandler.h"

void USortingHandler::Handle(UProcessingRequest *Request) {

	bool isTrash = false;
	if(isTrash){
		//TODO put material in trash
	}else {
		//Call next handler
		Super::Handle(Request);
	}


}
