#ifndef COMMON_H
#define COMMON_H

//Include
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <stdexcept>
#include <optional>
#include <cstdlib>
#include <stdint.h>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <sys/file.h>
#include <chrono>
#include <array>
#include <vulkan/vulkan.h>
#include <thread>
#include <typeindex>
#include <any>
#include <utility>
#include <functional>

//Namespaces
using namespace std;
using namespace glm;

//Function
#include "Specific/Function/fct_terminal.h"
#include "Specific/Function/fct_math.h"
#include "Specific/Function/fct_chrono.h" //For debuging
#include "Specific/Function/fct_timer.h"  //For time profilling

//Data
#include "Data/Struct/struct_object.h"
#include "Data/Struct/struct_cloud.h"
#include "Data/Struct/struct_set.h"
#include "Data/Struct/struct_data_file.h"
#include "Data/Struct/struct_glyph.h"
#include "Data/Struct/struct_mesh.h"

#include <Window/Window_manager.h>

//GUI
#include <imgui/core/imgui.h>
#include <imgui/core/imgui_impl_glfw.h>
#include <imgui/core/imgui_internal.h>
#include <imgui/vulkan/imgui_impl_vulkan.h>


#endif
