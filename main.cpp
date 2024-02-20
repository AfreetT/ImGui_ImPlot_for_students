#include "context_setup.h"

int main(int, char**)
{
  
    ImGuiContext_OGL context;
    context.setup_and_show();

    float slider_value = 0.0f;

    while (!glfwWindowShouldClose(context.window))
    {
        context.new_frame();

        ImGui::Begin("First window");
        ImGui::Text("Hello, ImGui\nSlider from below has value: %f \nOr if we round to three places: %.3f",
                                                                         slider_value, slider_value);
        ImGui::SliderFloat("Slider name from the right", &slider_value, -1.0f, 1.0f);
        ImGui::End();

        context.render_frame();
    }

    return 0;
}