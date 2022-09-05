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
*  @brief Engine side application translation unit
*/

#include "empch.h"
#include "Application.h"
#include "Ember/Events/ApplicationEvent.h"
#include "Ember/Log.h"
#include <GLFW/glfw3.h>

namespace Ember {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}