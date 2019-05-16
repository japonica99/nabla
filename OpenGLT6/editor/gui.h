#ifndef _NABLA_EDITOR_GUI_H_
#define _NABLA_EDITOR_GUI_H_

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#pragma warning (push)
#pragma warning (disable: 26495)
#pragma warning (disable: 26451)
#include "imgui/imgui.h"
#include "imgui/impl/imgui_impl_glfw.h"
#include "imgui/impl/imgui_impl_opengl3.h"
#pragma warning (pop)

namespace nabla {
void InitGui();
void PrepareGuiFrame();
bool IsUserWorkingOnGui();
void EndGuiFrame();
}

#endif // !_NABLA_EDITOR_GUI_H_
