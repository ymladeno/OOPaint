/*
 * PluginManager.hpp
 *
 *  Created on: 22 Mar 2018
 *      Author: osboxes
 */

#ifndef SRC_PLUGINMANAGER_HPP_
#define SRC_PLUGINMANAGER_HPP_

#include <string>

#include "../inc/ShapeRegistry.hpp"

class PluginManager {
public:
	PluginManager(ShapeRegistry& registry);
	virtual ~PluginManager() = default;

	void loadPlugins(const std::string& s);
    void unloadPlugins();

private:
    ShapeRegistry& registry;
};

#endif /* SRC_PLUGINMANAGER_HPP_ */
