/**
*  Copyright 2022 The Cherno - Hazel Game Engine
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*  @file Layer.cpp
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Layer source file: This file defines layer functions.
*/

#include "empch.h"
#include "Layer.h"

namespace Ember {

	/// @brief The Layer constructor and destructor
	/// @param debugName The name of a given layer
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName) {
	}

	Layer::~Layer() {}

}