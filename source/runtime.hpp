//
// Created by alex on 31/05/2021.
//

#ifndef ALTV_GO_RUNTIME_HPP
#define ALTV_GO_RUNTIME_HPP

#include <SDK.h>
#include "resource.hpp"
#include "log.hpp"

class GoRuntime : public alt::IScriptRuntime {
public:
	GoRuntime() = default;
	alt::IResource::Impl* CreateImpl(alt::IResource* impl) override;
	void DestroyImpl(alt::IResource::Impl* impl) override;

	static GoRuntime& Instance() {
		Log::Colored << "Created instance of GoRuntime" << Log::Endl;
		static GoRuntime _instance;
		return _instance;
	}
};

#endif //ALTV_GO_RUNTIME_HPP
