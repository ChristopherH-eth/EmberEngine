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
*  @file KeyEvent.h
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Key Events header file: This file handles input events via the keyboard.
*/

#pragma once

#include "Event.h"

namespace Ember {

	/// @brief KeyEvent class contains the KeyEvent constructor
	class EMBER_API KeyEvent : public Event {

		public:
			inline int GetKeyCode() const { return m_KeyCode; }

			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		protected:
			KeyEvent(int keycode)
				: m_KeyCode(keycode) {}

			int m_KeyCode;

	};

	/// @brief KeyPressedEvent class extends the KeyEvent class
	class EMBER_API KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		/// ToString() override to display key pressed and number of times repeated
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;

	};

	/// @brief KeyReleasedEvent class extends KeyEvent class
	class EMBER_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		/// ToString() override to display key released
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}