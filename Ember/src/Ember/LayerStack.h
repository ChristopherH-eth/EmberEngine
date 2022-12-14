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
*  @file LayerStack.h
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief LayerStack header file: This file declares the functions to be used by the
*		  layer stack source file.
*/

#pragma once

#include <vector>
#include "Core.h"
#include "Layer.h"

namespace Ember {

	class EMBER_API LayerStack {

	public:
		/// @brief LayerStack constructor and destructor
		LayerStack();
		~LayerStack();

		/// LayerStack functions and iterator
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;

	};

}