#ifndef ENGINE_H
#define ENGINE_H

#include "common.h"

class Node_engine;
class Node_load;
class Node_gui;
class Node_data;
class Node_operation;


class Engine
{
public:
  //Constructor / Destructor
  Engine();
  ~Engine();

public:
  void program(Window_manager* window);
  void init(Window_manager* window);
  void loop();
  void exit();
  void reset();

  inline Node_engine* get_node_engine(){return node_engine;}
  inline Node_load* get_node_load(){return node_load;}
  inline Node_gui* get_node_gui(){return node_gui;}
  inline Node_data* get_node_data(){return node_data;}
  inline Node_operation* get_node_ope(){return node_ope;}

private:
  Node_engine* node_engine;
  Node_load* node_load;
  Node_gui* node_gui;
  Node_data* node_data;
  Node_operation* node_ope;
};

#endif
