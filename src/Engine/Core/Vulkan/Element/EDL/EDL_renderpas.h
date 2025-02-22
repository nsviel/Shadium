#ifndef VK_EDL_RENDERPASS_H
#define VK_EDL_RENDERPASS_H

#include "../../Struct/struct_renderpass.h"
#include "../../Struct/struct_pipeline.h"
#include "../../../Shader/Shader.h"
#include "../../../../common.h"

class VK_engine;
class VK_param;
class VK_pipeline;
class VK_subpass;
class VK_viewport;


class EDL_renderpas
{
public:
  //Constructor / Destructor
  EDL_renderpas(VK_engine* vk_engine);
  ~EDL_renderpas();

public:
  //Main functions
  void init_renderpass(Struct_renderpass* renderpass);

  //Pipeline
  void create_pipeline_edl(Struct_renderpass* renderpass);

private:
  VK_engine* vk_engine;
  VK_param* vk_param;
  VK_pipeline* vk_pipeline;
  VK_subpass* vk_subpass;
  VK_viewport* vk_viewport;
};

#endif
