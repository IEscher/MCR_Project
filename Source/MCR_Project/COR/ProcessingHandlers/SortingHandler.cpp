// Fill out your copyright notice in the Description page of Project Settings.


#include "SortingHandler.h"

void USortingHandler::handle(UProcessingRequest *r) {

	bool isTrash = false;
	if(isTrash){
		//TODO put material in trash
	}else {
		//Call next handler
		Super::handle(r);
	}


}
