/*
 * PluginManager.cpp
 *
 *  Created on: 22 Mar 2018
 *      Author: osboxes
 */
#include <dirent.h>
#include <dlfcn.h>
#include "PluginManager.hpp"

PluginManager::PluginManager(ShapeRegistry& registry)
: registry(registry) {
}

void PluginManager::loadPlugins(const std::string& path) {
	void* handle = dlopen(path.c_str(), RTLD_LAZY);
	if (nullptr == handle) {
		throw std::runtime_error("dlopen failed");
	}

	auto entryPoint = reinterpret_cast<void(*)(ShapeRegistry&)>(dlsym(handle, "registerMakers"));
	if (nullptr == entryPoint) {
		throw std::runtime_error("dlsym failed");
	}

	entryPoint(registry);
}

void PluginManager::unloadPlugins() {
}
