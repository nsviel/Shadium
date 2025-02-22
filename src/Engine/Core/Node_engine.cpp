#include "Node_engine.h"

#include "Vulkan/VK_engine.h"
#include "Dimension/Dimension.h"
#include "Camera/Camera.h"
#include "Param_engine.h"
#include "GPU/GPU_data.h"
#include "Shader/Shader.h"

#include "../Engine.h"


//Constructor / Destructor
Node_engine::Node_engine(Engine* engine){
  //---------------------------

  this->engine = engine;
  this->param_engine = new Param_engine();
  this->dimManager = new Dimension();
  this->cameraManager = new Camera(this);
  this->shaderManager = new Shader(this);
  this->vk_engine = new VK_engine(this);
  this->gpu_data = new GPU_data(this);

  //---------------------------
}
Node_engine::~Node_engine(){
  //---------------------------

  delete param_engine;
  delete dimManager;
  delete cameraManager;
  delete vk_engine;
  delete gpu_data;
  delete shaderManager;

  //---------------------------
}

//Main function
void Node_engine::init(Window_manager* window){
  //---------------------------

  vk_engine->init_vulkan(window);
  dimManager->update();

  //---------------------------
}
void Node_engine::loop_start(){
  //---------------------------

  vk_engine->main_loop();

  //---------------------------
}
void Node_engine::loop(){
  //---------------------------

  cameraManager->input_cam_mouse();
  engine->loop();

  //---------------------------
}
void Node_engine::exit(){
  //---------------------------

  vk_engine->clean_vulkan();

  //---------------------------
}
void Node_engine::reset(){
  //---------------------------

  cameraManager->reset_camera();

  //---------------------------
}
