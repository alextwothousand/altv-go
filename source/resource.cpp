//
// Created by alex on 31/05/2021.
//

#include "resource.hpp"

VResource::VResource(VRuntime *runtime, alt::IResource *resource)
: runtime(runtime), resource(resource) {
	main.append(resource->GetPath().CStr());
	main.append((const char*)ZPL_PATH_SEPARATOR);
	main.append(resource->GetMain().CStr());
}

bool VResource::OnInit() {
	// Load our DLL.
	auto mod = zpl_dll_load(main.c_str());
	if (mod == nullptr) {
		Log::Error << "Failed to open main dll" << Log::Endl;
		return false;
	}

	Log::Colored << "Loaded DLL into program" << Log::Endl;

	// Grab a pointer to the OnInit function.
	auto onInit = static_cast<f_OnInit>(zpl_dll_proc_address(mod, "OnInit"));
	if (onInit == nullptr) {
		Log::Error << "Could not determine address to dll entrypoint" << Log::Endl;
		return false;
	}
	// Make the pointer to that function known to our class.
	fn_OnInit = onInit;

	// Grab a pointer to the OnExit function.
	auto onExit = static_cast<f_OnExit>(zpl_dll_proc_address(mod, "OnExit"));
	// Make the pointer to that function known to our class.
	fn_OnExit = onExit;

	Log::Colored << "Determined addresses. Executing..." << Log::Endl;
	// Call our function.
	fn_OnInit();

	return true;
}

bool VResource::OnExit() {
	if (fn_OnExit != nullptr) {
		// We have a valid pointer to our OnExit function. Call it.
		fn_OnExit();
	}

	return true;
}
