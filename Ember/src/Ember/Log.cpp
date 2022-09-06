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
*  @file Log.cpp
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief Log source: This file defines the logs behaviors for client side and application
*		  side logging.
*/

#include "empch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ember {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	/// @brief The Init() function initializes CLIENT and CORE loggers, as well as format
	/// logger messages.
	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		s_CoreLogger = spdlog::stdout_color_mt("EMBER");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}