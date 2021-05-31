//
// Created by alex on 31/05/2021.
//

#ifndef ALTV_GO_RESOURCE_HPP
#define ALTV_GO_RESOURCE_HPP

#include <SDK.h>
#include <zpl.h>

#include "log.hpp"
#include "runtime.hpp"

#include <string>
#include <functional>

typedef std::function<void()> f_OnInit;
typedef std::function<void()> f_OnExit;

class VRuntime;
class VResource : public alt::IResource::Impl {
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
