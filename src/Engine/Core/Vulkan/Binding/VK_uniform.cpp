#include "VK_uniform.h"

#include "../VK_engine.h"
#include "../VK_param.h"
#include "../Data/VK_buffer.h"
#include "../Window/VK_error.h"


//Constructor / Destructor
VK_uniform::VK_uniform(VK_engine* vk_engine){
  //---------------------------

  this->vk_param = vk_engine->get_vk_param();
  this->vk_buffer = vk_engine->get_vk_buffer();
  this->vk_error = vk_engine->get_vk_error();

  //---------------------------
}
VK_uniform::~VK_uniform(){}

//Uniform creation
void VK_uniform::create_uniform_buffers(Struct_binding* binding){
  //---------------------------

  vec_descriptor_required& vec_required = binding->vec_required_binding;
  vector<Struct_uniform*>& vec_uniform = binding->vec_uniform;

  for(int i=0; i<vec_required.size(); i++){
    descriptor_required& descriptor = vec_required[i];
    string name = get<0>(descriptor);
    size_t size = get<1>(descriptor);
    int binding = get<2>(descriptor);
    VkDescriptorType type = get<3>(descriptor);

    if(type == TYPE_UNIFORM){
      Struct_uniform* uniform = create_uniform_buffer(name, size, binding);
      vec_uniform.push_back(uniform);
    }
  }

  //---------------------------
}
Struct_uniform* VK_uniform::create_uniform_buffer(string name, size_t size, int binding){
  Struct_uniform* uniform = new Struct_uniform();
  //---------------------------

    uniform->name = name;
    uniform->binding = binding;
    uniform->size = size;

    vk_buffer->create_gpu_buffer(size, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, uniform->buffer);
    vk_buffer->bind_buffer_memory(MEMORY_SHARED_CPU_GPU, uniform->buffer, uniform->mem);
    vkMapMemory(vk_param->device.device, uniform->mem, 0, size, 0, &uniform->mapped);

  //---------------------------
  return uniform;
}
void VK_uniform::clean_uniform(Struct_binding* binding){
  //---------------------------

  for(int i=0; i<binding->vec_uniform.size(); i++){
    Struct_uniform* uniform = binding->vec_uniform[i];
    vkDestroyBuffer(vk_param->device.device, uniform->buffer, nullptr);
    vkFreeMemory(vk_param->device.device, uniform->mem, nullptr);
  }

  //---------------------------
}

//Uniform update
void VK_uniform::update_uniform_mat4(string uniform_name, Struct_binding* binding, glm::mat4& value){
  bool has_been_found = false;
  //---------------------------

  for(int i=0; i<binding->vec_uniform.size(); i++){
    Struct_uniform* uniform = binding->vec_uniform[i];
    if(uniform->name == uniform_name){
      memcpy(uniform->mapped, &value, sizeof(value));
      has_been_found = true;
      break;
    }
  }

  if(has_been_found == false){
    vk_error->uniform_name_not_recognized(binding, uniform_name);
  }

  //---------------------------
}
void VK_uniform::update_uniform_int(string uniform_name, Struct_binding* binding, int value){
  bool has_been_found = false;
  //---------------------------

  for(int i=0; i<binding->vec_uniform.size(); i++){
    Struct_uniform* uniform = binding->vec_uniform[i];
    if(uniform->name == uniform_name){
      memcpy(uniform->mapped, &value, sizeof(value));
      has_been_found = true;
      break;
    }
  }

  if(has_been_found == false){
    vk_error->uniform_name_not_recognized(binding, uniform_name);
  }

  //---------------------------
}
void VK_uniform::update_uniform_edl(string uniform_name, Struct_binding* binding, Struct_edl value){
  bool has_been_found = false;
  //---------------------------

  for(int i=0; i<binding->vec_uniform.size(); i++){
    Struct_uniform* uniform = binding->vec_uniform[i];
    if(uniform->name == uniform_name){
      memcpy(uniform->mapped, &value, sizeof(value));
      has_been_found = true;
      break;
    }
  }

  if(has_been_found == false){
    vk_error->uniform_name_not_recognized(binding, uniform_name);
  }

  //---------------------------
}
