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
*  @file Application.cpp
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Application source: This file defines the functions to be handled by the
*		  application.
*/

#include "empch.h"
#include "Application.h"
#include "Ember/Log.h"
#include <GLFW/glfw3.h>

namespace Ember {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	/// @brief Application constructor and destructor
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
	}

	/// @brief The OnEvent() function defines what is called when an event is received.
	/// @param e The event to be dispatched and handled
	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		/// Iterate through the layer stack to handle an event. Break once the event is handled.
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			(*--it)->OnEvent(e);

			if (e.Handled)
				break;
		}
	}

	/// @brief The Run() function keeps the application running until it receives a window
	/// close event. It updates the window and the layers.
	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	/** 
	 * @brief The OnWindowClose() function tells the window what to do when a window close
	 * event is received.
	 * @param e The event to be handled
	 */
	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		
		return true;
	}

}