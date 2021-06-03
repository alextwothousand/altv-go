//
// Created by alex on 31/05/2021.
//

#ifndef ALTV_GO_RESOURCE_HPP
#define ALTV_GO_RESOURCE_HPP

#include <SDK.h>
#include <string>

#include "log.hpp"
#include "runtime.hpp"

//#include <zpl.h>
#include <Windows.h>

#ifndef ZPL_DEF
#define ZPL_DEF

#define zpl_dll_load(x) (void*)LoadLibraryA(x)
#define zpl_dll_proc_address(x,y) (void*)GetProcAddress((HMODULE)x,y)
#define ZPL_PATH_SEPARATOR "\\"

#endif

//typedef void (*f_OnInit)();
//typedef void (*f_OnExit)();

class GoRuntime;
class GoResource : public alt::IResource::Impl {
	using f_onInit = void (*)();
	using f_onExit = void(*)();

	GoRuntime* runtime;
	alt::IResource* resource;

	std::string main;

	f_onInit fn_onInit = nullptr;
	f_onExit fn_onExit = nullptr;

public:
	GoResource(GoRuntime* runtime, alt::IResource* resource);
	~GoResource() override = default;

	bool Start();
	bool Stop();

	bool OnEvent(const alt::CEvent* ev);
};

#endif //ALTV_GO_RESOURCE_HPP
