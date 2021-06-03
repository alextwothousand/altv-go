//
// Created by alex on 31/05/2021.
//

#include "main.hpp"

EXPORT bool altMain(alt::ICore* core) {
	Log::Colored << "altMain proc called." << Log::Endl;

	alt::ICore::SetInstance(core);
	auto& runtime = GoRuntime::Instance();

	core->RegisterScriptRuntime("go", &runtime);
	Log::Colored << "Loaded Go module, version ~y~" GO_MODULE_VERSION << Log::Endl;

	return true;
}

EXPORT uint32_t GetSDKVersion() {
	return alt::ICore::SDK_VERSION;
}