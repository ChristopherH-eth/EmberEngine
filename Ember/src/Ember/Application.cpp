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

#include "Application.h"
#include "Ember/Events/ApplicationEvent.h"
#include "Ember/Log.h"

namespace Ember {

	Application::Application() {}
	Application::~Application() {}

	void Application::Run() {
		/// Test event
		WindowResizeEvent e(1280, 720);
		EM_TRACE(e);

		while (true);
	}

}