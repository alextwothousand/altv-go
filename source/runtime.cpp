//
// Created by alex on 31/05/2021.
//

#include "runtime.hpp"

alt::IResource::Impl *VRuntime::CreateImpl(alt::IResource *impl) {
	auto resource = new VResource(this, impl);
	return resource;
}

void VRuntime::DestroyImpl(alt::IResource::Impl *impl) {
	auto* resource = dynamic_cast<VResource*>(impl);
	delete resource;
}