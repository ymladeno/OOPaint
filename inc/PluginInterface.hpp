/*
 * PluginInterface.hpp
 *
 *  Created on: 22 Mar 2018
 *      Author: osboxes
 */

#ifndef SRC_PLUGININTERFACE_HPP_
#define SRC_PLUGININTERFACE_HPP_

#include "ShapeRegistry.hpp"

class PluginInterface {
public:
	virtual ~PluginInterface() = default;
	virtual void registerMakers(ShapeRegistry& reg) = 0;
};

#endif /* SRC_PLUGININTERFACE_HPP_ */
