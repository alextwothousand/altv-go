//
// Created by alex on 31/05/2021.
//

#include "runtime.hpp"

alt::IResource::Impl *GoRuntime::CreateImpl(alt::IResource *impl) {
	auto resource = new GoResource(this, impl);
	return resource;
}

void GoRuntime::DestroyImpl(alt::IResource::Impl *impl) {
	auto* resource = dynamic_cast<GoResource*>(impl);
	delete resource;
}