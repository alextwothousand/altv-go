//
// Created by alex on 31/05/2021.
//

#include "resource.hpp"

GoResource::GoResource(GoRuntime *runtime, alt::IResource *resource)
: runtime(runtime), resource(resource) {
	main.append(resource->GetPath().CStr());
	main.append((const char*)ZPL_PATH_SEPARATOR);
	main.append(resource->GetMain().CStr());
}

bool GoResource::Start() {
	// Load our DLL.
	auto mod = zpl_dll_load(main.c_str());
	if (mod == nullptr) {
		Log::Error << "Failed to open main dll" << Log::Endl;
		return false;
	}

	Log::Colored << "Loaded DLL into program" << Log::Endl;

	// Grab a pointer to the OnInit function.
	auto onInit = static_cast<f_onInit>(zpl_dll_proc_address(mod, "onInit"));
	if (onInit == nullptr) {
		Log::Error << "Could not determine address to dll entrypoint" << Log::Endl;
		return false;
	}
	// Make the pointer to that function known to our class.
	fn_onInit = onInit;

	// Grab a pointer to the OnExit function.
	auto onExit = static_cast<f_onExit>(zpl_dll_proc_address(mod, "onExit"));
	// Make the pointer to that function known to our class.
	fn_onExit = onExit;

	Log::Colored << "Determined addresses. Executing..." << Log::Endl;
	// Call our function.
	fn_onInit();

	return true;
}

bool GoResource::Stop() {
	if (fn_onExit != nullptr) {
		// We have a valid pointer to our OnExit function. Call it.
		fn_onExit();
	}

	return true;
}

bool GoResource::OnEvent(const alt::CEvent* ev) {
	// Proper event handling will be explained in another article
	return true;
}
