//
// Created by alex on 31/05/2021.
//

#ifndef ALTV_GO_RUNTIME_HPP
#define ALTV_GO_RUNTIME_HPP

#include <SDK.h>
#include "resource.hpp"
#include "log.hpp"

class VRuntime : public alt::IScriptRuntime {
public:
	VRuntime() = default;
	alt::IResource::Impl* CreateImpl(alt::IResource* impl) override;
	void DestroyImpl(alt::IResource::Impl* impl) override;

	static VRuntime& Instance() {
		Log::Colored << "Created instance of VRuntime" << Log::Endl;
		static VRuntime _instance;
		return _instance;
	}
};

#endif //ALTV_GO_RUNTIME_HPP
