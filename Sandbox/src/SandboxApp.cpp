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
*  @file SandboxApp.cpp
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Client side application
*/

#include <Ember.h>

/// @brief The ExampleLayer class extends the Ember Layer class
class ExampleLayer : public Ember::Layer {

public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		EM_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ember::Event& event) override {
		EM_TRACE("{0}", event);
	}

};

/// @brief Sandbox class declaration extends the Application class
class Sandbox : public Ember::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {}

};

/// @brief The CreateApplication() function launches Sandbox Application CLIENT side
Ember::Application* Ember::CreateApplication() {
	return new Sandbox();
}