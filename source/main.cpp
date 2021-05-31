//
// Created by alex on 31/05/2021.
//

#include "main.hpp"

EXPORT bool altMain(alt::ICore* core) {
	alt::ICore::SetInstance(core);
	auto& runtime = VRuntime::Instance();

	core->RegisterScriptRuntime("v", &runtime);
	Log::Colored << "Loaded V module, version ~y~" GO_MODULE_VERSION << Log::Endl;

	return true;
}

EXPORT uint32_t GetSDKVersion()
{
	return alt::ICore::SDK_VERSION;
}