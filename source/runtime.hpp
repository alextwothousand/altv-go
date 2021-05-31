//
// Created by alex on 31/05/2021.
//

#ifndef ALTV_GO_RUNTIME_HPP
#define ALTV_GO_RUNTIME_HPP

#include "resource.hpp"
#include <SDK.h>

class VRuntime : public alt::IScriptRuntime {
public:
	VRuntime() = default;
	alt::IResource::Impl* CreateImpl(alt::IResource* impl) override;
	void DestroyImpl(alt::IResource::Impl* impl) override;

	static VRuntime& Instance() {
		static VRuntime _instance;
		return _instance;
	}
};

#endif //ALTV_GO_RUNTIME_HPP
