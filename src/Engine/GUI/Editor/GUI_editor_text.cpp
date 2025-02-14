#include "GUI_editor_text.h"
#include "../Node_gui.h"


//Constructor / Destructor
GUI_editor_text::GUI_editor_text(Node_gui* node_gui){
  //---------------------------

  this->editor = new TextEditor();
  this->load_file("/home/aeter/Desktop/Dev/Nephos/CMakeLists.txt");

  //---------------------------
}
GUI_editor_text::~GUI_editor_text(){}

//Main function
void GUI_editor_text::design_panel(){
  //---------------------------

  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
  ImGui::SetNextWindowSizeConstraints(ImVec2(100, 100), ImVec2(500, 500));
  ImGui::Begin("Text editor");
  editor->Render("Editor");
  ImGui::End();
  ImGui::PopStyleVar();

  //---------------------------
}

//Subfunction
void GUI_editor_text::load_file(string path){
  //---------------------------

  //Open file
  ifstream file;
  file.open(path.c_str());

  //Get first line
  string line;
  std::getline(file, line);
  string buffer = line;

  //Get following lines
  while(std::getline(file, line)){
    buffer = buffer + "\n" + line;
  }

  editor->SetText(buffer);


  //---------------------------
}
