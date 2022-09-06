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
*  @file Layer.h
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Layer header file: This file declares the functions to be used by the
*		  layer source file.
*/

#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Ember {

	/// @brief The Layer() class
	class EMBER_API Layer {

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};

}