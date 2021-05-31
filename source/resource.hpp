//
// Created by alex on 31/05/2021.
//

#ifndef ALTV_GO_RESOURCE_HPP
#define ALTV_GO_RESOURCE_HPP

#include <SDK.h>
#include <zpl.h>
#include <string>

#include "log.hpp"
#include "runtime.hpp"

//typedef void (*f_OnInit)();
//typedef void (*f_OnExit)();

class VRuntime;
class VResource : public alt::IResource::Impl {
	using f_OnInit = void (*)();
	using f_OnExit = void(*)();

	VRuntime* runtime;
	alt::IResource* resource;

	std::string main;

	f_OnInit fn_OnInit;
	f_OnExit fn_OnExit;

public:
	VResource(VRuntime* runtime, alt::IResource* resource);
	~VResource() override = default;

	bool OnInit();
	bool OnExit();
};

#endif //ALTV_GO_RESOURCE_HPP
