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
*  @file Application.h
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Application header file: This file declares the functions to be used by the
*		  application source file.
*/

#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Ember/Events/ApplicationEvent.h"
#include "Window.h"

namespace Ember {

	/// @brief The Application class
	class EMBER_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	/// To be defined in CLIENT
	Application* CreateApplication();

}