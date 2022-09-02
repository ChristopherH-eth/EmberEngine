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
*  @file MouseEvent.h
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Mouse events
*/

#pragma once

#include "Event.h"

namespace Ember {

	/// @see MouseMovedEvent class extends the Event class
	class EMBER_API MouseMovedEvent : public Event {

	public:
		MouseMovedEvent(float x, float y) 
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		/// ToString() override to display mouse moved
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	/// @see MouseScrolledEvent class extends the Event class
	class EMBER_API MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		/// ToString() override to display mouse scrolled
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

	/// @see MouseButtonEvent class contains the MouseButtonEvent constructor
	class EMBER_API MouseButtonEvent : public Event {
		
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;

	};

	/// @see MouseButtonPressedEvent class extends the MouseButtonEvent class
	class EMBER_API MouseButtonPressedEvent : MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int button) 
			: MouseButtonEvent(button) {}

		/// ToString() override to display mouse button pressed
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	};

	/// @see MouseButtonReleasedEvent class extends the MouseButtonEvent class
	class EMBER_API MouseButtonReleasedEvent : MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		/// ToString() override to display mouse button released
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}