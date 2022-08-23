/**
*  Copyright 2022 0xChristopher
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
*  @file Core.h
*  @author Original Author Yan Chernikov - Used for learning purposes by
*		0xChristopher
*  @brief All files included in this project contain code from The Cherno's
*		Hazel game engine creation series.
*/

#pragma once

#ifdef EM_PLATFORM_WINDOWS
	#ifdef EM_BUILD_DLL
		#define EMBER_API __declspec(dllexport)
	#else
		#define EMBER_API __declspec(dllimport)
	#endif
#else
	#error Ember only supports Windows!
#endif