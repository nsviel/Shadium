#ifndef NODE_SCENE_H
#define NODE_SCENE_H

#include "../common.h"

class Node_engine;
class Node_load;

class Engine;
class Scene;
class Param_data;
class Database;
class Glyphs;
class Control;


class Node_data
{
public:
  //Constructor / Destructor
  Node_data(Engine* engine);
  ~Node_data();

public:
  void init();
  void reset();

  inline Engine* get_engine(){return engine;}
  inline Node_engine* get_node_engine(){return node_engine;}
  inline Node_load* get_node_load(){return node_load;}

  inline Param_data* get_param_data(){return param_data;}
  inline Scene* get_sceneManager(){return sceneManager;}
  inline Database* get_dataManager(){return dataManager;}
  inline Control* get_controlManager(){return controlManager;}

private:
  Engine* engine;
  Node_engine* node_engine;
  Node_load* node_load;

  Param_data* param_data;
  Scene* sceneManager;
  Database* dataManager;
  Glyphs* glyphManager;
  Control* controlManager;
};

#endif
