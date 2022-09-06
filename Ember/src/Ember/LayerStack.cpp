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
*  @file LayerStack.cpp
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief LayerStack source file: This file defines layer stack functions.
*/

#include "empch.h"
#include "LayerStack.h"

namespace Ember {

	/// @brief LayerStack constructor and destructor
	LayerStack::LayerStack() {
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : m_Layers)
			delete layer;
	}

	/// @brief The PushLayer() function pushes a layer onto the layer stack (below overlays).
	/// @param layer The layer to be added
	void LayerStack::PushLayer(Layer* layer) {
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	/// @brief The PushOverlay() function pushes an overlay onto the top of the layer stack.
	/// @param overlay The overlay to be added
	void LayerStack::PushOverlay(Layer* overlay) {
		m_Layers.emplace_back(overlay);
	}

	/// @brief The PopLayer() function iterates through the layer stack and removes a layer.
	/// @param layer The layer to be removed
	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	/// @brief The PopOverlay() function iterates through the layer stack and removes an overlay.
	/// @param overlay The overlay to be removed
	void LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);

		if (it != m_Layers.end())
			m_Layers.erase(it);
	}

}