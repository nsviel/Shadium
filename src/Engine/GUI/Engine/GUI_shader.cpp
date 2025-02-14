#include "GUI_shader.h"

#include "../Node_gui.h"

#include "../../Core/Node_engine.h"
#include "../../Core/Dimension/Dimension.h"
#include "../../Core/Shader/Shader.h"
#include "../../Core/Shader/Source/EDL/Shader_edl.h"


//Constructor / Destructor
GUI_shader::GUI_shader(Node_gui* node_gui){
  //---------------------------

  Node_engine* node_engine = node_gui->get_node_engine();
  Shader* shaderManager = node_engine->get_shaderManager();
  this->dimManager = node_engine->get_dimManager();
  this->shader_edl = shaderManager->get_shader_edl();

  this->item_width = 100;

  //---------------------------
}
GUI_shader::~GUI_shader(){}

//Main function
void GUI_shader::design_panel(){
  //---------------------------

  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
  ImGui::SetNextWindowSizeConstraints(ImVec2(100, 100), ImVec2(500, 500));
  ImGui::Begin("Shader");
  this->design_shader();
  ImGui::End();
  ImGui::PopStyleVar();

  //---------------------------
}
void GUI_shader::design_shader(){
  Struct_edl* edl_param = shader_edl->get_edl_param();
  ImGui::BeginChild("window_EDL", ImVec2(0, 100), false, ImGuiWindowFlags_NavFlattened);
  //---------------------------

  ImGui::TextColored(ImVec4(0.7f,0.7f,0.7f,1.0f),"EDL");

  ImGui::SetNextItemWidth(item_width);
  if(ImGui::Checkbox("Activated", &edl_param->activated)){
    shader_edl->update_shader();
  }

  ImGui::SetNextItemWidth(item_width);
  if(ImGui::SliderFloat("Radius", &edl_param->radius, 1.0f, 5.0f)){
    shader_edl->update_shader();
  }

  ImGui::SetNextItemWidth(item_width);
  if(ImGui::SliderFloat("Strength", &edl_param->strength, 1.0f, 100.0f)){
    shader_edl->update_shader();
  }

  //---------------------------
  ImGui::EndChild();
  ImGui::Separator();
}
