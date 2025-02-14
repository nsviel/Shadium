#include "VK_frame.h"
#include "VK_swapchain.h"

#include "../VK_engine.h"
#include "../VK_param.h"
#include "../Command/VK_command.h"
#include "../Command/VK_synchronization.h"
#include "../Presentation/VK_framebuffer.h"
#include "../Image/VK_depth.h"
#include "../Image/VK_color.h"
#include "../Image/VK_image.h"
#include "../Device/VK_physical_device.h"


//Constructor / Destructor
VK_frame::VK_frame(VK_engine* vk_engine){
  //---------------------------

  this->vk_engine = vk_engine;
  this->vk_param = vk_engine->get_vk_param();
  this->vk_physical_device = vk_engine->get_vk_physical_device();
  this->vk_image = vk_engine->get_vk_image();
  this->vk_synchronization = vk_engine->get_vk_synchronization();
  this->vk_color = vk_engine->get_vk_color();
  this->vk_swapchain = vk_engine->get_vk_swapchain();
  this->vk_framebuffer = vk_engine->get_vk_framebuffer();
  this->vk_depth = vk_engine->get_vk_depth();

  //---------------------------
}
VK_frame::~VK_frame(){}

//Renderpass frame
void VK_frame::create_frame_renderpass(Struct_renderpass* renderpass){
  //---------------------------

  for(int i=0; i<vk_param->swapchain.vec_swapchain_image.size(); i++){
    Frame* frame = new Frame();

    frame->ID = i;
    frame->color.image_usage = renderpass->color_image_usage;
    frame->color.sampler_layout = renderpass->color_sampler_layout;
    frame->depth.image_usage = renderpass->depth_image_usage;
    frame->depth.sampler_layout = renderpass->depth_sampler_layout;

    vk_color->create_color_attachment(frame);
    vk_depth->create_depth_attachment(frame);
    vk_framebuffer->create_framebuffer(renderpass, frame);

    renderpass->vec_frame.push_back(frame);
  }

  //---------------------------
}
void VK_frame::clean_frame_renderpass(Struct_renderpass* renderpass){
  vector<Frame*>& vec_frame = renderpass->vec_frame;
  //---------------------------

  //Vec images
  for(int i=0; i<vec_frame.size(); i++){
    Frame* frame = vec_frame[i];
    vk_image->clean_image(&frame->color);
    vk_image->clean_image(&frame->depth);
    vk_framebuffer->clean_framebuffer(frame);
    delete frame;
  }
  vec_frame.clear();

  //---------------------------
}

//Swapchain frame
void VK_frame::create_frame_swapchain(Struct_swapchain* swapchain){
  //---------------------------

  for(int i=0; i<swapchain->vec_swapchain_image.size(); i++){
    Frame* frame = new Frame();

    frame->ID = i;
    frame->color.image = swapchain->vec_swapchain_image[i];
    frame->color.format = vk_color->find_color_format();
    frame->color.aspect = VK_IMAGE_ASPECT_COLOR_BIT;
    frame->depth.image_usage = IMAGE_USAGE_DEPTH;

    vk_image->create_image_view(&frame->color);
    vk_depth->create_depth_attachment(frame);
    vk_framebuffer->create_framebuffer(&vk_param->renderpass_ui, frame);
    vk_synchronization->init_frame_sync(frame);

    swapchain->vec_frame.push_back(frame);
  }

  //---------------------------
}
void VK_frame::clean_frame_swapchain(Struct_swapchain* swapchain){
  vector<Frame*>& vec_frame = swapchain->vec_frame;
  //---------------------------

  //Vec images
  for(int i=0; i<vec_frame.size(); i++){
    Frame* frame = vec_frame[i];
    vkDestroyImageView(vk_param->device.device, frame->color.view, nullptr);
    vk_image->clean_image(&frame->depth);
    vk_framebuffer->clean_framebuffer(frame);
    vk_synchronization->clean_frame_sync(frame);
    delete frame;
  }
  vec_frame.clear();

  //---------------------------
}
